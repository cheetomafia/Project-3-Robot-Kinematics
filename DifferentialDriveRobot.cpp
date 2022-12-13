#include "DifferentialDriveRobot.h"
#include <iostream>
#include <math.h>
#include <iomanip>      // std::setprecision
using namespace std;

DifferentialDriveRobot::DifferentialDriveRobot(double r, double d)
    : wheelRadius(r), wheelDistance(d), MobileRobot(DifferentialDriveRobot::MODEL_NAME), leftWheel("Left",r, 0, d/2), rightWheel("Right",r, 0, -d/2) {} //constructor asking for wheel stats and creating wheels

double DifferentialDriveRobot::getRotVel(void) const { //calculate rotational velocity
  double LWv = leftWheel.getVelocity();
  double RWv = rightWheel.getVelocity();
  return ((2 * M_PI * wheelRadius) / wheelDistance * (RWv - LWv));
}

double DifferentialDriveRobot::getVel(void) const { //calculate normal velocity
  double LWv = leftWheel.getVelocity();
  double RWv = rightWheel.getVelocity();
  return (M_PI * wheelRadius * (LWv + RWv));
}

double DifferentialDriveRobot::getVx(void) const { //obtain x velocity
  return (getVel() * cos(getRotVel()));
}

double DifferentialDriveRobot::getVy(void) const { //obtain y velocity
  return (getVel() * sin(getRotVel()));
}

void DifferentialDriveRobot::print(void) const { //print robot status
  MobileRobot::print(); //call mobile robot print
  cout.precision(1);
  cout << "--------------------------------------\n";
  leftWheel.print(); //print out wheels
  rightWheel.print();
  cout << "--------------------------------------\n";
  cout << "DifferentialDrive Robot State\n";
  cout << "--------------------------------------\n";
  cout << "Wheel Radius: " << std::fixed << wheelRadius << endl; //print out wheel stats
  cout << "Wheel Distance Left-Right: " << std::fixed << wheelDistance << endl;
  cout << "--------------------------------------\n";
  
}

void DifferentialDriveRobot::setLeftWheelVelocity(double v) {
  leftWheel.setVelocity(v); //set velocity
}

void DifferentialDriveRobot::setRightWheelVelocity(double v) {
  rightWheel.setVelocity(v); //set velocity
}

const std::string DifferentialDriveRobot::MODEL_NAME = "DifferentialDrive"; //global variable for name
