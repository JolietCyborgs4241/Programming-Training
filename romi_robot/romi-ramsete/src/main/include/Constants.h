// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc/kinematics/DifferentialDriveKinematics.h>
#include <frc/trajectory/constraint/DifferentialDriveKinematicsConstraint.h>

#include <units/acceleration.h>
#include <units/length.h>
#include <units/time.h>
#include <units/velocity.h>
#include <units/voltage.h>
#include <wpi/math>


/**
 * The Constants header provides a convenient place for teams to hold robot-wide
 * numerical or bool constants.  This should not be used for any other purpose.
 *
 * It is generally a good idea to place constants into subsystem- or
 * command-specific namespaces within this header, which can then be used where
 * they are needed.
 */

namespace DriveConstants {

    extern const frc::DifferentialDriveKinematics kDriveKinematics;

    constexpr double kCountsPerMotorRevolution = 12.0;
    constexpr double kGearRatio = 120.0;
    constexpr double kCountsPerWheelRevolution = kCountsPerMotorRevolution * kGearRatio;

    constexpr auto   kWheelDiameter = 70_mm;

    constexpr auto   kS = 0.929_V; // 0.584_V;
    constexpr auto   kV = 6.33 * 1_V * 1_s / 1_m; // 0.18 * 1_V * 1_s / 1_m;
    constexpr auto   kA = 0.0389 * 1_V * 1_s * 1_s / 1_m; // 0.000186 * 1_V * 1_s * 1_s / 1_m;

    constexpr double kPDriveVel = 0.085;
    constexpr double kIDriveVel = 0.0;
    constexpr double kDDriveVel = 0.0;

    constexpr auto   kTrackWidth = 0.140_m;   // meters


}  // namespace DriveConstants


namespace AutoConstants {
    constexpr double kRamseteB = 2;
    constexpr double kRamseteZeta = 0.7;

    constexpr auto kMaxSpeed = 0.5_mps;
    constexpr auto kMaxAcceleration = 0.5_mps_sq;
}   // namespace AutoConstants