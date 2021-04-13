#pragma once

#include <frc2/command/Command.h>
#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include <frc2/command/InstantCommand.h>
#include <frc2/command/SequentialCommandGroup.h>

#include <subsystems/OnBoardIO.h>
#include <subsystems/Drivetrain.h>

#include <string>
#include <vector>


using std::string;


#define MAX_INVOKABLE_COMMANDS      20


class InvokableCommands {

  public:
    InvokableCommands(Drivetrain *drive, frc::DigitalOutput *red,
                                         frc::DigitalOutput *yellow,
                                         frc::DigitalOutput *green);

    bool checkCommandName(string name);

    string getCommandName(int index);

    void addCommand(frc2::SequentialCommandGroup *cmdGroup, string cmdName);

  private:

    int                 m_cmdCount = 0;

    string              m_cmdNames[MAX_INVOKABLE_COMMANDS];

    Drivetrain          *m_drive;
    frc::DigitalOutput  *m_redLED;
    frc::DigitalOutput  *m_yellowLED;
    frc::DigitalOutput  *m_greenLED;
};



class InvokableCmdStop
    : public frc2::CommandHelper<frc2::CommandBase, InvokableCmdStop> {

    public:

        explicit InvokableCmdStop(Drivetrain *drivetrain);

        void Initialize() override;

        bool IsFinished() override;

    private:

        Drivetrain *m_drivetrain;
};


class InvokableCmdResetOdo
    : public frc2::CommandHelper<frc2::CommandBase, InvokableCmdResetOdo> {

    public:

        explicit InvokableCmdResetOdo(Drivetrain *drivetrain);

        void Initialize() override;

        bool IsFinished() override;

    private:

        Drivetrain *m_drivetrain;
};


class InvokableCmdRedLEDOn
    : public frc2::CommandHelper<frc2::CommandBase, InvokableCmdRedLEDOn> {

    public:

        explicit InvokableCmdRedLEDOn(frc::DigitalOutput *io);

        void Initialize() override;

        bool IsFinished() override;

    private:

        frc::DigitalOutput *m_io;
};

class InvokableCmdRedLEDOff
    : public frc2::CommandHelper<frc2::CommandBase, InvokableCmdRedLEDOff> {

    public:

        explicit InvokableCmdRedLEDOff(frc::DigitalOutput *io);

        void Initialize() override;

        bool IsFinished() override;

    private:

        frc::DigitalOutput *m_io;
};

class InvokableCmdYellowLEDOn
    : public frc2::CommandHelper<frc2::CommandBase, InvokableCmdYellowLEDOn> {

    public:

        explicit InvokableCmdYellowLEDOn(frc::DigitalOutput *io);

        void Initialize() override;

        bool IsFinished() override;

    private:

        frc::DigitalOutput *m_io;
};

class InvokableCmdYellowLEDOff
    : public frc2::CommandHelper<frc2::CommandBase, InvokableCmdYellowLEDOff> {

    public:

        explicit InvokableCmdYellowLEDOff(frc::DigitalOutput *io);

        void Initialize() override;

        bool IsFinished() override;

    private:
        frc::DigitalOutput *m_io;
};

class InvokableCmdGreenLEDOn
    : public frc2::CommandHelper<frc2::CommandBase, InvokableCmdGreenLEDOn> {

    public:

        explicit InvokableCmdGreenLEDOn(frc::DigitalOutput *io);

        void Initialize() override;

        bool IsFinished() override;

    private:

        frc::DigitalOutput *m_io;
};

class InvokableCmdGreenLEDOff
    : public frc2::CommandHelper<frc2::CommandBase, InvokableCmdGreenLEDOff> {

    public:

        explicit InvokableCmdGreenLEDOff(frc::DigitalOutput *io);

        void Initialize() override;

        bool IsFinished() override;

    private:

        frc::DigitalOutput *m_io;
};