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

#include <dirent.h>
#include <sys/stat.h>

#include "commands/TeleopArcadeDrive.h"

#include "commands/AutoSequences.h"





RobotContainer::RobotContainer() {

  SetupInvokableCommands();

  ConfigureButtonBindings();

  SetupAutoChooser();
}


void RobotContainer::SetupInvokableCommands() {

  m_invokableCommands = new InvokableCommands(&m_drive, &m_redLED, &m_yellowLED, &m_greenLED);

  for ( auto i = 0 ; m_invokableCommands->getCommandName(i) != "" ; i++ ) {
    std::cout << "CmdName[" << i << "] \"" << m_invokableCommands->getCommandName(i) << "\"" << std::endl;
  }
}


void RobotContainer::ConfigureButtonBindings() {
  // Also set default commands here
  m_drive.SetDefaultCommand(TeleopArcadeDrive(
      &m_drive, [this] { return -m_controller.GetRawAxis(1); },
      [this] { return m_controller.GetRawAxis(3); }));

#ifdef NEVER
  // Example of how to use the onboard IO
  m_onboardButtonA.WhenPressed(m_invokableCommands.getCommand("RED_ON"))
      .WhenReleased(m_invokableCommands.getCommand("RED_OFF"));

  m_onboardButtonB.WhenPressed(m_invokableCommands.getCommand("YELLOW_ON"))
      .WhenReleased(m_invokableCommands.getCommand("YELLOW_OFF"));

  m_onboardButtonC.WhenPressed(m_invokableCommands.getCommand("GREEN_ON"))
      .WhenReleased(m_invokableCommands.getCommand("GREEN_OFF"));
#endif

  //m_onboardButtonA.WhenPressed(frc2::InstantCommand([this] { m_onboardIO.SetYellowLed(true); }, {} ))
  //    .WhenReleased(frc2::InstantCommand([this] { m_onboardIO.SetYellowLed(false); }, {}));
}


void RobotContainer::SetupAutoChooser() {

  frc::SmartDashboard::PutData("Auto Selector", &m_chooser);

  wpi::SmallString<64>    deployDir;
  string                  pathsDir;

  // build the path to the PathWeaver files
  frc::filesystem::GetDeployDirectory(deployDir);
  pathsDir = deployDir.str();
  pathsDir += "/paths/";

  // open the dir and start processing the group names
  if (auto dir = opendir(pathsDir.c_str())) {

    while (auto dirEntry = readdir(dir)) {

      struct stat info;
      bool        firstIsDefault = true;

        // get the information about this file system entry
        if (stat(pathsDir.c_str(), &info) != 0) {
            std::cerr << "SetupAutoChooser(): stat() error on \"" << pathsDir
                  << "/" << dirEntry->d_name << "\": error: " <<
                  strerror(errno) << std::endl;

            return;
        }

        // check to see if it's a directory since all we care about are dirs since they
        // are where the PathWeaver projects will be stored
        //
        // be sure to skip "." and ".."!

        if (S_ISDIR(info.st_mode) && strcmp(dirEntry->d_name, ".") != 0 && strcmp(dirEntry->d_name, "..") != 0) {

          std::cout << "SetupAutoChooser(): dirEntry->d_name: \"" << dirEntry->d_name << "\"" << std::endl;

          //if (firstIsDefault) {
          //  m_chooser.SetDefaultOption(dirEntry->d_name, dirEntry->d_name);
          //  std::cout << "SetupAutoChooser(): DEFAULT: \"" << dirEntry->d_name << "\"" << std::endl;
          //}

          m_chooser.AddOption(dirEntry->d_name, dirEntry->d_name);
        }
      }

      closedir(dir);

      m_chooser.SetDefaultOption("path-with-events", "path-with-events");

  } else {

        std::cerr << "SetupAutoChooser(): opendir() error on \"" << pathsDir 
            << "\": error: " << strerror(errno) << std::endl;
  }
}


frc2::Command* RobotContainer::GetAutonomousCommand() {

      return InitializeAutoSequence(m_chooser.GetSelected(), &m_drive, m_invokableCommands);
}
