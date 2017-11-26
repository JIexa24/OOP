#ifndef FIGUR_H_
#define FIGUR_H_

#include <iostream>

 class Figure{
	public:
		 //Figure(void);
		 virtual void drawObj(HDC hDC,HPEN hPen, int R, int G, int B, int size) = 0;
	   virtual void move(int radius, float xCntr, float yCntr,float step) = 0;
	   virtual void keyMove(int vect) = 0;
};

#endif
