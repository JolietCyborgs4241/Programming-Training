#include <frc/kinematics/DifferentialDriveKinematics.h>
#include <frc/trajectory/constraint/DifferentialDriveKinematicsConstraint.h>
#include <frc/trajectory/Trajectory.h>
#include <frc/trajectory/TrajectoryGenerator.h>
#include <frc/trajectory/constraint/DifferentialDriveVoltageConstraint.h>
#include <frc/Filesystem.h>

#include <frc2/command/Command.h>
#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include <frc2/command/SequentialCommandGroup.h>
#include <frc2/command/InstantCommand.h>
#include <frc2/command/RamseteCommand.h>

#include <wpi/Path.h>
#include <wpi/SmallString.h>

#include <string>

#include "Constants.h"
#include "commands/AutoSequences.h"
#include "commands/PathGroup.h"
#include "commands/PathSet.h"
#include "subsystems/OnBoardIO.h"




// For each name sequence, get the trajectories for each path segment
//
// For now, we only deal with the first path group but we will expand it to handle more
//
// The challenge is to work out how to setup the various options so we can present them
// to the user for selection on the dash board.  Right now, we use the pre-defined sequence name
// to specify a path directory to find the "Groups", "Paths", and "output" directory.  In the future,
// we'll need to build the sequences off of a base set of directories but incorporate the Group
// name into the sequence name for displaying on the dashboard for selection.  Either that or
// we could put all path sequences into the same PathWeaver project directory and differentiate
// solely on the group name - this is probably more realistic given we won't have multiple
// "games" to select from

frc2::Command *InitializeAutoSequence(string sequence, Drivetrain *driveTrain, InvokableCommands *cmds) {

    // first setup the trajectory-following constraints
    // Create a voltage constraint to ensure we don't accelerate too fast
    frc::DifferentialDriveVoltageConstraint autoVoltageConstraint(
      frc::SimpleMotorFeedforward<units::meters>(DriveConstants::kS, DriveConstants::kV, DriveConstants::kA),
      DriveConstants::kDriveKinematics, 7_V);

    // Set up config for trajectory
    frc::TrajectoryConfig config(AutoConstants::kMaxSpeed, AutoConstants::kMaxAcceleration);

    // Add kinematics to ensure max speed is actually obeyed
    config.SetKinematics(DriveConstants::kDriveKinematics);

    // Apply the voltage constraint
    config.AddConstraint(autoVoltageConstraint);


    static class frc2::SequentialCommandGroup AutoSeqCmd;

    // start off the command we'll return - we'll add to it as we go along
    //AutoSeqCmd.AddCommands(*(cmds->getCommand("STOP")));


    wpi::SmallString<64>    deployDir;
    string                  pathsDir;

    // build the path to the PathWeaver files
    frc::filesystem::GetDeployDirectory(deployDir);
    pathsDir = deployDir.str();
    pathsDir += "/paths/";


    // - get the groups (we just support one right now, the first group found so for consistency,
    //   we should just have one group per game)
    //
    // - build the trajectories for each segment
    //
    // - build the ramsette controller for each segment

    PathSet thisPath(pathsDir + sequence);

    // we only look at the first path group and ignore any others - whichever one is "first"
    //
    // that's why we don't run getGroupPathsAvailable() through all the number of groups
    // and only run it using the 0 index
    //
    // this restricts us to only processing the "first" group we found
    //
    // the "first" group is whatever the first entry return by the directory reading routines
    // when we open the "Groups" directory, we don't know which group that might end up being
    //
    // since the "first" group isn't definitive if there are multiple groups in the Groups/
    // directory, we make this a definitive group by just having a single group in each directory
    // which means there is only a single file in the Groups/ directory
    //
    // that way we end up knowing for sure what file we're going to get - no matter what
    // the name is

    // go through all the paths in the first (and only) group
    for (auto pathIndex = 0; pathIndex < thisPath.getGroupPathsAvailable(0); pathIndex++) {

        bool      status;
        string    pathSegment = thisPath.getGroupPath(0, pathIndex);;

std::cout << "pathSegment: \"" << pathSegment << "\"" << std::endl;

        // check is this is a known command - if not, we'll assume it's a path and generate
        // a ramsete command to handle it as a trajectory
        //
        // if it's a command, we'll skip over that and just add it to the sequential
        // command group we are building

        frc2::Command *cmdPointer;

        if ((cmdPointer = cmds->getCommand(pathSegment)) != nullptr) {

std::cout << "\"" << pathSegment << "\" is a command - adding to sequential command group" << std:: endl;

          //AutoSeqCmd.AddCommands( (*cmdPointer) );

        } else {

          // it's an actual path segment to get the JSON, create a trajectory, and create the ramsete command

std::cout << "\"" << pathSegment << "\" is not a command" << std::endl;

          auto trajectory = thisPath.getGroupSegTrajectory(0, pathIndex, status);

          if ( ! status) {
              break;      // got trajectory processing error; don't process any more from this group
          }

          // this is where we would differentiate between trajectories and internal commands we want to invoke

          // IMPORTANT:  We normalise the path to be robot-relative as we pass it to the ramsete command!

          frc2::RamseteCommand ramseteCommand(
                                  trajectory.RelativeTo(trajectory.InitialPose()),

                                  [driveTrain]() { return driveTrain->GetPose(); },

                                  frc::RamseteController(AutoConstants::kRamseteB, AutoConstants::kRamseteZeta),

                                  frc::SimpleMotorFeedforward<units::meters>(DriveConstants::kS,
                                                                             DriveConstants::kV,
                                                                             DriveConstants::kA),

                                  DriveConstants::kDriveKinematics,

                                  [driveTrain] { return driveTrain->GetWheelSpeeds(); },

                                  frc2::PIDController(DriveConstants::kPDriveVel, 0, 0),

                                  frc2::PIDController(DriveConstants::kPDriveVel, 0, 0),

                                  [driveTrain](auto left, auto right) { driveTrain->TankDriveVolts(left, right); },

                                  {driveTrain});

          // add to the sequential command group for this entire sequence
          //
          // each trajectory command is preceded by an odometry reset (since we did a RelativeTo() above)

          AutoSeqCmd.AddCommands(frc2::InstantCommand([driveTrain] { driveTrain->ResetOdometry(frc::Pose2d(0_m, 0_m, 0_deg)); }, {} ),
                                 std::move(ramseteCommand)
                                );
        }                   
    }

    // end the sequence with a full stop - use our "STOP" command for consistency

    //AutoSeqCmd.AddCommands(frc2::InstantCommand([driveTrain] { driveTrain->ArcadeDrive(0, 0); }, {} ) );
    //AutoSeqCmd.AddCommands(*(cmds->getCommand("STOP")));

    return &AutoSeqCmd;
}