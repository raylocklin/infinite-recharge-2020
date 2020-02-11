#include "XboxInputHandler.h"
#include "Utilities.h"

#include <frc/XboxController.h>
namespace utilities
{
    void XboxInputHandler::operator=(frc::XboxController XBoxController)
    {
        //Joystick
        m_joystickLeft = joystick_t{XBoxController.GetX(frc::GenericHID::JoystickHand::kLeftHand), 
            XBoxController.GetY(frc::GenericHID::kLeftHand)};

        m_joystickRight = joystick_t{XBoxController.GetX(frc::GenericHID::JoystickHand::kRightHand), 
            XBoxController.GetY(frc::GenericHID::kRightHand)};
    }
}