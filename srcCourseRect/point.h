#ifndef POINT_H_
#define POINT_H_

#include <conio.h>
#include <iostream>
#include <stdlib.h>
#include <windows.h>

class Point {
public:
  float x;
  float y;

  Point() : x(0), y(0){};
  Point(float x, float y);
  //~Point();
};

#endif
