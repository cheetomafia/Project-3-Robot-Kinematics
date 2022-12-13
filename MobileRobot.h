#ifndef MOBILEROBOT_H__
#define MOBILEROBOT_H__
#include <iostream>
#include <memory>
#include <set>
#include "Robot.h"
#include "Wheel.h"
// done
class MobileRobot : public Robot {

public:
  MobileRobot(std::string model);
  virtual ~MobileRobot();
  virtual double getVel(void) const = 0;
  virtual double getVx(void) const = 0;
  virtual double getVy(void) const = 0;
  virtual double getRotVel(void) const = 0;
  virtual void print(void) const = 0;
  void addWheel(std::shared_ptr<Wheel> wheel);

private:

  std::set<std::shared_ptr<Wheel>> wheels;
};

#endif
