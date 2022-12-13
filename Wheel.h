#ifndef WHEEL_H__ 
#define WHEEL_H__
#include <iostream>
// done
class Wheel {
public:
  Wheel(std::string name, double r, double x, double y);
  inline double getRadius() const { return radius; }
  inline double getVelocity() const { return velocity; }
  inline void setVelocity(double v) { velocity = v; }
  inline void setRadius(double r) { radius = r; }
  void setName(std::string name);
  void setX (double x);
  void setY (double y);
  void setR (double r);
  inline double getX() const { return x; }
  inline double getY() const { return y; }
  inline std::string getName() const { return name; }
  void print() const;

private:
  std::string name;
  double radius, velocity, x, y;
};
#endif
