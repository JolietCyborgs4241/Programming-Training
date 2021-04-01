// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include <frc/shuffleboard/Shuffleboard.h>
#include <frc2/command/button/JoystickButton.h>
#include <frc/XboxController.h>

#include "RobotContainer.h"

#include <frc/controller/PIDController.h>
#include <frc/controller/RamseteController.h>
#include <frc/shuffleboard/Shuffleboard.h>
#include <frc/trajectory/Trajectory.h>
#include <frc/trajectory/TrajectoryGenerator.h>
#include <frc/trajectory/TrajectoryUtil.h>
#include <frc/trajectory/constraint/DifferentialDriveVoltageConstraint.h>
#include <frc2/command/Command.h>
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

#include "commands/AutoSequences.h"





RobotContainer::RobotContainer() {
  // Configure the button bindings
  ConfigureButtonBindings();

  SetupInvokableCommands();
}

void RobotContainer::ConfigureButtonBindings() {
  // Also set default commands here
  m_drive.SetDefaultCommand(TeleopArcadeDrive(
      &m_drive, [this] { return -m_controller.GetRawAxis(1); },
      [this] { return m_controller.GetRawAxis(2); }));

  // Example of how to use the onboard IO
  m_onboardButtonA.WhenPressed(frc2::PrintCommand("Button A Pressed"))
      .WhenReleased(frc2::PrintCommand("Button A Released"));

std::cout << "SETUP CHOOSER";

  m_chooser.SetDefaultOption("HEY", "HEY");

  #ifdef NEVER
  // Setup SmartDashboard options.
  //
  // we return the same string as was selected
  for (auto i = 1 ; ! (AutoSequences[i].seqName.empty()) ; i++) {
    m_chooser.AddOption(AutoSequences[i].seqName, AutoSequences[i].seqName);
  }
  frc::SmartDashboard::PutData("Auto Path Selector", &m_chooser);
  #endif
}


void RobotContainer::SetupInvokableCommands() {

  m_commands("STOP",       &InvokableCmdStop);
  m_commands("RESET_ODO",  &InvokableCmdResetOdo);
  m_commands("RED_ON",     &InvokableCmdRedLedOn);
  m_commands("RED_OFF",    &InvokableCmdRedLedOff);
  m_commands("YELLOW_ON",  &InvokableCmdYellowLedOn);
  m_commands("YELLOW_OFF", &InvokableCmdYellowLedOff);
  m_commands("GREEN_ON",   &InvokableCmdGreenLedOn);
  m_commands("GREEN_OFF",  &InvokableCmdGreenLedOff);

  vector<string> cmdNames = m_commands.getCommandNames();

  for ( auto i = 0 ; i < (int)cmdNames.size() ; i++ ) {
    std::cout << "CmdName[" << i << "] \"" << cmdNames[i] << "\"" << std::endl;
  }
}


frc2::Command* RobotContainer::GetAutonomousCommand() {

      return InitializeAutoSequence(m_chooser.GetSelected(), &m_drive, &m_commands);
}
