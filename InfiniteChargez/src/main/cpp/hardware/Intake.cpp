#include "MotorGroups.h"
#include "MotorDef.h"

namespace hardware
{
    void Intake::in()
    {
        intakeMotorLeft.SetSpeed(baseSpeed);
        intakeMotorRight.SetSpeed(-baseSpeed);
    }

    void Intake::out()
    {
        intakeMotorLeft.SetSpeed(-baseSpeed);
        intakeMotorRight.SetSpeed(baseSpeed);

    }

    void Intake::stop()
    {
        intakeMotorLeft.SetSpeed(0);
        intakeMotorRight.SetSpeed(0);
    }

}