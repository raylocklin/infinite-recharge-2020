#include "Robot.h"
#include <iostream>

    void Robot::checkAndExec()
    {
        joystickPosition();
        //buttonA();
        //buttonB();
        //buttonX();
        //buttonY();
        //bumper();  
    }
    
    void Robot::joystickPosition()
    {
            driveMotorsRight.Set(-leController.GetY(frc::GenericHID::JoystickHand::kLeftHand));
            driveMotorsLeft.Set(leController.GetY(frc::GenericHID::JoystickHand::kRightHand));
            /*driverMain.ArcadeDrive(
            leController.GetY(frc::GenericHID::JoystickHand::kLeftHand),
            leController.GetX(frc::GenericHID::JoystickHand::kLeftHand));
            */
    }