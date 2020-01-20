#include "Robot.h"

    void Robot::Intake::in()
    {
        intakeMotorLeft.SetSpeed(baseSpeed);
        intakeMotorRight.SetSpeed(-baseSpeed);
    }

    void Robot::Intake::out()
    {
        intakeMotorLeft.SetSpeed(-baseSpeed);
        intakeMotorRight.SetSpeed(baseSpeed);

    }

    void Robot::Intake::stop()
    {
        intakeMotorLeft.SetSpeed(0);
        intakeMotorRight.SetSpeed(0);
    }
