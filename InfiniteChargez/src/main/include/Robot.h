/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/
#ifndef YEET_LE_MOST_AMAZING_ROBOT_IN_THE_WORLD
#define YEET_LE_MOST_AMAZING_ROBOT_IN_THE_WORLD
 #pragma once

#include <string>

#include <frc/PWMVictorSPX.h>
#include <frc/TimedRobot.h>
#include <frc/smartdashboard/SendableChooser.h>

class Robot : public frc::TimedRobot 
{
  //Configuration constants will go here until a configuration system can be set up
  using driveMotor_t = frc::PWMVictorSPX;
  using intakeMotor_t = frc::PWMVictorSPX;
  using storageMotor_t = frc::PWMVictorSPX;
  using hookMotor_t = frc::PWMVictorSPX;

  //Ports for Motors and Controllers
 private:
    static constexpr int portDriveLeft{0};
    static constexpr int portDriveRight{1};
    static constexpr int portIntakeLeft{2};
    static constexpr int portIntakeRight{3};
    static constexpr int portStorage{4};
    static constexpr int portHook{5};


 public:
  void RobotInit() override;
  void RobotPeriodic() override;
  void AutonomousInit() override;
  void AutonomousPeriodic() override;
  void TeleopInit() override;
  void TeleopPeriodic() override;
  void TestPeriodic() override;

 private:
  //Declare Motors
    static driveMotor_t driveMotorLeft;
    static driveMotor_t driveMotorRight;

    static intakeMotor_t intakeMotorLeft;
    static intakeMotor_t intakeMotorRight;

    static storageMotor_t storageMotor;

    static hookMotor_t hookMotor;

  //Declare Controllers
  frc::SendableChooser<std::string> m_chooser;
  const std::string kAutoNameDefault = "Yeeter McYeeterson";
  const std::string kAutoNameCustom = "Yeeter McYeeterson";
  std::string m_autoSelected;
};

#endif