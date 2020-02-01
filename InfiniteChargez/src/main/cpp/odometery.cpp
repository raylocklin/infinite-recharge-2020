#include "Robot.h"
#include <chrono>

void Robot::updatePos(duration_t delta)
{
    std::cout << delta.count();
    std::cout << "reeee";
}
