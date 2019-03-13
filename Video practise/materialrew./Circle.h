#ifndef MATERIALREW_CIRCLE_H
#define MATERIALREW_CIRCLE_H
#include "Shape.h"


class Circle: public Shape{

  int radius;
 public:

  double circumference();
  double area();

};

#endif //MATERIALREW_CIRCLE_H
