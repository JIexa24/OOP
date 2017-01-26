9*#include "rect.h"

void Rect :: drawObj(HDC hDC, HPEN hPen, int R, int G, int B,int size){
	hPen = CreatePen(PS_SOLID, size,RGB(R,G,B));
  SelectObject(hDC, hPen);
  Rectangle(hDC,a.x,a.y,b.x,b.y); 
				DeleteObject(hPen);
}

 void Rect :: keyMove(int vect){
	  	
switch(vect){
  case 0:{
		a.y -=1;
		b.y -=1;
		break;
	}	
	case 1:{
		a.x +=1;
		b.x +=1;
		break;
	}
	case 2:{
		a.y +=1;
		b.y +=1;
		break;
	}
	case 3:{
		a.x -=1;
		b.x -=1;
		break;
	}
		}
	}
	void Rect :: move(int radius, float xCntr, float yCntr,float step){

	}
		//~Line();
