#include "Robot.h"

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
            driverMain.ArcadeDrive(
            leController.GetX(frc::GenericHID::JoystickHand::kLeftHand),
            leController.GetY(frc::GenericHID::JoystickHand::kRightHand));
    }