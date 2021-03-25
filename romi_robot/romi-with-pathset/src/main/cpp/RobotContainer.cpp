// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"

#include <frc/controller/PIDController.h>
#include <frc/controller/RamseteController.h>
#include <frc/shuffleboard/Shuffleboard.h>
#include <frc/trajectory/Trajectory.h>
#include <frc/trajectory/TrajectoryGenerator.h>
#include <frc/trajectory/TrajectoryUtil.h>
#include <frc/trajectory/constraint/DifferentialDriveVoltageConstraint.h>
#include <frc2/command/InstantCommand.h>
#include <frc2/command/RamseteCommand.h>
#include <frc2/command/SequentialCommandGroup.h>

#include <frc/smartdashboard/SmartDashboard.h>
#include <frc2/command/PrintCommand.h>
#include <frc2/command/button/Button.h>

#include <frc/Filesystem.h>
#include <wpi/Path.h>
#include <wpi/SmallString.h>

#include "commands/TeleopArcadeDrive.h"

#include "commands/Autonomous.h"
#include "commands/AutoSequences.h"



AUTO_SEQ  AutoSequences[] = { { "mini-slalom", AUTO_ACTION_TRAJECTORY, nullptr },
                              { "down-n-back", AUTO_ACTION_TRAJECTORY, nullptr },
                              { "", AUTO_ACTION_NULL, nullptr }
                            };



RobotContainer::RobotContainer() {
  // Configure the button bindings
  ConfigureButtonBindings();
}

void RobotContainer::ConfigureButtonBindings() {
  // Also set default commands here
  m_drive.SetDefaultCommand(TeleopArcadeDrive(
      &m_drive, [this] { return -m_controller.GetRawAxis(1); },
      [this] { return m_controller.GetRawAxis(2); }));

  // Example of how to use the onboard IO
  m_onboardButtonA.WhenPressed(frc2::PrintCommand("Button A Pressed"))
      .WhenReleased(frc2::PrintCommand("Button A Released"));

  // Setup SmartDashboard options.
  m_chooser.SetDefaultOption("Auto Routine Distance", &m_autoDistance);
  m_chooser.AddOption("Auto Routine Time", &m_autoTime);
  frc::SmartDashboard::PutData("Auto Selector", &m_chooser);
}

frc2::Command* RobotContainer::GetAutonomousCommand() {

    // Create a voltage constraint to ensure we don't accelerate too fast
  frc::DifferentialDriveVoltageConstraint autoVoltageConstraint(
      frc::SimpleMotorFeedforward<units::meters>(
          DriveConstants::kS, DriveConstants::kV, DriveConstants::kA),
      DriveConstants::kDriveKinematics, 7_V);

  // Set up config for trajectory
  frc::TrajectoryConfig config(AutoConstants::kMaxSpeed,
                               AutoConstants::kMaxAcceleration);

  // Add kinematics to ensure max speed is actually obeyed
  config.SetKinematics(DriveConstants::kDriveKinematics);

  // Apply the voltage constraint
  config.AddConstraint(autoVoltageConstraint);

  wpi::SmallString<64>    deployDir;
  frc::filesystem::GetDeployDirectory(deployDir);

  auto exampleTrajectory = frc::TrajectoryUtil::FromPathweaverJson(deployDir + "/mini-slalom.wpilib.json");

#ifdef NEVER
  // An example trajectory to follow.  All units in feet.
  auto exampleTrajectory = frc::TrajectoryGenerator::GenerateTrajectory(
      // Start at the origin facing the +X direction
      frc::Pose2d(0_m, 0_m, frc::Rotation2d(0_deg)),
      // Pass through these two interior waypoints, making an 's' curve path
      {frc::Translation2d(2_ft, 0.75_ft), frc::Translation2d(4_ft, -0.75_ft)},
      // End 3 feet straight ahead of where we started, facing forward
      frc::Pose2d(6_ft, 0_m, frc::Rotation2d(0_deg)),
      // Pass the config
      config);

// --------------------------------------------------------------------------

  // An example trajectory to follow.  All units in feet.
  auto exampleTrajectory = frc::TrajectoryGenerator::GenerateTrajectory(
  
      frc::Pose2d(0_ft, 0_ft, frc::Rotation2d(0_deg)),
      // Pass through these waypoints
      {frc::Translation2d(1_ft, 0.5_ft),
       frc::Translation2d(2_ft, 1.0_ft),
       frc::Translation2d(3_ft, 0_ft),
       frc::Translation2d(4_ft, -1.0_ft),
       frc::Translation2d(5_ft, 0_ft),
       frc::Translation2d(6_ft, 1.0_ft),
       frc::Translation2d(7_ft, 0.0_ft),
       frc::Translation2d(6_ft, -1.0_ft),
       frc::Translation2d(5_ft, 0.0_ft),
       frc::Translation2d(4_ft, 1.0_ft),
       frc::Translation2d(3_ft, 0.0_ft),
       frc::Translation2d(2_ft, -1.0_ft),
       frc::Translation2d(1_ft, -0.5_ft)},
      // End here facing in the same direction we started
      frc::Pose2d(0_ft, 0_ft, frc::Rotation2d(0_deg)),
      config);
#endif

  frc2::RamseteCommand ramseteCommand(
      exampleTrajectory, [this]() { return m_drive.GetPose(); },
      frc::RamseteController(AutoConstants::kRamseteB,
                             AutoConstants::kRamseteZeta),
      frc::SimpleMotorFeedforward<units::meters>(
          DriveConstants::kS, DriveConstants::kV, DriveConstants::kA),
      DriveConstants::kDriveKinematics,
      [this] { return m_drive.GetWheelSpeeds(); },
      frc2::PIDController(DriveConstants::kPDriveVel,
                          DriveConstants::kIDriveVel,
                          DriveConstants::kDDriveVel),
      frc2::PIDController(DriveConstants::kPDriveVel,
                          DriveConstants::kIDriveVel,
                          DriveConstants::kDDriveVel),
      [this](auto left, auto right) { m_drive.TankDriveVolts(left, right); },
      {&m_drive});

  // Reset odometry to the starting pose of the trajectory.
  m_drive.ResetOdometry(exampleTrajectory.InitialPose());

  // no auto
  return new frc2::SequentialCommandGroup(
      std::move(ramseteCommand),
      frc2::InstantCommand([this] { m_drive.TankDriveVolts(0_V, 0_V); }, {}));

  // return m_chooser.GetSelected();
}
