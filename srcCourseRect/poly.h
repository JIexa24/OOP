#ifndef POLY_H_
#define POLY_H_

#define stepp 4
#include "figure.h"
#include "line.h"
#include <math.h>
#include <stdlib.h>
class Poly : public Figure {
private:
  int num;
  Point *points;
  Point *pointscopy;

public:
  int flag = 0;
  int id; // 4-rectange, 3 - triangle
  Poly() : points(NULL), pointscopy(NULL){};
  Poly(int Num, float *x, float *y, int ID);
  PolyOne(int Num, float *x, float *y, int ID);
  void drawObj(HDC hDC, HPEN hPen, int R, int G, int B, int size);
  void move(int radius, float xCntr, float yCntr, float step);
  void keyMove(int vect);

  Point getPoint(int i) { return points[i]; }
};

#endif
