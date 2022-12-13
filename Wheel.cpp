#include "Wheel.h"
#include <iostream>
#include <iomanip>      // std::setprecision
using namespace std;

Wheel::Wheel(string name, double r, double x, double y)
  {
      setName(name);
      setX(x);
      setY(y);
      setR(r);
    } //default constructor

void Wheel::print(void) const { //wheel print, called in omni and differential robot
  cout.precision(2);
  cout << "Name: " << name << endl;
  cout << "Position: (" << std::fixed << getX() << " m, " << getY() << " m) "  << endl;
  cout << "Velocity: " << std::fixed << getVelocity() << " rev/s" << endl;
  cout << "--------------------------------------\n";
}
void Wheel::setName(string name){
  this->name = name; //set wheel name
}

void Wheel::setX(double x){
  this->x = x; //set x position
}

void Wheel::setY(double y){
  this->y = y; //set y position
}

void Wheel::setR(double r){
  this->radius = r; //set wheel radius
}
