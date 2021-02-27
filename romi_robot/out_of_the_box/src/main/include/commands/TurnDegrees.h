// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

//#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include <frc2/command/PIDCommand.h>  
#include <units/angle.h>
#include <units/length.h>

#include "subsystems/Drivetrain.h"

class TurnDegrees : public frc2::CommandHelper<frc2::PIDCommand, TurnDegrees> {
 public:
  TurnDegrees(double speed, units::degree_t angle, Drivetrain* drive);
  //    : m_speed(speed), m_angle(angle), m_drive(drive);

  bool IsFinished() override;

 private:
};
