#include "poly.h"

Poly ::Poly(int Num, float *x, float *y, int ID) {
  this->id = ID;
  this->num = Num;
  points = (Point *)malloc(num * sizeof(Point));
  pointscopy = (Point *)malloc(num * sizeof(Point));
  for (int i = 0; i < Num; i++) {
    points[i].x = x[i];
    points[i].y = y[i];
    pointscopy[i].x = x[i];
    pointscopy[i].y = y[i];
  }
}
Poly ::PolyOne(int Num, float *x, float *y, int ID) {
  this->id = ID;
  this->num = Num;
  points = (Point *)malloc(num * sizeof(Point));
  pointscopy = (Point *)malloc(num * sizeof(Point));
  for (int i = 0; i < Num; i++) {
    points[i].x = x[i];
    points[i].y = y[i];
    pointscopy[i].x = x[i];
    pointscopy[i].y = y[i];
  }
}

void Poly ::drawObj(HDC hDC, HPEN hPen, int R, int G, int B, int size) {
  hPen = CreatePen(PS_SOLID, size, RGB(R, G, B));
  SelectObject(hDC, hPen);

  for (int i = 0; i < num - 1; i++) {
    MoveToEx(hDC, points[i].x, points[i].y,
             NULL); //сделать текущими координаты x1, y
    LineTo(hDC, points[i + 1].x, points[i + 1].y);
  }

  MoveToEx(hDC, points[num - 1].x, points[num - 1].y,
           NULL); //сделать текущими координаты x1, y
  LineTo(hDC, points[0].x, points[0].y);
  // Polyline(hDC, points , num);
  DeleteObject(hPen);
}

void Poly ::move(int radius, float xCntr, float yCntr, float step) {
  int Radius = radius;
  float Step = step;
  /*	if(flag == 1){
          for(int i = 0; i < id; i++) {
                  points[i].x = pointscopy[i].x;
                  points[i].y = pointscopy[i].y;
                          }
          flag = 0;
          }*/
  for (int i = 0; i < id; i++) {
    if (id == 3 && i == 2) {
      Radius *= 2;
      Step *= 2;
    }
    if (points[i].x >= xCntr && points[i].y <= yCntr) {
      if (points[i].x <= xCntr + (Radius / 2) * sqrt(2)) {
        points[i].x = points[i].x + Step;

        points[i].y =
            yCntr - sqrt(pow(Radius, 2) -
                         pow((points[i].x >= xCntr) * (points[i].x - xCntr) +
                                 (points[i].x < xCntr) * (xCntr - points[i].x),
                             2));

      } else {
        points[i].y = points[i].y + Step;
        points[i].x =
            xCntr + sqrt(pow(Radius, 2) -
                         pow((points[i].y >= yCntr) * (points[i].y - yCntr) +
                                 (points[i].y < yCntr) * (yCntr - points[i].y),
                             2));
      }
    } else if (points[i].x >= xCntr && points[i].y >= yCntr) {
      if (points[i].x >= xCntr + (Radius / 2) * sqrt(2)) {

        points[i].y = points[i].y + Step;
        points[i].x =
            xCntr + sqrt(pow(Radius, 2) -
                         pow((points[i].y >= yCntr) * (points[i].y - yCntr) +
                                 (points[i].y < yCntr) * (yCntr - points[i].y),
                             2));

      } else {
        points[i].x = points[i].x - Step;
        points[i].y =
            yCntr + sqrt(pow(Radius, 2) -
                         pow((points[i].x >= xCntr) * (points[i].x - xCntr) +
                                 (points[i].x < xCntr) * (xCntr - points[i].x),
                             2));
      }

    } else if (points[i].x <= xCntr && points[i].y >= yCntr) {
      if (points[i].x >= xCntr - (Radius / 2) * sqrt(2)) {
        points[i].x = points[i].x - Step;

        points[i].y =
            yCntr + sqrt(pow(Radius, 2) -
                         pow((points[i].x >= xCntr) * (points[i].x - xCntr) +
                                 (points[i].x < xCntr) * (xCntr - points[i].x),
                             2));

      } else {
        points[i].y = points[i].y - Step;
        points[i].x =
            xCntr - sqrt(pow(Radius, 2) -
                         pow((points[i].y >= yCntr) * (points[i].y - yCntr) +
                                 (points[i].y < yCntr) * (yCntr - points[i].y),
                             2));
      }
    } else if (points[i].x <= xCntr && points[i].y <= yCntr) {
      if (points[i].x <= xCntr - (Radius / 2) * sqrt(2)) {

        points[i].y = points[i].y - Step;
        points[i].x =
            xCntr - sqrt(pow(Radius, 2) -
                         pow((points[i].y >= yCntr) * (points[i].y - yCntr) +
                                 (points[i].y < yCntr) * (yCntr - points[i].y),
                             2));

      } else {
        points[i].x = points[i].x + Step;
        points[i].y =
            yCntr - sqrt(pow(Radius, 2) -
                         pow((points[i].x >= xCntr) * (points[i].x - xCntr) +
                                 (points[i].x < xCntr) * (xCntr - points[i].x),
                             2));
      }
    }
  }

  /*		if (points[2].x + 0.1 > pointscopy[2].x && points[2].x - 0.1 <
     pointscopy[2].x|| points[2].y + 0.1 > pointscopy[2].y && points[2].y - 0.1
     < pointscopy[2].y )	{ flag = 1;
                  }			*/
}

void Poly ::keyMove(int vect) {

  switch (vect) {
  case 0: {
    for (int i = 0; i < id; i++) {
      points[i].y -= stepp;
      pointscopy[i].y -= stepp;
    }
    break;
  }
  case 1: {
    for (int i = 0; i < id; i++) {
      points[i].x += stepp;
      pointscopy[i].x += stepp;
    }
    break;
  }
  case 2: {
    for (int i = 0; i < id; i++) {
      points[i].y += stepp;
      pointscopy[i].y += stepp;
    }
    break;
  }
  case 3: {
    for (int i = 0; i < id; i++) {
      points[i].x -= stepp;
      pointscopy[i].x -= stepp;
    }
    break;
  }
  }
}
