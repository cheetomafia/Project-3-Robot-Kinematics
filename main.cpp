#include "DifferentialDriveRobot.h"
#include "OmnidirectionalDriveRobot.h"
#include <iostream>

using namespace std;

const int ROBOT_TYPE_DIFF = 1;
const int ROBOT_TYPE_OMNI = 2;

const bool SHOW_PROMPTS = false;

int main(void) {
  char newVelocities;
  char newModel;
  
  do {
    int type;
    double radius;

    if (SHOW_PROMPTS) {
      cout << "Select Robot Type: \n";
      cout << "(1) Differential Drive \n";
      cout << "(2) Omnidirectional Drive \n";
      cout << "Enter Selection: ";
    }
    cin >> type;

    switch (type) {
    case ROBOT_TYPE_DIFF: {
      // Query for Diff wheel radius and distances
      double wheelDist;
      if (SHOW_PROMPTS) {
        cout << "Enter Wheel Radius: ";
      }
      cin >> radius;

      if (SHOW_PROMPTS) {
        cout << "Enter Distance Between Wheels: ";
      }
      cin >> wheelDist;

      // Create differential robot
      Robot *robot = (new DifferentialDriveRobot(radius, wheelDist));
      do {
        // Query for the wheel velocities
        double lVel, rVel;
        if (SHOW_PROMPTS) {
          cout << "Enter Left Wheel Velocity (rev/s): ";
        }
        cin >> lVel;
        if (SHOW_PROMPTS) {
          cout << "Enter Right Wheel Velocity (rev/s): ";
        }
        cin >> rVel;

        // Downcast to an Diff robot and set the wheel velocities

        DifferentialDriveRobot *dd_robot = dynamic_cast<DifferentialDriveRobot *>(robot); //downcast
        
        if (dd_robot != nullptr) { //setting wheel velocities
            dd_robot->setLeftWheelVelocity(lVel);
            dd_robot->setRightWheelVelocity(rVel);
        }

        robot->print(); // print out robot status
        
        if (SHOW_PROMPTS) {
          cout << "Try different velocities (y/n)? ";
        }
        cin >> newVelocities;

      } while (newVelocities != 'n');

      delete robot; //clean up memory
     
    break;
      }
    case ROBOT_TYPE_OMNI:

      // Query for Omni wheel radius and distances
      double lrDist;
      double fbDist;

      if (SHOW_PROMPTS) {
        cout << "Enter Wheel Radius: ";
      }
      cin >> radius;

      if (SHOW_PROMPTS) {
        cout << "Enter Distance Between Left-Right Wheels: ";
      }
      cin >> lrDist;

      if (SHOW_PROMPTS) {
        cout << "Enter Distance Between Front-Back Wheels: ";
      }
      cin >> fbDist;

      // Create Omni Robot
      MobileRobot *robot = (new OmnidirectionalDriveRobot(radius, lrDist, fbDist));
      do {
        // Query for the wheel velocities
        double flVel, frVel, blVel, brVel;
        if (SHOW_PROMPTS) {
          cout << "Enter Front Left Wheel Velocity (rev/s): ";
        }
        cin >> flVel;
        if (SHOW_PROMPTS) {
          cout << "Enter Front Right Wheel Velocity (rev/s): ";
        }
        cin >> frVel;
        if (SHOW_PROMPTS) {
          cout << "Enter Back Left Wheel Velocity (rev/s): ";
        }
        cin >> blVel;
        if (SHOW_PROMPTS) {
          cout << "Enter Back Right Wheel Velocity (rev/s): ";
        }
        cin >> brVel;

        // Downcast to an Omni robot and set the wheel velocities

        OmnidirectionalDriveRobot *omni_robot = dynamic_cast<OmnidirectionalDriveRobot *>(robot); //downcast
        
        omni_robot->setBackLeftWheelVelocity(blVel); //set velocity
        omni_robot->setBackRightWheelVelocity(brVel);
        omni_robot->setFrontLeftWheelVelocity(flVel);
        omni_robot->setFrontRightWheelVelocity(frVel);

        // Use generic robot print
        robot->print();

        if (SHOW_PROMPTS) {
          cout << "Try different velocities (y/n)? ";
        }
        cin >> newVelocities;
      } while (newVelocities != 'n');

      delete robot; //clean memory
      
      break;
    }
    if (SHOW_PROMPTS) {
      cout << "Try different model (y/n)? ";
    }
    cin >> newModel;

  } while (newModel != 'n');

  //Delete Robot
  
  return 0;
}
