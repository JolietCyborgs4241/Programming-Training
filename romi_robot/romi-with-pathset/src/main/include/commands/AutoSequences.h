#include <frc2/command/Command.h>
#include <frc2/command/InstantCommand.h>
#include <frc2/command/RunCommand.h>

#include <wpi/math>
#include <string>
#include <vector>

#include "Constants.h"

#include "RobotContainer.h"
#include "subsystems/Drivetrain.h"


#pragma once

using std::string;
using std::vector;


class InvokableCommands {

  public:
    InvokableCommands();
    InvokableCommands(const string name, const frc2::Command *command);
    InvokableCommands(const char *name, const frc2::Command *command);

    vector<const string> getCommandNames();

    int getCommandCount();

    frc2::Command *getCommand(string string);

  private:

    vector<const string> m_names;
    vector<const frc2::Command*> m_commands;
};



enum    autoActionType {AUTO_ACTION_NULL,
                        AUTO_ACTION_TRAJECTORY,
                        AUTO_ACTION_INTERNAL_COMMAND
                        };

typedef struct {

    std::string seqName;

} AUTO_SEQ;


frc2::Command   *InitializeAutoSequence(std::string, Drivetrain *, InvokableCommands *);

#ifdef  NEVER
class AutoSeqStopCmd
    : public frc2::CommandHelper<frc2::CommandBase, AutoSeqStopCmd> {

    public:

        explicit AutoSeqStopCmd(Drivetrain* drivetrain);
        AutoSeqStopCmd();

        void Initialize() override;

        void Execute() override;

        void End(bool interrupted) override;

        bool IsFinished() override;

    private:

        Drivetrain* m_drivetrain;
};

class ResetOdometry
    : public frc2::CommandHelper<frc2::CommandBase, ResetOdometry> {

    public:

        explicit ResetOdometry(Drivetrain* drivetrain);
        ResetOdometry();

        void Initialize() override;

        void Execute() override;

        void End(bool interrupted) override;

        bool IsFinished() override;

    private:

        Drivetrain* m_drivetrain;
};
#endif