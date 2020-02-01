#include <hal/HAL.h>
#include <iostream>
#include "Robot.h"

#include "gtest/gtest.h"

int main(int argc, char** argv) {
  HAL_Initialize(500, 0);
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  Robot robo;
  robo.TeleopPeriodic();
  std::cout << "Reee";
  return ret;
}
