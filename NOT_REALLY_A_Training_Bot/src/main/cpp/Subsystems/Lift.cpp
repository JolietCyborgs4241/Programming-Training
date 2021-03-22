/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Subsystems/Lift.h"
#include "RobotMap.h"
Lift::Lift() : Subsystem("ExampleSubsystem") {
  Lift_Motor = RobotMap::Lift_motor;
  }
  //Arm moves up at 100%
void Lift::LiftUp() {
  Lift_Motor->Set(1); 
}
//Arm moves down 100%
void Lift::LiftDown() {
  Lift_Motor->Set(-1);
}
void Lift::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
