/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/
#ifndef YEET_LE_MOST_AMAZING_ROBOT_IN_THE_WORLD
#define YEET_LE_MOST_AMAZING_ROBOT_IN_THE_WORLD
 #pragma once

#include "ControlCheckExec.h"

#include <string>

#include <frc/SpeedControllerGroup.h>
#include <frc/PWMVictorSPX.h>
#include <frc/TimedRobot.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <frc/XboxController.h>
#include <frc/drive/DifferentialDrive.h>

class Robot : public frc::TimedRobot 
{
  //Configuration constants will go here until a configuration system can be set up
  using driveMotor_t = frc::PWMVictorSPX;
  using intakeMotor_t = frc::PWMVictorSPX;
  using storageMotor_t = frc::PWMVictorSPX;
  using hookMotor_t = frc::PWMVictorSPX;

  using controller_t = frc::XboxController;
  using driver_t = frc::DifferentialDrive;
  private:
   static constexpr double intakeSpeed{1};
   static constexpr double speedMultiplier{1};
   static constexpr double rotationMultiplier{1};
  //Ports for Motors and Controllers
 private:
     static constexpr int controllerPort{0};

     static constexpr int portDriveFrontLeft{1};
     static constexpr int portDriveFrontRight{3};
     static constexpr int portDriveBackLeft{2};
     static constexpr int portDriveBackRight{4};
     static constexpr int portIntakeLeft{5};
     static constexpr int portIntakeRight{6};
     static constexpr int portStorage{7};
     static constexpr int portHook{8};


 public:
  void RobotInit() override;
  void RobotPeriodic() override;
  void AutonomousInit() override;
  void AutonomousPeriodic() override;
  void TeleopInit() override;
  void TeleopPeriodic() override;
  void TestPeriodic() override;
 private:
     controller_t leController{controllerPort}; //Of epic dankness
  //Declare Motors
     driveMotor_t driveMotorFrontLeft{portDriveFrontLeft};
     driveMotor_t driveMotorFrontRight{portDriveFrontRight};
     driveMotor_t driveMotorBackLeft{portDriveBackLeft};
     driveMotor_t driveMotorBackRight{portDriveBackRight};

     intakeMotor_t intakeMotorLeft{portIntakeLeft};
     intakeMotor_t intakeMotorRight{portIntakeRight};

     storageMotor_t storageMotor{portStorage};

     hookMotor_t hookMotor{portHook};
  //Declare Motor Groups
    frc::SpeedControllerGroup driveMotorsLeft{driveMotorFrontLeft, driveMotorBackLeft};
    frc::SpeedControllerGroup driveMotorsRight{driveMotorFrontRight, driveMotorBackRight};
    driver_t driverMain{driveMotorsLeft, driveMotorsRight};
    //Input checking funcitons
    void checkAndExec();
    void joystickPosition();
    void buttonA();
    void buttonB();
    void buttonX();
    void buttonY();
    void bumper();  
    //Movement Functions
    void intakeIn();
    void intakeOut();
    void intakeStop();
  //Control handling nested class
  //Declare Controllers
  frc::SendableChooser<std::string> m_chooser;
  const std::string kAutoNameDefault = "Yeeter McYeeterson";
  const std::string kAutoNameCustom = "Yeeter McYeeterson";
  std::string m_autoSelected;
};

#endif