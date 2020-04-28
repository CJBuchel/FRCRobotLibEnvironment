#include "Robot.h"

using namespace frc;
using namespace wml;

WayFinder::Waypoint wypt1 = {0, 0, 0, 1, -3, 0, false}; // Old Linear Waypoint design
// WayFinderSpline::sSpline path1;
// path1.points = { {0, 0}, {2, -7}, {5, -7}, {5, 7} };

void Robot::RobotInit() {
  drivetrain = new Drivetrain(robotMap.driveSystem.drivetrainConfig, robotMap.driveSystem.gainsVelocity);
  wayFinder = new WayFinder(0.3, 0, 0, *drivetrain, 7, 15.24);
  
}

void Robot::RobotPeriodic() {}

void Robot::DisabledInit() {
  InterruptAll(true);
}

// Code called once when auto starts
void Robot::AutonomousInit() {
  wayFinder->Config(0.4, 0.3);
}

// Auto loops
void Robot::AutonomousPeriodic() {
  if (!wayFinder->GetWaypointComplete()) {
    wayFinder->GotoWaypoint(wypt1, 1);
  }
}

// Start of teleop
void Robot::TeleopInit() {}

// Teleop Loops
void Robot::TeleopPeriodic() {}


// Start of test
void Robot::TestInit() {}

// Test loops
void Robot::TestPeriodic() {}