#include "line.h"

void Line ::drawObj(HDC hDC, HPEN hPen, int R, int G, int B, int size) {
  hPen = CreatePen(PS_SOLID, size, RGB(R, G, B));
  SelectObject(hDC, hPen);

  MoveToEx(hDC, a.x, a.y, NULL); //сделать текущими координаты x1, y1
  LineTo(hDC, b.x, b.y);
}

void Line ::setPoints(Point one, Point two) {
  a.x = one.x;
  b.x = two.x;
  a.y = one.y;
  b.y = two.y;
}

void Line::keyMove(int vect) {}

void Line::move(int radius, float xCntr, float yCntr, float step) {}
