#include <frc/kinematics/DifferentialDriveKinematics.h>
#include <frc/trajectory/constraint/DifferentialDriveKinematicsConstraint.h>
#include <frc/trajectory/Trajectory.h>
#include <frc/trajectory/TrajectoryGenerator.h>
#include <frc/trajectory/constraint/DifferentialDriveVoltageConstraint.h>
#include <frc2/command/Command.h>
#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include <frc2/command/SequentialCommandGroup.h>
#include <frc2/command/InstantCommand.h>
#include <frc2/command/RamseteCommand.h>
#include <frc/Filesystem.h>
#include <wpi/Path.h>
#include <wpi/SmallString.h>
#include <string>

#include "commands/Autonomous.h"
#include "commands/AutoSequences.h"
#include "Constants.h"
#include "commands/PathGroup.h"
#include "commands/PathSet.h"


// setup our initial command - start from a stopped robot

AutoSeqStopCmd::AutoSeqStopCmd(Drivetrain* drivetrain) : m_drivetrain(drivetrain) {
  AddRequirements({drivetrain});
}

void AutoSeqStopCmd::Initialize() {
  m_drivetrain->ArcadeDrive(0, 0);
}

void AutoSeqStopCmd::Execute() {}

void AutoSeqStopCmd::End(bool interrupted) {}

bool AutoSeqStopCmd::IsFinished() { 
  return true; 
}






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

frc2::Command *InitializeAutoSequence(string sequence, Drivetrain *driveTrain) {

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


    static AutoSeqStopCmd AutoStopCmd(driveTrain);
    static class frc2::SequentialCommandGroup AutoSeqCmd;

    // start off the command we'll return - we'll add to it as we go along
    AutoSeqCmd.AddCommands(AutoStopCmd);

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

        bool        status;

        // get each path segment for this group
        auto trajectory = thisPath.getGroupSegTrajectory(0, pathIndex, status);

        if ( ! status) {
            break;      // got trajectory processing error; don't process any more from this group
        }

        // this is where we would differentiate between trajectories and internal commands we want to invoke

        frc2::RamseteCommand ramseteCommand(trajectory,

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
        // each trajectory command is followed by a stop
        AutoSeqCmd.AddCommands(std::move(ramseteCommand), AutoStopCmd);                             
    }

    return &AutoSeqCmd;
}