#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#define SIZEX 500
#define SIZEY 500
typedef struct Coords {
  int x;
  int y;
} coord;

class Game {
public:
  virtual void draw(HDC hDC) = 0;
};

class Screen : public Game {
private:
  int sizex;
  int sizey;
  int kx;
  int ky;

public:
  Screen();
  Screen(int x, int y);
  int getkx();
  int getky();
  virtual void draw(HDC hDC);
  ~Screen();
};
class Snake;
class Apple : public Screen {
private:
  coord xy;

public:
  Apple(Snake *snk);
  int getx();
  int gety();
  void draw(HDC hdc);
  void generate();
  ~Apple();
};

class Snake : public Screen {
private:
  int len;
  coord *coords;
  int vector;
  int move1;

public:
  Snake(int xhead, int yhead);
  void move();
  void eat(Apple *app);
  int getHeadx();
  int getHeady();
  int getCoordsxi(int i);
  int getCoordsyi(int i);
  int getLen();
  void setVector(int vec);
  void draw(HDC hdc);
  ~Snake();
};
