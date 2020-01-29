#include "Robot.h"
#include <algorithm>
#include <iostream>
#include <math.h>

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
        const double JoystickLeftX{leController.GetX(frc::GenericHID::JoystickHand::kLeftHand)};
        const double JoystickLeftY{leController.GetY(frc::GenericHID::JoystickHand::kLeftHand)};

        const double JoystickRightX{leController.GetX(frc::GenericHID::JoystickHand::kRightHand)};
        const double JoystickRightY{leController.GetY(frc::GenericHID::JoystickHand::kRightHand)};


        if(tankMode)
        {
            driveMotorsRight.Set(JoystickRightY);
            driveMotorsLeft.Set(JoystickLeftY);
        }
        else 
        {
            driveMotorsRight.Set(-std::clamp(JoystickLeftY - JoystickLeftX, -1.0, 1.0));
            driveMotorsLeft.Set(std::clamp(JoystickLeftY + JoystickLeftX, -1.0, 1.0));//FIGURE OUT WHY A NEGATIVE IS NEEDED!!!!
        }
            /*driverMain.ArcadeDrive(
            leController.GetY(frc::GenericHID::JoystickHand::kLeftHand),
            leController.GetX(frc::GenericHID::JoystickHand::kLeftHand));
            */
    }