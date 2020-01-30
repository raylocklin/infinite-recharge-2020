#include "Robot.h"
#include "Utilities.h"
#include "Pair2D.h"
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
        //Compilar arguments and preprocessor macros can be passed to remove unused
        const double JoystickLeftX{leController.GetX(frc::GenericHID::JoystickHand::kLeftHand)};
        const double JoystickLeftY{leController.GetY(frc::GenericHID::JoystickHand::kLeftHand)};

        const double JoystickRightX{leController.GetX(frc::GenericHID::JoystickHand::kRightHand)};
        const double JoystickRightY{leController.GetY(frc::GenericHID::JoystickHand::kRightHand)};
        
        //Squarified Values
        const Pair2D<double> SquareJoystickLeft{utilities::squarify(JoystickLeftX, JoystickLeftY)};
        const Pair2D<double> SquareJoystickRight{utilities::squarify(JoystickRightX, JoystickRightY)};


        if(tankMode)
        {
            driveMotorsRight.Set(JoystickRightY);
            driveMotorsLeft.Set(JoystickLeftY);
        }
        else 
        {
            driveMotorsRight.Set(-std::clamp(SquareJoystickLeft.y - SquareJoystickLeft.x, -1.0, 1.0));
            driveMotorsLeft.Set(std::clamp(SquareJoystickLeft.y + SquareJoystickLet.x, -1.0, 1.0));//FIGURE OUT WHY A NEGATIVE IS NEEDED!!!!
        }
            /*driverMain.ArcadeDrive(
            leController.GetY(frc::GenericHID::JoystickHand::kLeftHand),
            leController.GetX(frc::GenericHID::JoystickHand::kLeftHand));
            */
    }