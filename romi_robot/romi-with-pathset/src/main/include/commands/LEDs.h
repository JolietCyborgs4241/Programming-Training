// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <string>
#include <vector>

#include <frc2/command/Command.h>
#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

using std::string;
using std::vector;


class InvokableCommands {

  public:
    InvokableCommands();
    InvokableCommands(string name, frc2::Command *command);

    vector<string> getCommandNames();

    int getCommandCount();

    frc2::Command *getCommand(string string);

  private:

    vector<string> m_names;
    vector<frc2::Command*> m_commands;
};



class LEDControlRedOn : public frc2::CommandHelper<frc2::CommandBase, LEDControlRedOn> {
 public:
  explicit LEDControlRedOn(OnBoardIO *onboardIO);
  LEDControlRedOn();

  void Initialize() override;
  void Execute() override;
  void End(bool interrupted) override;
  bool IsFinished() override;

 private:
  OnBoardIO *m_onBoardIO;
};


class LEDControlRedOff : public frc2::CommandHelper<frc2::CommandBase, LEDControlRedOff> {
 public:
  explicit LEDControlRedOff(OnBoardIO *onboardIO);
  LEDControlRedOff();

  void Initialize() override;
  void Execute() override;
  void End(bool interrupted) override;
  bool IsFinished() override;

 private:
  OnBoardIO *m_onBoardIO;
};


class LEDControlYellowOn : public frc2::CommandHelper<frc2::CommandBase, LEDControlYellowOn> {
 public:
  explicit LEDControlYellowOn(OnBoardIO *onboardIO);
  LEDControlYellowOn();

  void Initialize() override;
  void Execute() override;
  void End(bool interrupted) override;
  bool IsFinished() override;

 private:
  OnBoardIO *m_onBoardIO;
};


class LEDControlYellowOff : public frc2::CommandHelper<frc2::CommandBase, LEDControlYellowOff> {
 public:
  explicit LEDControlYellowOff(OnBoardIO *onboardIO);
  LEDControlYellowOff();

  void Initialize() override;
  void Execute() override;
  void End(bool interrupted) override;
  bool IsFinished() override;

 private:
  OnBoardIO *m_onBoardIO;
};


class LEDControlGreenOn : public frc2::CommandHelper<frc2::CommandBase, LEDControlGreenOn> {
 public:
  explicit LEDControlGreenOn(OnBoardIO *onboardIO);
  LEDControlGreenOn();

  void Initialize() override;
  void Execute() override;
  void End(bool interrupted) override;
  bool IsFinished() override;

 private:
  OnBoardIO *m_onBoardIO;
};


class LEDControlGreenOff : public frc2::CommandHelper<frc2::CommandBase, LEDControlGreenOff> {
 public:
  explicit LEDControlGreenOff(OnBoardIO *onBoardIO);
  LEDControlGreenOff();

  void Initialize() override;
  void Execute() override;
  void End(bool interrupted) override;
  bool IsFinished() override;

 private:
  OnBoardIO *m_onBoardIO;
};



