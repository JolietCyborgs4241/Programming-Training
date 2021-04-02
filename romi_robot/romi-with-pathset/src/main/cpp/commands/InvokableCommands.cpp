#include "commands/InvokableCommands.h"

#include <string>
#include <vector>


//  stop utility command

InvokableCmdStop::InvokableCmdStop(Drivetrain* drivetrain) : m_drivetrain(drivetrain) {
  AddRequirements({drivetrain});
}

void InvokableCmdStop::Initialize() {
  m_drivetrain->ArcadeDrive(0, 0);
}

void InvokableCmdStop::Execute() {}

void InvokableCmdStop::End(bool interrupted) {}

bool InvokableCmdStop::IsFinished() { 
  return true; 
}


// reset odometry utility command

InvokableCmdResetOdo::InvokableCmdResetOdo(Drivetrain* drivetrain) : m_drivetrain(drivetrain) {
  AddRequirements({drivetrain});
}

void InvokableCmdResetOdo::Initialize() {
  m_drivetrain->ResetOdometry(frc::Pose2d(0_m, 0_m, 0_deg));
}

void InvokableCmdResetOdo::Execute() {}

void InvokableCmdResetOdo::End(bool interrupted) {}

bool InvokableCmdResetOdo::IsFinished() { 
  return true; 
}



// red led on utility command

InvokableCmdRedLedOn::InvokableCmdRedLedOn(OnBoardIO *onBoardIO) : m_onBoardIO(onBoardIO) {
  AddRequirements({onBoardIO});
}

void InvokableCmdRedLedOn::Initialize() {
  m_onBoardIO->SetRedLed(true);
}

void InvokableCmdRedLedOn::Execute() {}

void InvokableCmdRedLedOn::End(bool interrupted) {}

bool InvokableCmdRedLedOn::IsFinished() { 
  return true; 
}


// red led off utility command

InvokableCmdRedLedOff::InvokableCmdRedLedOff(OnBoardIO *onBoardIO) : m_onBoardIO(onBoardIO) {
  AddRequirements({onBoardIO});
}

void InvokableCmdRedLedOff::Initialize() {
  m_onBoardIO->SetRedLed(false);
}

void InvokableCmdRedLedOff::Execute() {}

void InvokableCmdRedLedOff::End(bool interrupted) {}

bool InvokableCmdRedLedOff::IsFinished() { 
  return true; 
}


// yellow led on utility command

InvokableCmdYellowLedOn::InvokableCmdYellowLedOn(OnBoardIO *onBoardIO) : m_onBoardIO(onBoardIO) {
  AddRequirements({onBoardIO});
}

void InvokableCmdYellowLedOn::Initialize() {
  m_onBoardIO->SetYellowLed(true);
}

void InvokableCmdYellowLedOn::Execute() {}

void InvokableCmdYellowLedOn::End(bool interrupted) {}

bool InvokableCmdYellowLedOn::IsFinished() { 
  return true; 
}


// yellow led off utility command

InvokableCmdYellowLedOff::InvokableCmdYellowLedOff(OnBoardIO *onBoardIO) : m_onBoardIO(onBoardIO) {
  AddRequirements({onBoardIO});
}

void InvokableCmdYellowLedOff::Initialize() {
  m_onBoardIO->SetYellowLed(false);
}

void InvokableCmdYellowLedOff::Execute() {}

void InvokableCmdYellowLedOff::End(bool interrupted) {}

bool InvokableCmdYellowLedOff::IsFinished() { 
  return true; 
}


// green led on utility command

InvokableCmdGreenLedOn::InvokableCmdGreenLedOn(OnBoardIO *onBoardIO) : m_onBoardIO(onBoardIO) {
  AddRequirements({onBoardIO});
}

void InvokableCmdGreenLedOn::Initialize() {
  m_onBoardIO->SetGreenLed(true);
}

void InvokableCmdGreenLedOn::Execute() {}

void InvokableCmdGreenLedOn::End(bool interrupted) {}

bool InvokableCmdGreenLedOn::IsFinished() { 
  return true; 
}


// green led off utility command

InvokableCmdGreenLedOff::InvokableCmdGreenLedOff(OnBoardIO *onBoardIO) : m_onBoardIO(onBoardIO) {
  AddRequirements({onBoardIO});
}

void InvokableCmdGreenLedOff::Initialize() {
  m_onBoardIO->SetGreenLed(false);
}

void InvokableCmdGreenLedOff::Execute() {}

void InvokableCmdGreenLedOff::End(bool interrupted) {}

bool InvokableCmdGreenLedOff::IsFinished() { 
  return true; 
}



// InvokableCommands implementation

InvokableCommands::InvokableCommands(string name, frc2::Command *command) {
  m_names.push_back(name);
  m_commands.push_back(command);
}


InvokableCommands::InvokableCommands(char *c_name, frc2::Command *command) {
  string name = c_name;
  m_names.push_back(name);
  m_commands.push_back(command);
}


int InvokableCommands::getCommandCount() {
  return(int)(m_names.size());
}


frc2::Command *InvokableCommands::getCommand(string name) {

  for (auto i = 0 ; i < (int)m_names.size() ; i++) {
    if (m_names[i] == name) {
      return (m_commands[i]);
    }
  }

  return nullptr;
}


frc2::Command *InvokableCommands::getCommand(int index) {

  if (index >= 0 && index < (int)m_names.size()) {
    return (m_commands[index]);
  }

  return nullptr;
}