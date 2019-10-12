#include "RobotMap.h"

#include "WPILib.h"
#include "ctre/Phoenix.h"

#include "liveWindow/LiveWindow.h"

//#include "cyborg_talons.h"	// all Talon constants live here
//#include "subsytem_definitions.h" //Sensor value definitions

using namespace frc;




WPI_TalonSRX* RobotMap::Lift_motor = NULL;