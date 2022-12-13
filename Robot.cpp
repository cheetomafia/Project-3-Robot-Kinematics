#include "Robot.h"
#include <iostream>

Robot::~Robot(){}
void Robot::print(void) const { //print robot status, called down the inheritance chain
  std::cout << "--------------------------------------\n";
  std::cout << "Robot State\n";
  std::cout <<"--------------------------------------\n";
  std::cout << "Model: " << Robot::model << std::endl;
  std::cout << "--------------------------------------\n";
}
