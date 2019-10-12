#include "RobotMap.h"
#include "WPILib.h"
#include "ctre/Phoenix.h"
#include "LiveWindow/LiveWindow.h"

using namespace frc;

WPI_TalonSRX* RobotMap::claw = NULL;