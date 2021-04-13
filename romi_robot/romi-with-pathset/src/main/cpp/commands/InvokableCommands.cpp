#include "commands/InvokableCommands.h"

#include <string>



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

InvokableCmdRedLEDOn::InvokableCmdRedLEDOn(frc::DigitalOutput *io) : m_io(io) {
  //AddRequirements({io});
}

void InvokableCmdRedLEDOn::Initialize() {
  std::cout << "InvokableCmdRedLEDOn: Initialize()" << std::endl;

  m_io->Set(true);
}

bool InvokableCmdRedLEDOn::IsFinished() { 
  return true; 
}


// red led off utility command

InvokableCmdRedLEDOff::InvokableCmdRedLEDOff(frc::DigitalOutput *io) : m_io(io) {
  //AddRequirements({io});
}

void InvokableCmdRedLEDOff::Initialize() {
  std::cout << "InvokableCmdRedLEDOff: Initialize()" << std::endl;

  m_io->Set(false);
}

bool InvokableCmdRedLEDOff::IsFinished() { 
  return true; 
}


// yellow led on utility command

InvokableCmdYellowLEDOn::InvokableCmdYellowLEDOn(frc::DigitalOutput *io) : m_io(io) {
  //AddRequirements({io});
}

void InvokableCmdYellowLEDOn::Initialize() {
  std::cout << "InvokableCmdYellowLEDOn: Initialize()" << std::endl;

  m_io->Set(true);
}

bool InvokableCmdYellowLEDOn::IsFinished() { 
  return true; 
}


// yellow led off utility command

InvokableCmdYellowLEDOff::InvokableCmdYellowLEDOff(frc::DigitalOutput *io) : m_io(io) {
  //AddRequirements({io});
}

void InvokableCmdYellowLEDOff::Initialize() {
  std::cout << "InvokableCmdYellowLEDOff: Initialize()" << std::endl;

  m_io->Set(false);
}

bool InvokableCmdYellowLEDOff::IsFinished() { 
  return true; 
}


// green led on utility command

InvokableCmdGreenLEDOn::InvokableCmdGreenLEDOn(frc::DigitalOutput *io) : m_io(io) {
  //AddRequirements({io});
}

void InvokableCmdGreenLEDOn::Initialize() {
  std::cout << "InvokableCmdGreenLEDOn: Initialize()" << std::endl;

  m_io->Set(true);
}

bool InvokableCmdGreenLEDOn::IsFinished() { 
  return true; 
}


// green led off utility command

InvokableCmdGreenLEDOff::InvokableCmdGreenLEDOff(frc::DigitalOutput *io) : m_io(io) {
  //AddRequirements({io});
}

void InvokableCmdGreenLEDOff::Initialize() {
  std::cout << "InvokableCmdGreenLEDOff: Initialize()" << std::endl;

  m_io->Set(false);
}

bool InvokableCmdGreenLEDOff::IsFinished() { 
  return true; 
}



// InvokableCommands implementation


static  string  commandNames[] = {
                            "STOP",
                            "RESET_ODO",
                            "RED_ON",
                            "RED_OFF",
                            "YELLOW_ON",
                            "YELLOW_OFF",
                            "GREEN_ON",
                            "GREEN_OFF",
                            ""
                        };


InvokableCommands::InvokableCommands(Drivetrain *drive, frc::DigitalOutput *redLED,
                                                        frc::DigitalOutput *yellowLED,
                                                        frc::DigitalOutput *greenLED) :
                                                             m_drive(drive),
                                                             m_redLED(redLED),
                                                             m_yellowLED(yellowLED),
                                                             m_greenLED(greenLED)  {
  int i;

  for (i = 0 ; commandNames[i] != "" && i < MAX_INVOKABLE_COMMANDS ; i++) {
    m_cmdNames[i] = commandNames[i];
  }

  if (i >= MAX_INVOKABLE_COMMANDS) {
    std::cerr << "InvokableCommands::InvokableCommands(): Too many invokable commands - max of "
              << MAX_INVOKABLE_COMMANDS << " permitted" << std::endl;
  }

  m_cmdCount = i;
}


void InvokableCommands::addCommand(frc2::SequentialCommandGroup *cmdGroup, string cmdName) {

  // is it even a valid name?
  if ( ! checkCommandName(cmdName)) {
    std::cerr << "InvokableCommands::addCommand():  command \"" << cmdName << "\" not a known command" << std::endl;
    return;
  }

  // for each command name, we create an appropriate comand and move it into the command group
  //
  // this takes care of object ownership issues when dealing with command points and the like
  if (cmdName == "STOP") {

    InvokableCmdStop  cmdStop(m_drive);
    cmdGroup->AddCommands(std::move(cmdStop));

  } else if (cmdName == "RESET_ODO") {

    InvokableCmdResetOdo  cmdResetOdo(m_drive);
    cmdGroup->AddCommands(std::move(cmdResetOdo));

  } else if (cmdName == "RED_ON") {

    InvokableCmdRedLEDOn  cmdRedLEDOn(m_redLED);
    cmdGroup->AddCommands(std::move(cmdRedLEDOn));

  } else if (cmdName == "RED_OFF") {

    InvokableCmdRedLEDOff  cmdRedLEDOff(m_redLED);
    cmdGroup->AddCommands(std::move(cmdRedLEDOff));

  } else if (cmdName == "GREEN_ON") {

    InvokableCmdGreenLEDOn  cmdGreenLEDOn(m_greenLED);
    cmdGroup->AddCommands(std::move(cmdGreenLEDOn));

  } else if (cmdName == "GREEN_OFF") {

    InvokableCmdGreenLEDOff  cmdGreenLEDOff(m_greenLED);
    cmdGroup->AddCommands(std::move(cmdGreenLEDOff));

  } else if (cmdName == "YELLOW_ON") {

    InvokableCmdYellowLEDOn  cmdYellowLEDOn(m_yellowLED);
    cmdGroup->AddCommands(std::move(cmdYellowLEDOn));

  } else if (cmdName == "YELLOW_OFF") {

    InvokableCmdYellowLEDOff  cmdYellowLEDOff(m_yellowLED);
    cmdGroup->AddCommands(std::move(cmdYellowLEDOff));
  }
}


bool InvokableCommands::checkCommandName(string name) {

  for (auto i = 0 ; i < m_cmdCount ; i++) {
    if (m_cmdNames[i] == name) {
      return true;
    }
  }

  return false;
}


string InvokableCommands::getCommandName(int index) {

  if (index < 0 || index >= m_cmdCount) {
    return "";
  } else {
    return m_cmdNames[index];
  }
}
