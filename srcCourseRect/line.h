#ifndef LINE_H_
#define LINE_H_

#include "figure.h"
#include "point.h"

class Line : public Figure {
public:
  // Line() : a(Point(0,0)), b(Point(0,0)) {};
  Line(Point one, Point two) : a(one), b(two){};
  virtual void drawObj(HDC hDC, HPEN hPen, int R, int G, int B, int size);
  void setPoints(Point one, Point two);
  virtual void move(int radius, float xCntr, float yCntr, float step);
  virtual void keyMove(int vect);
  //~Line();
  Point a;
  Point b;
};

#endif
