#include "Robot.h"
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
            std::cout << leController.GetX(frc::GenericHID::JoystickHand::kLeftHand) << '\n';
            driverMain.ArcadeDrive(
            speedMultiplier * std::pow(
                leController.GetY(frc::GenericHID::JoystickHand::kLeftHand), speedCurvePower),
            rotationMultiplier * std::pow(
                leController.GetX(frc::GenericHID::JoystickHand::kLeftHand), rotationCurvePower));
    }