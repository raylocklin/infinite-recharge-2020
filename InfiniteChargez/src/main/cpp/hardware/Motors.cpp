#include "MotorDef.h"
#include "frc/PWMVictorSPX.h"
namespace hardware
{
    
    /*The integer passed into the motors' constructor
    corresponds to the port to which they were plugged into
    the RoboRio*/
    constexpr int portDriveLeft{0};
    constexpr int portDriveRight{1};
    constexpr int portIntakeLeft{2};
    constexpr int portIntakeRight{3};
    constexpr int portStorage{4};
    constexpr int portHook{5};

    driveMotor_t driveMotorLeft{portDriveLeft};
    driveMotor_t driveMotorRight{portDriveRight};

    intakeMotor_t intakeMotorLeft{portIntakeLeft};
    intakeMotor_t intakeMotorRight{portIntakeRight};

    storageMotor_t storageMotor{portStorage};

    hookMotor_t hookMotor{portHook};
}