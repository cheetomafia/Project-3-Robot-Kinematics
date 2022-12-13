#include "OmnidirectionalDriveRobot.h"
#include <iostream>
#include <math.h>
#include <cmath>
using namespace std;

OmnidirectionalDriveRobot::OmnidirectionalDriveRobot(double r, double d, double e) 
  :  wheelRadius(r), wheelDistanceLR(d), wheelDistanceFB(e), MobileRobot(OmnidirectionalDriveRobot::MODEL_NAME), frontLeftWheel("Front Left",r,d/2,e/2), frontRightWheel("Front Right",r, d/2,-e/2), backLeftWheel("Back Left",r,-d/2,e/2), backRightWheel("Back Right",r,-d/2,-e/2) { //default constructor sets each wheel
    
    
  }

double OmnidirectionalDriveRobot::getRotVel(void) const { //obtain rotational velocity
  double FLv = frontLeftWheel.getVelocity();
  double FRv = frontRightWheel.getVelocity();
  double BLv = backLeftWheel.getVelocity();
  double BRv = backRightWheel.getVelocity();
  return (((M_PI * wheelRadius)/(wheelDistanceLR + wheelDistanceFB))*(-FLv + FRv + -BLv + BRv));
}

double OmnidirectionalDriveRobot::getVel(void) const { //obtain velocity
  double Vx = getVx();
  double Vy = getVy();
  double angle = atan2(Vx, -Vy);
  if((angle> M_PI)&&(angle<2*M_PI)||(angle<0)&&(angle > -M_PI)){
  return (-(sqrt((Vx*Vx)+(Vy*Vy))));
    }
  else{
  return ((sqrt((Vx*Vx)+(Vy*Vy))));
  }
}

double OmnidirectionalDriveRobot::getVx(void) const { //obtain x velocity
  double FLv = frontLeftWheel.getVelocity();
  double FRv = frontRightWheel.getVelocity();
  double BLv = backLeftWheel.getVelocity();
  double BRv = backRightWheel.getVelocity();
  return (((M_PI*wheelRadius)/2)*(FLv + FRv + BLv + BRv));
}

double OmnidirectionalDriveRobot::getVy(void) const { //obtain y velocity
  double FLv = frontLeftWheel.getVelocity();
  double FRv = frontRightWheel.getVelocity();
  double BLv = backLeftWheel.getVelocity();
  double BRv = backRightWheel.getVelocity();
  return (((M_PI*wheelRadius)/2)*(-FLv + FRv + BLv - BRv));
}

void OmnidirectionalDriveRobot::print(void) const {
  MobileRobot::print(); //call mobile robot print
  cout.precision(1);
  cout << "--------------------------------------\n";
  frontLeftWheel.print(); //print each wheel status
  frontRightWheel.print();
  backLeftWheel.print();
  backRightWheel.print();
  cout << "--------------------------------------\n";
  cout << "Omnidirectional Drive Robot State\n";
  cout << "--------------------------------------\n";
  cout << "Wheel Radius: " << std::fixed << wheelRadius <<endl;
  cout << "Wheel Distance Left-Right: " << std::fixed << wheelDistanceLR << endl;
  cout << "Wheel Distance Front-Back: " << std::fixed << wheelDistanceFB << endl;
  cout << "--------------------------------------\n";
}

void OmnidirectionalDriveRobot::setBackLeftWheelVelocity(double vel) { //set each wheels velocity
  OmnidirectionalDriveRobot::backLeftWheel.setVelocity(vel);
}

void OmnidirectionalDriveRobot::setBackRightWheelVelocity(double vel) {
  OmnidirectionalDriveRobot::backRightWheel.setVelocity(vel);
}

void OmnidirectionalDriveRobot::setFrontLeftWheelVelocity(double vel) {
  OmnidirectionalDriveRobot::frontLeftWheel.setVelocity(vel);
}

void OmnidirectionalDriveRobot::setFrontRightWheelVelocity(double vel) {
  OmnidirectionalDriveRobot::frontRightWheel.setVelocity(vel);
}
const std::string OmnidirectionalDriveRobot::MODEL_NAME = "Omnidirectional Drive";
