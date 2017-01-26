#ifndef RECT_H_
#define RECT_H_

#include "line.h"

class Rect : public Line {
	public:
		Rect(Point one,	Point two) : Line(one,	two){};
		void drawObj(HDC hDC,HPEN hPen, int R, int G, int B, int size);
	  void move(int radius, float xCntr, float yCntr,float step);
	  void keyMove(int vect);
		//~Line();
};

#endif
