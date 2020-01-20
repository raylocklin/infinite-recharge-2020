#include "ControllerDef.h"
#include "ControlCheckExec.h"
#include "DriverDef.h"

#include <frc/GenericHID.h>
#include <frc/PWMVictorSPX.h>
#include <frc/XboxController.h>
#include <frc/drive/DifferentialDrive.h>

namespace control
{
    void checkAndExec()
    {
        inline void joystickPosition();
        inline void buttonA();
        inline void buttonB();
        inline void buttonX();
        inline void buttonY();
        inline void bumper();  
    }
    
    inline void joystickPosition()
    {
        driverMain.ArcadeDrive(
            leController.GetX(frc::GenericHID::JoystickHand::kLeftHand),
            leController.GetY(frc::GenericHID::JoystickHand::kRightHand));
    }
}