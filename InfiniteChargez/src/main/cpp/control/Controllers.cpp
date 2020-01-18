#include "ControllerDef.h"
#include <frc/XboxController.h>
namespace control
{
    const int controllerPort{0};
    frc::XboxController leController{controllerPort}; //Make this configurable outside
}