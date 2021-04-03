#include "commands/InvokableCommands.h"

#include <string>



// InvokableCommands implementation

InvokableCommands::InvokableCommands() {
    m_cmdCount = 0;
}
    
    
void InvokableCommands::addCommands(string name, frc2::Command *command) {
  if (m_cmdCount < (MAX_INVOKABLE_COMMANDS - 1)) {
      // room for at least one more
      m_names[m_cmdCount]    = name;
      m_commands[m_cmdCount] = command;

      m_cmdCount++;
  } else {
      std::cerr << "InvokableCommands: No more space for commands - max # of commands is " << MAX_INVOKABLE_COMMANDS << std::endl;
  }
}


int InvokableCommands::getCommandCount() {
  return m_cmdCount;
}


frc2::Command *InvokableCommands::getCommand(string name) {

  for (auto i = 0 ; i < m_cmdCount ; i++) {
    if (m_names[i] == name) {
      return m_commands[i];
    }
  }

  return nullptr;
}


frc2::Command *InvokableCommands::getCommand(int index) {

  if (index >= 0 && index < m_cmdCount) {
    return m_commands[index];
  }

  return nullptr;
}


string InvokableCommands::getCommandName(int index) {

  if (index >= 0 && index < m_cmdCount) {
    return m_names[index];
  }

  return "";
}



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