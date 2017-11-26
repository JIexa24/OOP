#include <math.h>
#include "snake.h"

Screen scr(SIZEX,SIZEY);
Snake sn(15,10);
Apple app;
int rungame = 1;
using namespace std;

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInst, /* hInstance €вл€етс€ дескриптором экземпл€ра окна */
                   HINSTANCE hPrevInst, /* hInstance €вл€етс€ дескриптором экземпл€ра окна */
                   LPSTR lpCmdLine, /* hInstance €вл€етс€ дескриптором экземпл€ра окна */
                   int nCmdShow) /* определ€ет способ показа окна нужен дл€ showwindow */
{	
	/*struct tagWNDCLASSEX{
      UINT cbSize; //величина структуры в байтах
      UINT style; // стил класса окна
      WNDPROC WndProc; // ”казатель на им€ пользовательской функции
      int cbWndExtra; // число освобождаемых байтов
      int cbClsExtra; // то жке что и выше но дл€ экземпл€ра приложени€
      HICON hIcon; // дескриптор значка
      HICON hIconMini; // .... трей
      HCURSOR hCursor; // .... курсора
      HBRUSH hbrBack; // .... цвет фона
      HINSTANCE hInst; // .... экземпл€ра приложени€
      LPCTSTR lpszClassName; // указатель на const-строку с именем класса
      LPCTSTR lpszMenuName; // содержащую меню с именем класса
}WNDCLASSEX;*/
	HWND hMainWnd;  //windowsDescriptor;
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
  wc.hIcon  = LoadIcon(NULL, IDI_WINLOGO); 
  wc.hIconSm = LoadIcon(NULL, IDI_WINLOGO); 
  wc.hCursor = LoadCursor(NULL, IDC_ARROW); 
  wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH); 
  wc.hInstance = hInst;
  
  if(!RegisterClassEx(&wc)){ //if class is init
  	MessageBox(NULL, "Alarm!", "Error", MB_OK);
  	return 0;
  }
    
	hMainWnd = CreateWindow(
							szClassName, // им€ класс
							"WindowOne", // »м€ окна
							WS_OVERLAPPEDWINDOW,// | WS_VSCROLL, //режимы отображени€ окна
							50, //позици€ по икс CW_USEDEFAULT
							50, // позици€ по игрек, если дефолт икс то ноль
							716, //  ширина окна CW_USEDEFAULT
 							739, // высота. тоже изза дефолта
							(HWND)NULL, // дескриптор родительского окна
						 	NULL, // дескриптор меню
 							HINSTANCE(hInst), // и экземпл€ра приложени€
						 	NULL); // ничего не передаем из WndProc
						 	
	if(!hMainWnd) {
		MessageBox(NULL, "Can't create window", "Error", MB_OK);
		return 0;
  }
  
  srand(time(NULL));
  
	ShowWindow(hMainWnd, nCmdShow);
	UpdateWindow(hMainWnd);

  while(GetMessage(&msg, NULL, 0, 0)){
   TranslateMessage(&msg);
    DispatchMessage(&msg);
  }
	return msg.wParam; 
}

LRESULT CALLBACK WndProc(HWND hMainWnd, UINT uMsg, WPARAM wParam, LPARAM lParam){

    HDC hDC,hDC1; // ƒескриптор ориентации текста
    PAINTSTRUCT ps; //—труктура клиентской области(размер,тип..)
    RECT rect; // размер клиентской области   
        //GetClientRect(hWnd, &rect); // область рисовани€
    switch(uMsg){
    case WM_KEYDOWN:{
  	  unsigned int key = wParam;
  	switch(key) {
  		case 37:{  	
			sn.setVector(3);		
			}
				break;
			
  		case 38:{  		
			sn.setVector(0);
			};
				break;
			
  		case 39:{  		
			sn.setVector(1);	
			};
				break;
			
  		case 40:{	
			sn.setVector(2);
			};
				break;
		}
	  };
	break;

    case WM_PAINT: {// если рисовать
        hDC = BeginPaint(hMainWnd, &ps);//контекст устройства 
        GetClientRect(hMainWnd, &rect); // область рисовани€
				HPEN hPen;	
				scr.draw(hDC);
				sn.draw(hDC);
				app.draw(hDC);
				sn.move();
				//printf("%d = %d | %d = %d\n",sn.getHeadx() , app.getx(), sn.getHeady(), app.gety() );
				if(sn.getHeadx() == app.getx() && sn.getHeady() == app.gety()){
					sn.eat(&app);
				}
				Sleep(150);
        EndPaint(hMainWnd, &ps); //заканчиваем рисовать
        if (rungame) {
        InvalidateRect(hMainWnd,NULL,TRUE); // команда на перерисовку окна
		}
        else{
        PostQuitMessage(0); 
		}
				};
        break;
    case WM_DESTROY: //≈сли закрылось окно - отправл€ем нулл
        PostQuitMessage(0); 
       // KillTimer(hMainWnd, 1);
        break;
        
case WM_LBUTTONDOWN:
        PostQuitMessage(0); 
       // KillTimer(hMainWnd, 1);
break;
    default:
        return DefWindowProc(hMainWnd, uMsg, wParam, lParam); //если закрыли окно
    }
    return 0; 
}
