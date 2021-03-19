// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/Drivetrain.h"

#include <wpi/math>
#include <frc/smartdashboard/SmartDashboard.h>


#include "Constants.h"

using namespace DriveConstants;

// The Romi has the left and right motors set to
// PWM channels 0 and 1 respectively
// The Romi has onboard encoders that are hardcoded
// to use DIO pins 4/5 and 6/7 for the left and right
Drivetrain::Drivetrain() {

  m_leftEncoder.SetDistancePerPulse(
      wpi::math::pi * kWheelDiameter.to<double>() / kCountsPerWheelRevolution);

  m_rightEncoder.SetDistancePerPulse(
      wpi::math::pi * kWheelDiameter.to<double>() / kCountsPerWheelRevolution);

  ResetEncoders();
}

void Drivetrain::Periodic() {

  m_odometry.Update(GetGyroAngle(),
                    units::meter_t(m_leftEncoder.GetDistance()),
                    units::meter_t(m_rightEncoder.GetDistance()));
}

void Drivetrain::ArcadeDrive(double xaxisSpeed, double zaxisRotate) {
  m_drive.ArcadeDrive(xaxisSpeed, zaxisRotate);
}

void Drivetrain::TankDriveVolts(units::volt_t left, units::volt_t right) {
  m_leftMotor.SetVoltage(left);
  m_rightMotor.SetVoltage(-right);
  m_drive.Feed();
}

void Drivetrain::ResetEncoders() {
  m_leftEncoder.Reset();
  m_rightEncoder.Reset();
}

int Drivetrain::GetLeftEncoderCount() {
  return m_leftEncoder.Get();
}

int Drivetrain::GetRightEncoderCount() {
  return m_rightEncoder.Get();
}

units::meter_t Drivetrain::GetLeftDistance() {
  return units::meter_t(m_leftEncoder.GetDistance());
}

units::meter_t Drivetrain::GetRightDistance() {
  return units::meter_t(m_rightEncoder.GetDistance());
}

units::meter_t Drivetrain::GetAverageDistance() {
  return (GetLeftDistance() + GetRightDistance()) / 2.0;
}

units::meters_per_second_t Drivetrain::GetLeftVelocity() {
  return units::meters_per_second_t(m_leftEncoder.GetRate());
}

units::meters_per_second_t Drivetrain::GetRightVelocity() {
  return units::meters_per_second_t(m_rightEncoder.GetRate());
}

units::meters_per_second_t Drivetrain::GetAverageVelocity() {
  return units::meters_per_second_t(GetLeftVelocity() + GetRightVelocity()) / 2.0;
}

double Drivetrain::GetAccelX() {
  return m_accelerometer.GetX();
}

double Drivetrain::GetAccelY() {
  return m_accelerometer.GetY();
}

double Drivetrain::GetAccelZ() {
  return m_accelerometer.GetZ();
}

double Drivetrain::GetGyroAngleX() {
  return m_gyro.GetAngleX();
}

double Drivetrain::GetGyroAngleY() {
  return m_gyro.GetAngleY();
}

double Drivetrain::GetGyroAngleZ() {
  return m_gyro.GetAngleZ();
}

void Drivetrain::ResetGyro() {
  m_gyro.Reset();
}

frc::Pose2d Drivetrain::GetPose() {
  
  frc::Pose2d pose = m_odometry.GetPose();

  frc::SmartDashboard::PutNumber("pose.X", (pose.X()).to<double>());
  frc::SmartDashboard::PutNumber("pose.Y", (pose.Y()).to<double>());
  frc::SmartDashboard::PutNumber("pose.rot", ((pose.Rotation()).Degrees()).to<double>());

  //std::cout << "DriveTrain::GetPose(): X " << pose.X() << "  Y " << pose.Y() << "   Rot " << (pose.Rotation()).Degrees() << std::endl;

  return pose;
}

frc::Rotation2d Drivetrain::GetGyroAngle() {
  return frc::Rotation2d((units::degree_t) m_gyro.GetAngleZ());
}

void Drivetrain::ResetOdometry(frc::Pose2d pose) {
  ResetEncoders();
  m_odometry.ResetPosition(pose, GetGyroAngle());
}

frc::DifferentialDriveWheelSpeeds Drivetrain::GetWheelSpeeds() {
    return { units::meters_per_second_t(m_leftEncoder.GetRate()),
          units::meters_per_second_t(m_rightEncoder.GetRate() )};
}
