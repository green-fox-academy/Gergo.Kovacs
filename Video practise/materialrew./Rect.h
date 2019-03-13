//
// Created by Kovacs család on 2019-02-06.
//

#ifndef MATERIALREW_RECT_H
#define MATERIALREW_RECT_H
#include "shape.h"
class Rect: public Shape
{
  int width;
  int height;
  double circumference(){
      return (2*width+2*height);
  }
  double area(){
      return width*height;
  }
};

#endif //MATERIALREW_RECT_H
