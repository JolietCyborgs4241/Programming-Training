// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/TurnDegrees.h"
#include <frc/controller/PIDController.h>

#include <units/math.h>
#include <wpi/math>


double  kTurnP  = 0.50;
double  kTurnI  = 0.10;
double  kTurnD  = 0.00;
double  kTurnFf = 0.20;

double  kTurnTolerance     = 2.0;
double  kTurnRateTolerance = 1.0;

TurnDegrees::TurnDegrees(double speed, units::degree_t angle, Drivetrain* drive)
    : CommandHelper(
          frc2::PIDController(kTurnP, kTurnI, kTurnD),
          // Close loop on heading
          [drive] { return drive->GetGyroAngleZ(); },
          // Set reference to target
          angle.to<double>(),
          // Pipe output to turn robot
          [drive](double output) { drive->ArcadeDrive(-(output + kTurnFf), output + kTurnFf); },
          // Require the drive
          {drive}) {
  // Set the controller to be continuous (because it is an angle controller)
  m_controller.EnableContinuousInput(-180, 180);
  // Set the controller tolerance - the delta tolerance ensures the robot is
  // stationary at the setpoint before it is considered as having reached the
  // reference
  m_controller.SetTolerance(kTurnTolerance, kTurnRateTolerance);

  std::cout << "TurnDegrees(): speed = " << speed << " angle = " << angle << std:: endl;

  AddRequirements({drive});
}

bool TurnDegrees::IsFinished() {
  bool retVal;
  
  retVal = GetController().AtSetpoint(); 
  
  //std::cout << "IsFinished(): " << retVal << std::endl;
  
  return retVal;
}
