#include "XboxInputHandler.h"
#include "Utilities.h"

#include <frc/XboxController.h>
namespace utilities
{
    void XboxInputHandler::operator=(frc::XboxController &XBoxController)
    {
        joystick_t joystickLeft{XBoxController.GetX(frc::GenericHID::JoystickHand::kLeftHand), 
            XBoxController.GetY(frc::GenericHID::kLeftHand)};
        
        joystick_t joystickRight{XBoxController.GetX(frc::GenericHID::JoystickHand::kRightHand), 
            XBoxController.GetY(frc::GenericHID::kRightHand)};
        //Joystick
        setJoystickRight(joystickLeft);

        setJoystickLeft(joystickRight);
        
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

        //Bumper
        //Bumper Left
        setBumperLeftState(XBoxController.GetBumper(frc::GenericHID::kLeftHand));
        setBumperLeftPressed(XBoxController.GetBumperPressed(frc::GenericHID::kLeftHand));
        setBumperLeftReleased(XBoxController.GetBumperReleased(frc::GenericHID::kLeftHand));
        //Bumper Right
        setBumperRightState(XBoxController.GetBumper(frc::GenericHID::kRightHand));
        setBumperRightPressed(XBoxController.GetBumperPressed(frc::GenericHID::kRightHand));
        setBumperRightReleased(XBoxController.GetBumperReleased(frc::GenericHID::kRightHand));

        //Stick Buttons
        //Left Stick Button
        setButtonLeftStickState(XBoxController.GetStickButton(frc::GenericHID::kLeftHand));
        setButtonLeftStickPressed(XBoxController.GetStickButtonPressed(frc::GenericHID::kLeftHand));
        setButtonLeftStickReleased(XBoxController.GetStickButtonReleased(frc::GenericHID::kLeftHand));
        //Right Stick Button
        setButtonRightStickState(XBoxController.GetStickButton(frc::GenericHID::kRightHand));
        setButtonRightStickPressed(XBoxController.GetStickButtonPressed(frc::GenericHID::kRightHand));
        setButtonRightStickReleased(XBoxController.GetStickButtonReleased(frc::GenericHID::kRightHand));

        //Back and Start button
        //Back Button
        setButtonBackState(XBoxController.GetBackButton());
        setButtonBackPressed(XBoxController.GetBackButtonPressed());
        setButtonBackReleased(XBoxController.GetBackButtonReleased());
        //Start Button
        setButtonStartState(XBoxController.GetStartButton());
        setButtonStartPressed(XBoxController.GetStartButtonPressed());
        setButtonStartReleased(XBoxController.GetStartButtonReleased());
    }
}
