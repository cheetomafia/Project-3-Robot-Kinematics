#ifndef DIFFERENTIALDRIVEROBOT_H__
#define DIFFERENTIALDRIVEROBOT_H__
#include <iostream>
#include <memory>
#include "MobileRobot.h"
// done

class DifferentialDriveRobot : public MobileRobot
{

public:
  DifferentialDriveRobot(double r, double d); //constructor
  void setRightWheelVelocity(double v);
  void setLeftWheelVelocity(double v);
  double getVel() const override;
  double getVx() const override;
  double getVy() const override;
  double getRotVel() const override;
  void print() const override;

private:
  Wheel leftWheel;
  Wheel rightWheel;
  double wheelRadius;
  double wheelDistance;
  static const std::string MODEL_NAME;

};
#endif
