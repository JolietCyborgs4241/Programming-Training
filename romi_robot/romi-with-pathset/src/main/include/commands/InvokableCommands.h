#pragma once

#include <frc2/command/Command.h>
#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/OnBoardIO.h"
#include "subsystems/Drivetrain.h"

#include <string>
#include <vector>


using std::string;
using std::vector;

#define MAX_INVOKABLE_COMMANDS      10

class InvokableCommands {

  public:
    InvokableCommands();

    void addCommands(string name, frc2::Command *command);

    string getCommandName(int i);

    int getCommandCount();

    frc2::Command *getCommand(string name);
    frc2::Command *getCommand(int i);

  private:

    int             m_cmdCount = 0;
    string          m_names[MAX_INVOKABLE_COMMANDS];
    //frc2::Command   *m_commands[MAX_INVOKABLE_COMMANDS];
};



class InvokableCmdStop
    : public frc2::CommandHelper<frc2::CommandBase, InvokableCmdStop> {

    public:

        explicit InvokableCmdStop(Drivetrain *drivetrain);
        InvokableCmdStop();

        void Initialize() override;

        void Execute() override;

        void End(bool interrupted) override;

        bool IsFinished() override;

    private:

        Drivetrain *m_drivetrain;
};


class InvokableCmdResetOdo
    : public frc2::CommandHelper<frc2::CommandBase, InvokableCmdResetOdo> {

    public:

        explicit InvokableCmdResetOdo(Drivetrain *drivetrain);
        InvokableCmdResetOdo();

        void Initialize() override;

        void Execute() override;

        void End(bool interrupted) override;

        bool IsFinished() override;

    private:

        Drivetrain *m_drivetrain;
};


class InvokableCmdRedLedOn
    : public frc2::CommandHelper<frc2::CommandBase, InvokableCmdRedLedOn> {

    public:

        explicit InvokableCmdRedLedOn(OnBoardIO *onBoardIO);
        InvokableCmdRedLedOn();

        void Initialize() override;

        void Execute() override;

        void End(bool interrupted) override;

        bool IsFinished() override;

    private:

        OnBoardIO *m_onBoardIO;
};

class InvokableCmdRedLedOff
    : public frc2::CommandHelper<frc2::CommandBase, InvokableCmdRedLedOff> {

    public:

        explicit InvokableCmdRedLedOff(OnBoardIO *onBoardIO);
        InvokableCmdRedLedOff();

        void Initialize() override;

        void Execute() override;

        void End(bool interrupted) override;

        bool IsFinished() override;

    private:

        OnBoardIO *m_onBoardIO;
};

class InvokableCmdYellowLedOn
    : public frc2::CommandHelper<frc2::CommandBase, InvokableCmdYellowLedOn> {

    public:

        explicit InvokableCmdYellowLedOn(OnBoardIO *onBoardIO);
        InvokableCmdYellowLedOn();

        void Initialize() override;

        void Execute() override;

        void End(bool interrupted) override;

        bool IsFinished() override;

    private:

        OnBoardIO *m_onBoardIO;
};

class InvokableCmdYellowLedOff
    : public frc2::CommandHelper<frc2::CommandBase, InvokableCmdYellowLedOff> {

    public:

        explicit InvokableCmdYellowLedOff(OnBoardIO *onBoardIO);
        InvokableCmdYellowLedOff();

        void Initialize() override;

        void Execute() override;

        void End(bool interrupted) override;

        bool IsFinished() override;

    private:
        OnBoardIO *m_onBoardIO;
};

class InvokableCmdGreenLedOn
    : public frc2::CommandHelper<frc2::CommandBase, InvokableCmdGreenLedOn> {

    public:

        explicit InvokableCmdGreenLedOn(OnBoardIO *onBoardIO);
        InvokableCmdGreenLedOn();

        void Initialize() override;

        void Execute() override;

        void End(bool interrupted) override;

        bool IsFinished() override;

    private:

        OnBoardIO *m_onBoardIO;
};

class InvokableCmdGreenLedOff
    : public frc2::CommandHelper<frc2::CommandBase, InvokableCmdGreenLedOff> {

    public:

        explicit InvokableCmdGreenLedOff(OnBoardIO *onBoardIO);
        InvokableCmdGreenLedOff();

        void Initialize() override;

        void Execute() override;

        void End(bool interrupted) override;

        bool IsFinished() override;

    private:

        OnBoardIO *m_onBoardIO;
};