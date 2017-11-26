#include "snake.h"
#define STEP 10

extern int rungame;
extern int score;
char dead[100] = "You Dead!\nScore : ";
int getrand(int min, int max)
{
    return rand() % (max - min) + min;
}
Screen::Screen() : sizex(0), sizey(0){}
Screen::Screen(int x, int y):sizex(x),sizey(y){
	this->ky = 0;
	this->kx = 0;
    for (int i = 0; i < this->sizex; i+=STEP) kx++;
    for (int i = 0; i < this->sizey; i+=STEP) ky++;
}

void Screen :: draw(HDC hDC)
{
	HPEN hPen = CreatePen(PS_SOLID, 2,RGB(255,255,0));
    SelectObject(hDC, hPen);
  
    for (int i = 0; i < this->sizex; i+=STEP) {
	  MoveToEx(hDC, i, 0, NULL); //ñäåëàòü òåêóùèìè êîîðäèíàòû x1, y
	  LineTo(hDC, i, this->sizey);	
    }
    for (int i = 0; i < this->sizey; i+=STEP) {
	  MoveToEx(hDC, 0, i, NULL); //ñäåëàòü òåêóùèìè êîîðäèíàòû x1, y
	  LineTo(hDC, this->sizey, i);	
    }
  	DeleteObject(hPen);
}

int Screen :: getkx(){
	return kx;
}

int Screen :: getky(){
	return ky;
}

Screen :: ~Screen(){}

Snake :: Snake(int xhead, int yhead) : Screen(SIZEX,SIZEY) {
	this->len = 9;
	this->coords = (coord*)malloc(sizeof(coord) * this->len);
	for (int i = 0; i < len; i++) {
		this->coords[i].x = xhead - i;
		this->coords[i].y = yhead;
	}
	this->vector = 1;
	this->move1 = 1;
}

void Snake::draw(HDC hDC)
{
	HPEN hPen = CreatePen(PS_SOLID, 2,RGB(0,255,0));
	HPEN hPenhead = CreatePen(PS_SOLID, 2,RGB(0,0,255));
    SelectObject(hDC, hPenhead);
  
    for (int i = 0; i < this->len; i++) {
      if (i > 0) SelectObject(hDC, hPen);
	  MoveToEx(hDC, this->coords[i].x * STEP, this->coords[i].y * STEP, NULL); //ñäåëàòü òåêóùèìè êîîðäèíàòû x1, y
	  LineTo(hDC, this->coords[i].x * STEP + STEP, this->coords[i].y * STEP + STEP);	// /
	  
	  MoveToEx(hDC, this->coords[i].x * STEP + STEP, this->coords[i].y * STEP  , NULL); //ñäåëàòü òåêóùèìè êîîðäèíàòû x1, y
	  LineTo(hDC, this->coords[i].x * STEP, this->coords[i].y * STEP  + STEP);	// \
	  
	  
	  MoveToEx(hDC, this->coords[i].x * STEP + STEP/2, this->coords[i].y * STEP, NULL); //ñäåëàòü òåêóùèìè êîîðäèíàòû x1, y
	  LineTo(hDC, this->coords[i].x * STEP + STEP/2, this->coords[i].y * STEP + STEP);	// |
	  
	  MoveToEx(hDC, this->coords[i].x * STEP, this->coords[i].y * STEP + STEP/2, NULL); //ñäåëàòü òåêóùèìè êîîðäèíàòû x1, y
	  LineTo(hDC, this->coords[i].x * STEP + STEP, this->coords[i].y * STEP + STEP/2);	// -
    }	
  	DeleteObject(hPen);
    if (this->move1 == 0) {
      SelectObject(hDC, hPenhead);
	  MoveToEx(hDC, this->coords[0].x * STEP, this->coords[0].y * STEP, NULL); //ñäåëàòü òåêóùèìè êîîðäèíàòû x1, y
	  LineTo(hDC, this->coords[0].x * STEP + STEP, this->coords[0].y * STEP + STEP);	// /
	  
	  MoveToEx(hDC, this->coords[0].x * STEP + STEP, this->coords[0].y * STEP , NULL); //ñäåëàòü òåêóùèìè êîîðäèíàòû x1, y
	  LineTo(hDC, this->coords[0].x * STEP, this->coords[0].y * STEP + STEP);	// \
	  
	  
	  MoveToEx(hDC, this->coords[0].x * STEP + STEP/2, this->coords[0].y * STEP, NULL); //ñäåëàòü òåêóùèìè êîîðäèíàòû x1, y
	  LineTo(hDC, this->coords[0].x * STEP + STEP/2, this->coords[0].y * STEP + STEP);	// |
	  
	  MoveToEx(hDC, this->coords[0].x * STEP, this->coords[0].y * STEP + STEP/2, NULL); //ñäåëàòü òåêóùèìè êîîðäèíàòû x1, y
	  LineTo(hDC, this->coords[0].x * STEP + STEP, this->coords[0].y * STEP + STEP/2);	// -
	  char test[10];
	  itoa(score,test, 10);	  	
	  strcat(dead,test);
	  MessageBox(NULL, dead, "Fail", MB_OK);
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
  		if (this->coords[0].x < 0) this->coords[0].x = this->getkx() - 1;  //if (this->coords[0].x < 0) move1 = 0;
    	};
		break;
			
  		case 0:{    
		this->coords[0].y -= 1;
  		if (this->coords[0].y < 0) this->coords[0].y = this->getky() - 1;
	    };
		break;
		
  		case 1:{  		
		this->coords[0].x += 1;
  		if (this->coords[0].x > this->getkx() - 1) this->coords[0].x = 0;
		};
		break;
			
  		case 2:{	
		this->coords[0].y += 1;
  		if (this->coords[0].y > this->getky() - 1) this->coords[0].y = 0;
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

int Snake::getHeadx(){
	return this->coords[0].x;
}

int Snake::getHeady(){
	return this->coords[0].y;
}

void Snake::eat(Apple* app){
	int flag = 1;
	while (flag) {
	flag = 0;
    app->generate();
    for (int i = 0;i < this->len; i++) {
    	if (app->getx() == this->coords[i].x && app->gety() == this->coords[i].y ) flag = 1;
    }
    }
	this->len = this->len+1;
    this->coords = (coord*)realloc(this->coords ,sizeof(coord) * this->len);
    this->coords[len - 1].x = this->coords[len - 2].x;
    this->coords[len - 1].y = this->coords[len - 2].y;
    score++;
}

Snake::~Snake(){
	free(this->coords);
}

Apple::Apple() : Screen(SIZEX,SIZEY) {
	this->generate();
}

void Apple::generate(){
	this->xy.x = getrand(0, getkx());
	this->xy.y = getrand(0, getky());
}

void Apple::draw(HDC hDC){
	HPEN hPen = CreatePen(PS_SOLID, 4, RGB(255,0,0));
    SelectObject(hDC, hPen);
	Rectangle(hDC, this->xy.x  * STEP, this->xy.y  * STEP , this->xy.x  * STEP + STEP, this->xy.y  * STEP + STEP);
	DeleteObject(hPen);
}

int Apple::getx(){
	return xy.x;
}

int Apple::gety(){
	return xy.y;
}
Apple::~Apple(){}
