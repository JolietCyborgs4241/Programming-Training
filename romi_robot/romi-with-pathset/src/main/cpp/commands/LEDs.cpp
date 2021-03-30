// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/OnBoardIO.h"
#include "commands/LEDs.h"



InvokableCommands::InvokableCommands(string name, frc2::Command *command) {
  m_names.push_back(name);
  m_commands.push_back(command);
}

vector<string> InvokableCommands::getCommandNames() {
  return m_names;
}

int InvokableCommands::getCommandCount() {
  return(int)(m_names.size());
}

frc2::Command* InvokableCommands::getCommand(string string) {

  for (auto i = 0 ; i < (int)m_names.size() ; i++) {
    if (m_names[i] == string) {
      return (m_commands[i]);
    }
  }

  return nullptr;
}




LEDControlRedOn::LEDControlRedOn(OnBoardIO *onBoardIO) : m_onBoardIO(onBoardIO) {
  AddRequirements({onBoardIO});
}

void LEDControlRedOn::Initialize() {
  
std::cout << "LEDControlRedOn::Initialize: entered" << std::endl;

  m_onBoardIO->SetRedLed(true);
}

void LEDControlRedOn::Execute() {

  // nothing applicable - all done in init
}

void LEDControlRedOn::End(bool interrupted) {

  // nothing applicable
}

bool LEDControlRedOn::IsFinished() {
  return true;
}



LEDControlRedOff::LEDControlRedOff(OnBoardIO *onBoardIO) : m_onBoardIO(onBoardIO) {
  AddRequirements({onBoardIO});
}

void LEDControlRedOff::Initialize() {
  
std::cout << "LEDControlRedOff::Initialize: entered" << std::endl;

  m_onBoardIO->SetRedLed(false);
}

void LEDControlRedOff::Execute() {

  // nothing applicable - all done in init
}

void LEDControlRedOff::End(bool interrupted) {

  // nothing applicable
}

bool LEDControlRedOff::IsFinished() {
  return true;
}



LEDControlYellowOn::LEDControlYellowOn(OnBoardIO *onBoardIO) : m_onBoardIO(onBoardIO) {
  AddRequirements({onBoardIO});
}

void LEDControlYellowOn::Initialize() {
  
std::cout << "LEDControlYellowOn::Initialize: entered" << std::endl;

  m_onBoardIO->SetYellowLed(true);
}

void LEDControlYellowOn::Execute() {

  // nothing applicable - all done in init
}

void LEDControlYellowOn::End(bool interrupted) {

  // nothing applicable
}

bool LEDControlYellowOn::IsFinished() {
  return true;
}



LEDControlYellowOff::LEDControlYellowOff(OnBoardIO *onBoardIO) : m_onBoardIO(onBoardIO) {
  AddRequirements({onBoardIO});
}
void LEDControlYellowOff::Initialize() {
  
std::cout << "LEDControlYellowOff::Initialize: entered" << std::endl;

  m_onBoardIO->SetYellowLed(false);
}

void LEDControlYellowOff::Execute() {

  // nothing applicable - all done in init
}

void LEDControlYellowOff::End(bool interrupted) {

  // nothing applicable
}

bool LEDControlYellowOff::IsFinished() {
  return true;
}



LEDControlGreenOn::LEDControlGreenOn(OnBoardIO *onBoardIO) : m_onBoardIO(onBoardIO) {
  AddRequirements({onBoardIO});
}
void LEDControlGreenOn::Initialize() {
  
std::cout << "LEDControlGreenOn::Initialize: entered" << std::endl;

  m_onBoardIO->SetGreenLed(true);
}

void LEDControlGreenOn::Execute() {

  // nothing applicable - all done in init
}

void LEDControlGreenOn::End(bool interrupted) {

  // nothing applicable
}

bool LEDControlGreenOn::IsFinished() {
  return true;
}



LEDControlGreenOff::LEDControlGreenOff(OnBoardIO *onBoardIO) : m_onBoardIO(onBoardIO) {
  AddRequirements({onBoardIO});
}

void LEDControlGreenOff::Initialize() {
  
std::cout << "LEDControlGreenOff::Initialize: entered" << std::endl;

  m_onBoardIO->SetGreenLed(false);
}

void LEDControlGreenOff::Execute() {

  // nothing applicable - all done in init
}

void LEDControlGreenOff::End(bool interrupted) {

  // nothing applicable
}

bool LEDControlGreenOff::IsFinished() {
  return true;
}
