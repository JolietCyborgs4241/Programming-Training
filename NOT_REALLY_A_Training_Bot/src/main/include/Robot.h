/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <Commands/Command.h>
#include <SmartDashboard/SendableChooser.h>
#include <TimedRobot.h>
#include "OI.h"
#include "Subsystems/Claw.h"

#include "Subsystems/Lift.h"
#include "RobotMap.h"
class Robot : public frc::TimedRobot {
 public:
  static Claw* claw;
  static OI m_oi;
  static Lift* lift;

  void RobotInit() override;
  void RobotPeriodic() override;
  void DisabledInit() override;
  void DisabledPeriodic() override;
  void AutonomousInit() override;
  void AutonomousPeriodic() override;
  void TeleopInit() override;
  void TeleopPeriodic() override;
  void TestPeriodic() override;

 private:
  // Have it null by default so that if testing teleop it
  // doesn't have undefined behavior and potentially crash.
  //frc::Command* m_autonomousCommand = nullptr;
  //ExampleCommand m_defaultAuto;
  //myauto m_myAuto;
  //frc::SendableChooser<frc::Command*> m_chooser; 
};
