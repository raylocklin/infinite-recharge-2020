#ifndef YEET_MOTOR_DEFINITION_H
#define YEET_MOTOR_DEFINITION_H
#include <frc/PWMVictorSPX.h>

namespace hardware
{   
    using driveMotor_t = frc::PWMVictorSPX;
    using intakeMotor_t = frc::PWMVictorSPX;
    using storageMotor_t = frc::PWMVictorSPX;
    using hookMotor_t = frc::PWMVictorSPX;

    extern driveMotor_t driveMotorLeft;
    extern driveMotor_t driveMotorRight;

    extern intakeMotor_t intakeMotorLeft;
    extern intakeMotor_t intakeMotorRight;

    extern storageMotor_t storageMotor;

    extern hookMotor_t hookMotor;
    
}
#endif