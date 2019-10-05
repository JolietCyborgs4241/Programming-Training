/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once
#include "frc/WPLib.h"
#include <Commands/Subsystem.h>
#include "ctre/Phoenix.h"
using namespace frc;

class Claw : public frc::Subsystem {
 public:
  Claw();
  void ClawOpen(); 
  void ClawClose();
  void InitDefaultCommand() override;

 private: 
  WPI_TalonSRX* claw_motor;
  // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities

};
