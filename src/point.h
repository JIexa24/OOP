#ifndef POINT_H_
#define POINT_H_

#include <windows.h>
#include <iostream>
#include <stdlib.h>
#include <conio.h>

class Point {
	public:
		float x;
		float y;
		
		Point() : x(0),y(0) {};
		Point(float x, float y);
		//~Point();
};

#endif
