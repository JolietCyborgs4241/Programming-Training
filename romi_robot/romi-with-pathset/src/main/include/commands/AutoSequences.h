#include <wpi/math>
#include <string>

#include "Constants.h"

#include "subsystems/Drivetrain.h"


#pragma once


enum    autoActionType {AUTO_ACTION_NULL,
                        AUTO_ACTION_TRAJECTORY,
                        AUTO_ACTION_INTERNAL_COMMAND
                        };

typedef struct {

    std::string seqName;

} AUTO_SEQ;


frc2::Command   *InitializeAutoSequence(std::string, Drivetrain *);


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
