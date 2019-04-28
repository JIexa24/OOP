#include "figure.h"
#include "line.h"
#include "poly.h"
#include "rect.h"

#define radius 50
#define radius0 100

int score = 0;

float xCntr = 350;
float yCntr = 350;

// float absX = xCntr;
// float absY = yCntr + radius0;

float step = 2;

#define quadro 4
#define triang 3

// float xRect[quadro] = {xCntr,xCntr+radius,xCntr,xCntr-radius};//,xCntr};
// float yRect[quadro] =
// {yCntr-radius,yCntr,yCntr+radius,yCntr};//,yCntr-radius};

float xTriang[triang] = {xCntr, xCntr + radius, xCntr + 2 * radius};
float yTriang[triang] = {yCntr - radius, yCntr, yCntr};

float xTriang1[triang] = {xCntr - radius, xCntr, xCntr};
float yTriang1[triang] = {yCntr, yCntr - radius, yCntr - 2 * radius};

float xTriang2[triang] = {xCntr, xCntr - radius, xCntr - 2 * radius};
float yTriang2[triang] = {yCntr + radius, yCntr, yCntr};

float xTriang3[triang] = {xCntr + radius, xCntr, xCntr};
float yTriang3[triang] = {yCntr, yCntr + radius, yCntr + 2 * radius};

using namespace std;

Poly PolygonTwo(triang, xTriang, yTriang, 3);
Poly PolygonThree(triang, xTriang1, yTriang1, 3);
Poly PolygonFour(triang, xTriang2, yTriang2, 3);
Poly PolygonFive(triang, xTriang3, yTriang3, 3);

int vector = -1, vect2 = rand() % 4, vect1 = rand() % 4;

Point a(rand() % 700, rand() % 700);
Rect RectangleOne(a, {a.x + 20, a.y + 20});

Point b(rand() % 700, rand() % 700);
Rect RectangleTwo(b, {b.x + 20, b.y + 20});

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(
    HINSTANCE hInst, /* hInstance ˙âë˙ĺňń˙ äĺńęđčďňîđîě ýęçĺěďë˙đŕ îęíŕ */
    HINSTANCE hPrevInst, /* hInstance ˙âë˙ĺňń˙ äĺńęđčďňîđîě ýęçĺěďë˙đŕ îęíŕ */
    LPSTR lpCmdLine, /* hInstance ˙âë˙ĺňń˙ äĺńęđčďňîđîě ýęçĺěďë˙đŕ îęíŕ */
    int nCmdShow) /* îďđĺäĺë˙ĺň ńďîńîá ďîęŕçŕ îęíŕ íóćĺí äë˙ showwindow */
{
  /*struct tagWNDCLASSEX{
UINT cbSize; //âĺëč÷číŕ ńňđóęňóđű â áŕéňŕő
UINT style; // ńňčë ęëŕńńŕ îęíŕ
WNDPROC WndProc; // Óęŕçŕňĺëü íŕ čě˙ ďîëüçîâŕňĺëüńęîé ôóíęöčč
int cbWndExtra; // ÷čńëî îńâîáîćäŕĺěűő áŕéňîâ
int cbClsExtra; // ňî ćęĺ ÷ňî č âűřĺ íî äë˙ ýęçĺěďë˙đŕ ďđčëîćĺíč˙
HICON hIcon; // äĺńęđčďňîđ çíŕ÷ęŕ
HICON hIconMini; // .... ňđĺé
HCURSOR hCursor; // .... ęóđńîđŕ
HBRUSH hbrBack; // .... öâĺň ôîíŕ
HINSTANCE hInst; // .... ýęçĺěďë˙đŕ ďđčëîćĺíč˙
LPCTSTR lpszClassName; // óęŕçŕňĺëü íŕ const-ńňđîęó ń čěĺíĺě ęëŕńńŕ
LPCTSTR lpszMenuName; // ńîäĺđćŕůóţ ěĺíţ ń čěĺíĺě ęëŕńńŕ
}WNDCLASSEX;*/
  HWND hMainWnd; // windowsDescriptor;
  TCHAR szClassName[] = "My Class";
  MSG msg;

  WNDCLASSEX wc;
  wc.cbSize = sizeof(wc);
  wc.style = CS_HREDRAW | CS_VREDRAW;
  wc.lpfnWndProc = WndProc;
  wc.lpszMenuName = NULL;
  wc.lpszClassName = szClassName;
  wc.cbWndExtra = 0;
  wc.cbClsExtra = 0;
  wc.hIcon = LoadIcon(NULL, IDI_WINLOGO);
  wc.hIconSm = LoadIcon(NULL, IDI_WINLOGO);
  wc.hCursor = LoadCursor(NULL, IDC_ARROW);
  wc.hbrBackground = (HBRUSH)GetStockObject(LTGRAY_BRUSH);
  wc.hInstance = hInst;

  if (!RegisterClassEx(&wc)) { // if class is init
    MessageBox(NULL, "Alarm!", "Error", MB_OK);
    return 0;
  }

  hMainWnd = CreateWindow(
      szClassName, // čě˙ ęëŕńń
      "WindowOne", // Čě˙ îęíŕ
      WS_OVERLAPPEDWINDOW, // | WS_VSCROLL, //đĺćčěű îňîáđŕćĺíč˙ îęíŕ
      50,                  //ďîçčöč˙ ďî čęń CW_USEDEFAULT
      50, // ďîçčöč˙ ďî čăđĺę, ĺńëč äĺôîëň čęń ňî íîëü
      716,        //  řčđčíŕ îęíŕ CW_USEDEFAULT
      739,        // âűńîňŕ. ňîćĺ čççŕ äĺôîëňŕ
      (HWND)NULL, // äĺńęđčďňîđ đîäčňĺëüńęîăî îęíŕ
      NULL,       // äĺńęđčďňîđ ěĺíţ
      HINSTANCE(hInst), // č ýęçĺěďë˙đŕ ďđčëîćĺíč˙
      NULL);            // íč÷ĺăî íĺ ďĺđĺäŕĺě čç WndProc

  if (!hMainWnd) {
    MessageBox(NULL, "Can't create window", "Error", MB_OK);
    return 0;
  }

  ShowWindow(hMainWnd, nCmdShow);
  UpdateWindow(hMainWnd);

  while (GetMessage(&msg, NULL, 0, 0)) {
    TranslateMessage(&msg);
    DispatchMessage(&msg);
  }
  return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hMainWnd, UINT uMsg, WPARAM wParam,
                         LPARAM lParam) {

  HDC hDC, hDC1; // Äĺńęđčďňîđ îđčĺíňŕöčč ňĺęńňŕ
  PAINTSTRUCT ps; //Ńňđóęňóđŕ ęëčĺíňńęîé îáëŕńňč(đŕçěĺđ,ňčď..)
  RECT rect; // đŕçěĺđ ęëčĺíňńęîé îáëŕńňč
             // GetClientRect(hWnd, &rect); // îáëŕńňü đčńîâŕíč˙
  switch (uMsg) {
  case WM_KEYDOWN: {
    unsigned int key = wParam;
    switch (key) {
    case 37: {
      vector = 3;
    } break;

    case 38: {
      vector = 0;
    }; break;

    case 39: {
      vector = 1;
    }; break;

    case 40: {
      vector = 2;
    }; break;
    }
  }; break;

  case WM_PAINT: {                   // ĺńëč đčńîâŕňü
    hDC = BeginPaint(hMainWnd, &ps); //ęîíňĺęńň óńňđîéńňâŕ
    GetClientRect(hMainWnd, &rect);  // îáëŕńňü đčńîâŕíč˙
    HPEN hPen;

    // PolygonTwo.PolyOne(triang, xTriang, yTriang,3);
    // PolygonThree.PolyOne(triang, xTriang1, yTriang1,3);
    // PolygonFour.PolyOne(triang, xTriang2, yTriang2,3);
    // PolygonFive.PolyOne(triang, xTriang3, yTriang3,3);

    RectangleOne.drawObj(hDC, hPen, 0, 255, 0, 2);
    RectangleTwo.drawObj(hDC, hPen, 0, 255, 0, 2);

    PolygonTwo.drawObj(hDC, hPen, 255, 0, 0, 2);
    PolygonThree.drawObj(hDC, hPen, 255, 0, 0, 2);
    PolygonFour.drawObj(hDC, hPen, 255, 0, 0, 2);
    PolygonFive.drawObj(hDC, hPen, 255, 0, 0, 2);

    PolygonTwo.move(radius, xCntr, yCntr, step);
    PolygonThree.move(radius, xCntr, yCntr, step);
    PolygonFour.move(radius, xCntr, yCntr, step);
    PolygonFive.move(radius, xCntr, yCntr, step);

    RectangleOne.keyMove(vect2);
    RectangleTwo.keyMove(vect1);
    /*			int Step = step;
                            int Radius = radius0;
                                if (xCntr >= absX && yCntr <= absY) {
          if (xCntr <= absX+(Radius/2)*sqrt(2)){
              xCntr = xCntr+Step;
              
              yCntr = absY - sqrt(pow(Radius,2) - pow((xCntr >= absX)*(xCntr -
absX)+(xCntr < absX)*(absX -xCntr),2));
            
                                                    } else{
              yCntr = yCntr+Step;
              xCntr = absX + sqrt(pow(Radius,2) - pow((yCntr >= absY)*(yCntr -
absY)+(yCntr < absY)*(absY -yCntr),2));
                                                            
                                                    }
                                            } else if (xCntr >= absX && yCntr >=
absY) { if (xCntr >= absX+(Radius/2)*sqrt(2)){
            
              yCntr = yCntr+Step;
              xCntr = absX + sqrt(pow(Radius,2) - pow((yCntr >= absY)*(yCntr -
absY)+(yCntr < absY)*(absY -yCntr),2));
                                                                            
                                                    } else{
                                                        xCntr = xCntr-Step;
              yCntr = absY + sqrt(pow(Radius,2) - pow((xCntr >= absX)*(xCntr -
absX)+(xCntr < absX)*(absX -xCntr),2));
                                                            }
                                            
                                            } else if (xCntr <= absX && yCntr >=
absY) { if (xCntr >= absX-(Radius/2)*sqrt(2)){ xCntr = xCntr - Step;
              
              yCntr = absY + sqrt(pow(Radius,2) - pow((xCntr >= absX)*(xCntr -
absX)+(xCntr < absX)*(absX -xCntr),2));
              
            
                                                    } else{
              yCntr = yCntr - Step;
              xCntr = absX - sqrt(pow(Radius,2) - pow((yCntr >= absY)*(yCntr -
absY)+(yCntr < absY)*(absY - yCntr),2));
                                                                    
                                                    }
                                            } else if (xCntr <= absX && yCntr <=
absY) { if (xCntr <= absX-(Radius/2)*sqrt(2)){

              yCntr = yCntr-Step;
              xCntr = absX - sqrt(pow(Radius,2) - pow((yCntr >= absY)*(yCntr -
absY)+(yCntr < absY)*(absY -yCntr),2));
            
                                                    } else{
              xCntr = xCntr + Step;
              yCntr = absY - sqrt(pow(Radius,2) - pow((xCntr >= absX)*(xCntr -
absX)+(xCntr < absX)*(absX - xCntr),2));
                                                            }
                                                            
                                                    }
                                                                    
                            
xTriang[0] = xCntr;
xTriang[1] = xCntr+radius;
xTriang[2] = xCntr+2*radius;
yTriang[0] = yCntr-radius;
yTriang[1] = yCntr;
yTriang[2] = yCntr;

xTriang1[0] = xCntr-radius;
xTriang1[1] = xCntr;
xTriang1[2] =xCntr;
yTriang1[0]=yCntr;
yTriang1[1]=yCntr-radius;
yTriang1[2]=yCntr-2*radius;

xTriang2[0]= xCntr;
xTriang2[1]= xCntr-radius;
xTriang2[2]=xCntr-2*radius;
yTriang2[0] = yCntr+radius;
yTriang2[1] = yCntr;
yTriang2[2] = yCntr;

xTriang3[0] = xCntr+radius;
xTriang3[1] = xCntr;
xTriang3[2] = xCntr;
yTriang3[0]= yCntr;
yTriang3[1]= yCntr+radius;
yTriang3[2]= yCntr+2*radius;
*/
    if ((RectangleOne.a.x >= xCntr - 2 * radius &&
         RectangleOne.a.x <= xCntr + 2 * radius) &&
            (RectangleOne.a.y >= yCntr - 2 * radius &&
             RectangleOne.a.y <= yCntr + 2 * radius) ||
        (RectangleOne.b.x >= xCntr - 2 * radius &&
         RectangleOne.b.x <= xCntr + 2 * radius) &&
            (RectangleOne.b.y >= yCntr - 2 * radius &&
             RectangleOne.b.y <= yCntr + 2 * radius)) {
      vect2 = rand() % 4;
      a.x = rand() % 700;
      a.y = rand() % 700;
      RectangleOne.setPoints(a, {a.x + 20, a.y + 20});
      score++;
    }
    if (RectangleOne.a.x > 700 || RectangleOne.a.x <= 0 ||
        RectangleOne.a.y > 700 || RectangleOne.a.x <= 0 ||
        RectangleOne.b.x > 700 || RectangleOne.b.x <= 0 ||
        RectangleOne.b.y > 700 || RectangleOne.b.y <= 0) {
      switch (vect2) {
      case 0: {
        vect2 = 2;
        break;
      }
      case 1: {
        vect2 = 3;
        break;
      }
      case 2: {
        vect2 = 0;
        break;
      }
      case 3: {
        vect2 = 1;
        break;
      }
      }
    }
    if ((RectangleTwo.a.x >= xCntr - 2 * radius &&
         RectangleTwo.a.x <= xCntr + 2 * radius) &&
            (RectangleTwo.a.y >= yCntr - 2 * radius &&
             RectangleTwo.a.y <= yCntr + 2 * radius) ||
        (RectangleTwo.b.x >= xCntr - 2 * radius &&
         RectangleTwo.b.x <= xCntr + 2 * radius) &&
            (RectangleTwo.b.y >= yCntr - 2 * radius &&
             RectangleTwo.b.y <= yCntr + 2 * radius)) {
      vect1 = rand() % 4;
      b.x = rand() % 700;
      b.y = rand() % 700;
      RectangleTwo.setPoints(b, {b.x + 20, b.y + 20});
      score++;
    }
    if (RectangleTwo.a.x > 700 || RectangleTwo.a.x <= 0 ||
        RectangleTwo.a.y > 700 || RectangleTwo.a.x <= 0 ||
        RectangleTwo.b.x > 700 || RectangleTwo.b.x <= 0 ||
        RectangleTwo.b.y > 700 || RectangleTwo.b.y <= 0) {
      switch (vect1) {
      case 0: {
        vect1 = 2;
        break;
      }
      case 1: {
        vect1 = 3;
        break;
      }
      case 2: {
        vect1 = 0;
        break;
      }
      case 3: {
        vect1 = 1;
        break;
      }
      }
    }

    switch (vector) {
    case 0: {
      if (yCntr - stepp - 2 * radius >= 0) {
        yCntr -= stepp;
      } else {
        vector = 2;
      }
      PolygonTwo.keyMove(vector);
      PolygonThree.keyMove(vector);
      PolygonFour.keyMove(vector);
      PolygonFive.keyMove(vector);
      break;
    }
    case 1: {
      if (xCntr + stepp + 2 * radius <= 700) {
        xCntr += stepp;
      } else {
        vector = 3;
      }
      PolygonTwo.keyMove(vector);
      PolygonThree.keyMove(vector);
      PolygonFour.keyMove(vector);
      PolygonFive.keyMove(vector);
      break;
    }
    case 2: {
      if (yCntr + stepp + 2 * radius <= 700) {
        yCntr += stepp;
      } else {
        vector = 0;
      }
      PolygonTwo.keyMove(vector);
      PolygonThree.keyMove(vector);
      PolygonFour.keyMove(vector);
      PolygonFive.keyMove(vector);
      break;
    }
    case 3: {
      if (xCntr - stepp - 2 * radius >= 0) {
        xCntr -= stepp;
      } else {
        vector = 1;
      }
      PolygonTwo.keyMove(vector);
      PolygonThree.keyMove(vector);
      PolygonFour.keyMove(vector);
      PolygonFive.keyMove(vector);

      break;
    }
    }
    Sleep(10);
    EndPaint(hMainWnd, &ps); //çŕęŕí÷čâŕĺě đčńîâŕňü
    InvalidateRect(hMainWnd, NULL, TRUE); // ęîěŕíäŕ íŕ ďĺđĺđčńîâęó îęíŕ
  }; break;
  case WM_DESTROY: //Ĺńëč çŕęđűëîńü îęíî - îňďđŕâë˙ĺě íóëë
    PostQuitMessage(0);
    // KillTimer(hMainWnd, 1);
    break;

  case WM_LBUTTONDOWN:
    PostQuitMessage(0);
    // KillTimer(hMainWnd, 1);
    break;
  default:
    return DefWindowProc(hMainWnd, uMsg, wParam, lParam); //ĺńëč çŕęđűëč îęíî
  }
  return 0;
}
