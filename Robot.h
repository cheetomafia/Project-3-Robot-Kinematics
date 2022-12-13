#ifndef ROBOT_H__
#define ROBOT_H__
#include <iostream>

class Robot {
public:
  Robot(std::string model) : model(model) {}
  virtual ~Robot();
  virtual void print() const = 0;

protected:
  std::string model;
};
#endif
