
#include "snake.h"

extern int rungame;

void Screen :: draw(HDC hDC)
{
	this->ky = 0;
	this->kx = 0;
	HPEN hPen = CreatePen(PS_SOLID, 2,RGB(255,255,0));
    SelectObject(hDC, hPen);
  
    for (int i = 0; i < this->sizex; i+=25) {
	  MoveToEx(hDC, i, 0, NULL); //сделать текущими координаты x1, y
	  LineTo(hDC, i, this->sizey);	
	  kx++;
    }
    for (int i = 0; i < this->sizey; i+=25) {
	  MoveToEx(hDC, 0, i, NULL); //сделать текущими координаты x1, y
	  LineTo(hDC, this->sizey, i);	
	  ky++;
    }
  	DeleteObject(hPen);
}
Screen :: ~Screen(){};

Snake :: Snake(int xhead, int yhead) : Screen(SIZEX,SIZEY) {
	this->len = 9;
	this->coords = (coord*)malloc(sizeof(coord) * this->len);
	for (int i = 0; i < len; i++) {
		this->coords[i].x = xhead - i;
		this->coords[i].y = yhead;
	}
	this->vector = 0;
	this->move1 = 1;
}

void Snake::draw(HDC hDC)
{
	HPEN hPen = CreatePen(PS_SOLID, 2,RGB(0,255,0));
	HPEN hPenhead = CreatePen(PS_SOLID, 2,RGB(0,0,255));
    SelectObject(hDC, hPenhead);
  
    for (int i = 0; i < this->len; i++) {
      if (i > 0) SelectObject(hDC, hPen);
	  MoveToEx(hDC, this->coords[i].x * 25, this->coords[i].y * 25, NULL); //сделать текущими координаты x1, y
	  LineTo(hDC, this->coords[i].x * 25 + 25, this->coords[i].y * 25 + 25);	// /
	  
	  MoveToEx(hDC, this->coords[i].x * 25 + 25, this->coords[i].y * 25 , NULL); //сделать текущими координаты x1, y
	  LineTo(hDC, this->coords[i].x * 25, this->coords[i].y * 25 + 25);	// \
	  
	  
	  MoveToEx(hDC, this->coords[i].x * 25 + 12, this->coords[i].y * 25, NULL); //сделать текущими координаты x1, y
	  LineTo(hDC, this->coords[i].x * 25 + 12, this->coords[i].y * 25 + 25);	// |
	  
	  MoveToEx(hDC, this->coords[i].x * 25, this->coords[i].y * 25 + 12, NULL); //сделать текущими координаты x1, y
	  LineTo(hDC, this->coords[i].x * 25 + 25, this->coords[i].y * 25 + 12);	// -
    }	
  	DeleteObject(hPen);
    if (this->move1 == 0) {
      SelectObject(hDC, hPenhead);
	  MoveToEx(hDC, this->coords[0].x * 25, this->coords[0].y * 25, NULL); //сделать текущими координаты x1, y
	  LineTo(hDC, this->coords[0].x * 25 + 25, this->coords[0].y * 25 + 25);	// /
	  
	  MoveToEx(hDC, this->coords[0].x * 25 + 25, this->coords[0].y * 25 , NULL); //сделать текущими координаты x1, y
	  LineTo(hDC, this->coords[0].x * 25, this->coords[0].y * 25 + 25);	// \
	  
	  
	  MoveToEx(hDC, this->coords[0].x * 25 + 12, this->coords[0].y * 25, NULL); //сделать текущими координаты x1, y
	  LineTo(hDC, this->coords[0].x * 25 + 12, this->coords[0].y * 25 + 25);	// |
	  
	  MoveToEx(hDC, this->coords[0].x * 25, this->coords[0].y * 25 + 12, NULL); //сделать текущими координаты x1, y
	  LineTo(hDC, this->coords[0].x * 25 + 25, this->coords[0].y * 25 + 12);	// -
	  
	  MessageBox(NULL, "You Dead", "Fail", MB_OK);
	  rungame = 0;
	}
  	DeleteObject(hPenhead);
    
}

void Snake::move(){
  if (this->move1) {
	for (int i = this->len - 1; i > 0; i--){
		this->coords[i].x = this->coords[i - 1].x;
		this->coords[i].y = this->coords[i - 1].y;
	}
	switch(this->vector){
  		case 3:{  	
  		this->coords[0].x -= 1;
    	};
		break;
			
  		case 0:{    
		this->coords[0].y -= 1;
	    };
		break;
		
  		case 1:{  		
		this->coords[0].x += 1;
		};
		break;
			
  		case 2:{	
		this->coords[0].y += 1;
		};
		break;
	};	
	for (int i = this->len - 1; i > 2; i--) {
		if (this->coords[i].x == this->coords[0].x &&
		this->coords[i].y == this->coords[0].y ){
		move1 = 0;
		break;
		} 
	}
  }
}

void Snake::setVector(int vec){
	if (vec == 3 && vector == 1) {
		return;
	} else 
	if (vec == 1 && vector == 3) {
		return;
	} else 
	if (vec == 0 && vector == 2) {
		return;
	} else 
	if (vec == 2 && vector == 0) {
		return;
	} else 
  	  this->vector = vec;
}

Snake::~Snake(){
	free(this->coords);
}
