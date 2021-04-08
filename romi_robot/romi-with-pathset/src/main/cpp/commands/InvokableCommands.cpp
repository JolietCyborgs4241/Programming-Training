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


// --------------------- commands ---------------------------


//  stop utility command

InvokableCmdStop::InvokableCmdStop(Drivetrain* drivetrain) : m_drivetrain(drivetrain) {
  AddRequirements({drivetrain});
}

void InvokableCmdStop::Initialize() {
  m_drivetrain->ArcadeDrive(0, 0);
}

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

bool InvokableCmdResetOdo::IsFinished() { 
  return true; 
}



// red led on utility command

InvokableCmdRedLedOn::InvokableCmdRedLedOn(frc::DigitalOutput *io) : m_io(io) {
  //AddRequirements({io});
}

void InvokableCmdRedLedOn::Initialize() {
  std::cout << "InvokableCmdRedLedOn: Initialize()" << std::endl;

  m_io->Set(true);
}

bool InvokableCmdRedLedOn::IsFinished() { 

            std::cout << "InvokableCmdRedLedOn: IsFinished()" << std::endl;

  return true; 
}


// red led off utility command

InvokableCmdRedLedOff::InvokableCmdRedLedOff(frc::DigitalOutput *io) : m_io(io) {
  //AddRequirements({io});
}

void InvokableCmdRedLedOff::Initialize() {
  m_io->Set(false);
}

bool InvokableCmdRedLedOff::IsFinished() { 
  return true; 
}


// yellow led on utility command

InvokableCmdYellowLedOn::InvokableCmdYellowLedOn(frc::DigitalOutput *io) : m_io(io) {
  //AddRequirements({io});
}

void InvokableCmdYellowLedOn::Initialize() {
  std::cout << "InvokableCmdYellowLedOn: Initialize()" << std::endl;

  m_io->Set(true);
}

bool InvokableCmdYellowLedOn::IsFinished() { 
  std::cout << "InvokableCmdYellowLedOn: IsFinished()" << std::endl;

  return true; 
}


// yellow led off utility command

InvokableCmdYellowLedOff::InvokableCmdYellowLedOff(frc::DigitalOutput *io) : m_io(io) {
  //AddRequirements({io});
}

void InvokableCmdYellowLedOff::Initialize() {
  m_io->Set(false);
}

bool InvokableCmdYellowLedOff::IsFinished() { 
  return true; 
}


// green led on utility command

InvokableCmdGreenLedOn::InvokableCmdGreenLedOn(frc::DigitalOutput *io) : m_io(io) {
  //AddRequirements({io});
}

void InvokableCmdGreenLedOn::Initialize() {
  std::cout << "InvokableCmdGreenLedOn: Initialize()" << std::endl;

  m_io->Set(true);
}

bool InvokableCmdGreenLedOn::IsFinished() { 

  std::cout << "InvokableCmdGreenLedOn: IsFinished()" << std::endl;

  return true; 
}


// green led off utility command

InvokableCmdGreenLedOff::InvokableCmdGreenLedOff(frc::DigitalOutput *io) : m_io(io) {
  //AddRequirements({io});
}

void InvokableCmdGreenLedOff::Initialize() {
  m_io->Set(false);
}

bool InvokableCmdGreenLedOff::IsFinished() { 
  return true; 
}