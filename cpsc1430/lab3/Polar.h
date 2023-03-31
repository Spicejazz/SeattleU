#ifndef POLAR_H
#define POLAR_H
#define _USE_MATH_DEFINES
#include "Cartesian.h"
#include <math.h>

class Cartesian;

class Polar
{
public:
  Polar(double r, double a);
  Polar(const Cartesian &cartesian);
  double getR() const;
  double getA() const;
  double toDegrees() const;
private:
  double r;
  double a;
};

#endif
