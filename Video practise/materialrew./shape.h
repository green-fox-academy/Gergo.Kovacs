//
// Created by Kovacs család on 2019-02-06.
//

#ifndef MATERIALREW_SHAPE_H
#define MATERIALREW_SHAPE_H

class Shape
{
 protected:
  int x; // x az egy kordináta pont
  int y;// y az egy kordináta pont
 public:
  Shape
  void move(int dx, int dy);
  virtual double circumference() = 0;
  virtual double area() = 0;

};

#endif //MATERIALREW_SHAPE_H
