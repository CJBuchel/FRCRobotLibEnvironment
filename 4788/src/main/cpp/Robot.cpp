#include "Robot.h"

#define USING_WML
#include "WayFinder.h"

using namespace frc;
using namespace wml;

WayFinder::WayFinder *wayFinder; // main wayfinder

WayFinder::Path::sPath spath1; // path1
WayFinder::Path::lPath lpath1; // path2

double gearboxReduction = 7; // 7:1
double wheelDiameter = 15.23; // 15.23 cm

double kp = 0.3, kd = 0.3, ki = 0.3;

double maxSpeed = 0.4, maxTurnSpeed = 0.3;

void Robot::RobotInit() {
  drivetrain = new Drivetrain(robotMap.driveSystem.drivetrainConfig, robotMap.driveSystem.gainsVelocity);
  wayFinder = new WayFinder::WayFinder(*drivetrain, gearboxReduction, wheelDiameter);

  // configure PID and speeds. Or change them mid auto
  wayFinder->autoConfig(kp, ki, kd,  gearboxReduction, wheelDiameter, maxSpeed, maxTurnSpeed);

  spath1.points = { {5,5}, {15,15} };
}

void Robot::RobotPeriodic() {}

void Robot::DisabledInit() {
  InterruptAll(true);
}

// Code called once when auto starts
void Robot::AutonomousInit() {
  // wayFinder->Config(0.4, 0.3);
}

// Auto loops
void Robot::AutonomousPeriodic() {
  // if (!wayFinder->GetWaypointComplete()) {
    // wayFinder->GotoWaypoint(wypt1, 1);
  // }
}

// Start of teleop
void Robot::TeleopInit() {}

// Teleop Loops
void Robot::TeleopPeriodic() {}


// Start of test
void Robot::TestInit() {}

// Test loops
void Robot::TestPeriodic() {}