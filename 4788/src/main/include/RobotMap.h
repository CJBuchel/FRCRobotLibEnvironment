#pragma once

#include <string>
#include <stdint.h>

#include "devices/StateDevice.h"
#include "control/PIDController.h"
#include "strategy/StrategySystem.h"
#include "control/MotorFilters.h"
#include "Gearbox.h"
#include "strategy/Strategy.h"
#include "controllers/Controllers.h"
#include "sensors/BinarySensor.h"

// FRC
#include <frc/SpeedControllerGroup.h>
#include <frc/Spark.h>
#include <frc/PowerDistributionPanel.h>
#include <frc/PWMSparkMax.h>
#include <frc/Servo.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/AnalogInput.h>

#include <frc/Filesystem.h>
#include <frc/trajectory/TrajectoryUtil.h>
#include <wpi/Path.h>
#include <wpi/SmallString.h>

// REV
#include "rev/CANSparkMax.h"

// WML
#include "WMLCtre.h"
#include "controllers/Controllers.h"
#include "actuators/BinaryServo.h"
#include "actuators/Compressor.h"
#include "actuators/DoubleSolenoid.h"
#include "actuators/VoltageController.h"
#include "Drivetrain.h"
#include "sensors/Encoder.h"
#include "sensors/LimitSwitch.h"
#include "sensors/NavX.h"
#include "sensors/PressureSensor.h"
#include <networktables/NetworkTableInstance.h>
#include "control/PIDController.h"
#include "MotionProfiling.h"
#include "Toggle.h"
#include "WMLRev.h"

#include "Usage.h"

struct RobotMap {
  struct DriveSystem {
    wml::TalonSrx LMotor{ 0, 2048 };
    wml::TalonSrx RMotor{ 1, 2048 };

    wml::actuators::MotorVoltageController leftMotors = wml::actuators::MotorVoltageController::Group(LMotor);
    wml::actuators::MotorVoltageController rightMotors = wml::actuators::MotorVoltageController::Group(RMotor);

    wml::Gearbox LGearbox{ &leftMotors, &LMotor, 0 };
    wml::Gearbox RGearbox{ &rightMotors, &RMotor, 0 };

    wml::sensors::NavX navX{};
    wml::sensors::NavXGyro gyro{ navX.Angular(wml::sensors::AngularAxis::YAW) };

    wml::DrivetrainConfig drivetrainConfig{ LGearbox, RGearbox, &gyro, 0.56, 0.60, 0.0762, 50 };
    wml::Drivetrain drivetrain{ drivetrainConfig };
    wml::control::PIDGains gainsVelocity{ "Drivetrain Velocity", 1 };
  }; DriveSystem driveSystem;
};