/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "OI.h"

#include <WPILib.h>

#include "Commands/ClawOpen.h"

#include "Commands/ClawClose.h"


OI::OI() {
  // Process operator interface input here.
XboxController = new Joystick(0);
A= new JoystickButton(XboxController,1);
B= new JoystickButton(XboxController,2);
A->WhileHeld (new ClawOpen);
B->WhileHeld (new ClawClose);

}
