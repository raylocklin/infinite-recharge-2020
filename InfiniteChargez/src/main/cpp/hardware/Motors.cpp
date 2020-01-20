#include "MotorDef.h"
#include "frc/PWMVictorSPX.h"
namespace hardware
{
    
    /*The integer passed into the motors' constructor
    corresponds to the port to which they were plugged into
    the RoboRio*/
    
    driveMotor_t driveMotorLeft{portDriveLeft};
    driveMotor_t driveMotorRight{portDriveRight};

    intakeMotor_t intakeMotorLeft{portIntakeLeft};
    intakeMotor_t intakeMotorRight{portIntakeRight};

    storageMotor_t storageMotor{portStorage};

    hookMotor_t hookMotor{portHook};
}