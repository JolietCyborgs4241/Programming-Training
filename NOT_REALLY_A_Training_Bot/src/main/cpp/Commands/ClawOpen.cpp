/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Commands/ClawOpen.h"

#include "Robot.h"

ClawOpen::ClawOpen() {
  // Use Requires() here to declare subsystem dependencies
  
}

// Called just before this Command runs the first time
void ClawOpen::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void ClawOpen::Execute() {
  Robot::claw->ClawClose();
}

// Make this return true when this Command no longer needs to run execute()
bool ClawOpen::IsFinished() { return false; }

// Called once after isFinished returns true
void ClawOpen::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ClawOpen::Interrupted() {}
