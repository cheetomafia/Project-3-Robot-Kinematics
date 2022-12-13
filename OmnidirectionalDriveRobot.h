#ifndef OMNIDIRECTIONALDRIVEROBOT_H__
#define OMNIDIRECTIONALDRIVEROBOT_H__
#include "MobileRobot.h"
#include <iostream>
// done
class OmnidirectionalDriveRobot : public MobileRobot
{
public:
OmnidirectionalDriveRobot(double r, double d, double e);
double getVel() const override;
double getVx() const override;
double getVy() const override;
double getRotVel() const override;
void print() const override;
void setFrontLeftWheelVelocity (double vel);
void setFrontRightWheelVelocity (double vel);
void setBackLeftWheelVelocity(double vel);
void setBackRightWheelVelocity(double vel);

private:
Wheel frontLeftWheel;
Wheel frontRightWheel;
Wheel backLeftWheel;
Wheel backRightWheel;
double wheelRadius;
double wheelDistanceLR;
double wheelDistanceFB;
static const std::string MODEL_NAME;
};

#endif
