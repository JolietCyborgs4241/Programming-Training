/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Commands/ClawClose.h"

#include "Robot.h"

ClawClose::ClawClose() {
  // Use Requires() here to declare subsystem dependencies
  
}

// Called just before this Command runs the first time
void ClawClose::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void ClawClose::Execute() {
  Robot::claw->ClawClose();
}

// Make this return true when this Command no longer needs to run execute()
bool ClawClose::IsFinished() { return false; }

// Called once after isFinished returns true
void ClawClose::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ClawClose::Interrupted() {}
