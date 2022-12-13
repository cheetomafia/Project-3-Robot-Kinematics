#include <iostream>
using namespace std;
#include "MobileRobot.h"
#include <memory>
#include <set>
#include <iomanip>      // std::setprecision
MobileRobot::MobileRobot(std::string model) : Robot(model) {}

MobileRobot::~MobileRobot(){} //deconstructor

void MobileRobot::addWheel(std::shared_ptr<Wheel> wheel) { //add wheel function to create noe wheel classes
  wheels.insert(wheel);
}

void MobileRobot::print(void) const { //print function
  Robot::print(); //calls robot print
  cout.precision(2);
  cout << "--------------------------------------\n";
  cout << "Mobile Robot State\n";
  cout << "--------------------------------------\n";
  cout << "Linear Velocity: "  << std::fixed << this->getVel() << " m/s" << endl;
  cout << "Rotational Velocity: " << std::fixed << this->getRotVel() << " rad/s" << endl;
  cout << "Vx: " << std::fixed << this->getVx() << " m/s" << endl;
  cout << "Vy: " << std::fixed << this->getVy() << " m/s" << endl;
  cout << "--------------------------------------\n";
  cout << "Wheel States\n";
  
  
  /*
  for(int i = 0; i < wheels.size(); i++){

  }*/
  // cout << Wheel::print() << endl; //needs to iterate through each wheel
}
