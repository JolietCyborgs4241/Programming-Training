#include <frc2/command/Command.h>

#include <string>


//#include "commands/InvokableCommands.h"
#include "subsystems/Drivetrain.h"


#pragma once





frc2::Command   *InitializeAutoSequence(std::string, Drivetrain *, InvokableCommands *);
