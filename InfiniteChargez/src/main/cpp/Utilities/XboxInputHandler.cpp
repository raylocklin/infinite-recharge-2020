#include "XboxInputHandler.h"
#include "Utilities.h"

#include <frc/XboxController.h>
namespace utilities
{
    void XboxInputHandler::operator=(frc::XboxController XBoxController)
    {
        //Joystick
        setJoystickRight(joystick_t{XBoxController.GetX(frc::GenericHID::JoystickHand::kLeftHand), 
            XBoxController.GetY(frc::GenericHID::kLeftHand)});

        setJoystickLeft(joystick_t{XBoxController.GetX(frc::GenericHID::JoystickHand::kRightHand), 
            XBoxController.GetY(frc::GenericHID::kRightHand)});
        
        //Button Functions
        //Button A
        setButtonAState(XBoxController.GetAButton());
        setButtonAPressed(XBoxController.GetAButtonPressed());
        setButtonAReleased(XBoxController.GetAButtonReleased());
        //Button B
        setButtonBState(XBoxController.GetBButton());
        setButtonBPressed(XBoxController.GetBButtonPressed());
        setButtonBReleased(XBoxController.GetBButtonReleased());
        //Button X
        setButtonXState(XBoxController.GetXButton());
        setButtonXPressed(XBoxController.GetXButtonPressed());
        setButtonXReleased(XBoxController.GetXButtonReleased());
        //Button Y
        setButtonYState(XBoxController.GetYButton());
        setButtonYPressed(XBoxController.GetYButtonPressed());
        setButtonYReleased(XBoxController.GetYButtonReleased());

        //Triggers
        //Triger Left
        setTriggerLeft(XBoxController.GetTriggerAxis(frc::GenericHID::kLeftHand));
        //Trigger Right
        setTriggerRight(XBoxController.GetTriggerAxis(frc::GenericHID::kRightHand));



    }
}
