#ifndef YEET_UTILITIES_H
#define YEET_UTILITIES_H
#include <utility>
#include "Pair2D.h"
#include <units/units.h>
#include <chrono>
namespace utilities
{
    Pair2D<double> squarify(double x, double y);
    units::meter_t simpleAccelToPos(units::meters_per_second_squared_t accel, std::chrono::duration<double> delta);
}
#endif