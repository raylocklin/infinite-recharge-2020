#include "ControllerDef.h"
#include "ControlCheckExec.h"
#include "DriverDef.h"

#include <frc/GenericHID.h>
#include <frc/PWMVictorSPX.h>
#include <frc/XboxController.h>
#include <frc/drive/DifferentialDrive.h>

namespace control
{
    void joystickPosition()
    {
        driverMain.ArcadeDrive(
            leController.GetX(frc::GenericHID::JoystickHand::kLeftHand),
            leController.GetY(frc::GenericHID::JoystickHand::kRightHand));
    }
}