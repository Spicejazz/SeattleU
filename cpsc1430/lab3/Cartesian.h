#ifndef CARTESIAN_H
#define CARTESIAN_H
#include <math.h>
#include "Polar.h"

class Polar;

class Cartesian
{
public:
  Cartesian(double x, double y);
  Cartesian(const Polar &polar);
  double getX() const;
  double getY() const;
  Cartesian addX(double xToAdd) const;
  Cartesian addY(double yToAdd) const;
private:
  double x;
  double y;
};

#endif
