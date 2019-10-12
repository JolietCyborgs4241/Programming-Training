/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Subsystems\Claw.h"
#include "OI.h"
#include "RobotMap.h"

Claw::Claw() : frc::Subsystem("Claw") {
  claw_motor = RobotMap::claw;
}

void Claw::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Command

// Function below opens claw at 50% power
void Claw::ClawOpen(){
  claw_motor->Set(.5);
}
//Function below closes claw at 50% power
void Claw::ClawClose(){
  claw_motor->Set(-.5);
}