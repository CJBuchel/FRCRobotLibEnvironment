#include "Robot.h"

using namespace frc;
using namespace wml;

#include "Robot.h"

using namespace frc;
using namespace wml;

void Robot::RobotInit() {}

void Robot::RobotPeriodic() {}

void Robot::DisabledInit() {
  InterruptAll(true);
}

// Code called once when auto starts
void Robot::AutonomousInit() {}

// Auto loops
void Robot::AutonomousPeriodic() {}

// Start of teleop
void Robot::TeleopInit() {}

// Teleop Loops
void Robot::TeleopPeriodic() {}


// Start of test
void Robot::TestInit() {}

// Test loops
void Robot::TestPeriodic() {}