// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/TurnDegrees.h"

#include <units/math.h>
#include <wpi/math>

double slowWhenWithin = 15;

void TurnDegrees::Initialize() {
  // Set motors to stop, read encoder values for starting point
  m_drive->ArcadeDrive(0, 0);
  m_drive->ResetEncoders();
  m_drive->ResetGyro();

  if (m_speed < 0) { 
    m_angle *= -1;
  }

  std::cout << "TurnDegrees::Initialize: turning = " << m_angle << std::endl;
  std::cout << "TurnDegrees::Initialize: gyro Z angle = " << m_drive->GetGyroAngleZ() << std::endl;
}

void TurnDegrees::Execute() {
  double speed;

  double turnAngleRemaining;
  double angle = m_drive->GetGyroAngleZ();

  std::cout << "TurnDegrees::Execute: gyro Z angle = " << angle << std::endl;

  turnAngleRemaining = (double)m_angle - angle;

  if (turnAngleRemaining < 0 ) {
    turnAngleRemaining *= -1;
  }

  if (turnAngleRemaining < slowWhenWithin) {
    std::cout << "TurnDegrees::Execute: slowing..." << std::endl;
    speed = 0.25;
  } else {
    speed = m_speed;
  }
  m_drive->ArcadeDrive(-speed, speed);
}

void TurnDegrees::End(bool interrupted) {
  m_drive->ArcadeDrive(0, 0);
  std::cout << "TurnDegrees::End: gyro Z angle = " << m_drive->GetGyroAngleZ() << std::endl;

}

bool TurnDegrees::IsFinished() {
#ifdef NEVER
 // Need to convert distance travelled to degrees. The Standard Romi Chassis
  // found here https://www.pololu.com/category/203/romi-chassis-kits, has a
  // wheel placement diameter (149 mm) - width of the wheel (8 mm) = 141 mm
  // or 5.551 inches. We then take into consideration the width of the tires.
  static auto inchPerDegree = (5.551_in * wpi::math::pi) / 360_deg;

  // Compare distance traveled from start to distance based on degree turn.
  return GetAverageTurningDistance() >= inchPerDegree * m_angle;
#endif // NEVER

  if (abs(m_drive->GetGyroAngleZ()) < 180) {
    return false;
  } else {
    return true;
  }
}

units::meter_t TurnDegrees::GetAverageTurningDistance() {
  auto l = units::math::abs(m_drive->GetLeftDistance());
  auto r = units::math::abs(m_drive->GetRightDistance());
  return (l + r) / 2;
}
