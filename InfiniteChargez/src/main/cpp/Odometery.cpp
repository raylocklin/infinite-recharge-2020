#include "Robot.h"
#include <chrono>
#include <Pair2D.h>
#include <units/units.h>

void Robot::updatePos(duration_t delta)
{
    using gravAccel_t = units::standard_gravity_t;
    //RoboRio is facing backwards, must negate
    utilities::Pair2D<gravAccel_t> acceleration{gravAccel_t{-leAccelerometer.GetX()}, gravAccel_t{-leAccelerometer.GetY()}};
}
