/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Subsystems/Claw.h"

#include "RobotMap.h"

Claw::Claw() : frc::Subsystem("Claw") {
  claw_motor = RobotMap:: claw_motor;
}

void Claw::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Command

void Claw::ClawOpen(){
  claw_motor->Set(.5);
}

void Claw::ClawClose(){
  claw_motor->Set(-.5);
}