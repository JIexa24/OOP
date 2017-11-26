#include <math.h>
#include "snake.h"

Screen scr(SIZEX,SIZEY);
Snake sn(15,10);
int rungame = 1;
using namespace std;

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInst, /* hInstance ÿâëÿåòñÿ äåñêðèïòîðîì ýêçåìïëÿðà îêíà */
                   HINSTANCE hPrevInst, /* hInstance ÿâëÿåòñÿ äåñêðèïòîðîì ýêçåìïëÿðà îêíà */
                   LPSTR lpCmdLine, /* hInstance ÿâëÿåòñÿ äåñêðèïòîðîì ýêçåìïëÿðà îêíà */
                   int nCmdShow) /* îïðåäåëÿåò ñïîñîá ïîêàçà îêíà íóæåí äëÿ showwindow */
{	
	/*struct tagWNDCLASSEX{
      UINT cbSize; //âåëè÷èíà ñòðóêòóðû â áàéòàõ
      UINT style; // ñòèë êëàññà îêíà
      WNDPROC WndProc; // Óêàçàòåëü íà èìÿ ïîëüçîâàòåëüñêîé ôóíêöèè
      int cbWndExtra; // ÷èñëî îñâîáîæäàåìûõ áàéòîâ
      int cbClsExtra; // òî æêå ÷òî è âûøå íî äëÿ ýêçåìïëÿðà ïðèëîæåíèÿ
      HICON hIcon; // äåñêðèïòîð çíà÷êà
      HICON hIconMini; // .... òðåé
      HCURSOR hCursor; // .... êóðñîðà
      HBRUSH hbrBack; // .... öâåò ôîíà
      HINSTANCE hInst; // .... ýêçåìïëÿðà ïðèëîæåíèÿ
      LPCTSTR lpszClassName; // óêàçàòåëü íà const-ñòðîêó ñ èìåíåì êëàññà
      LPCTSTR lpszMenuName; // ñîäåðæàùóþ ìåíþ ñ èìåíåì êëàññà
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
							szClassName, // èìÿ êëàññ
							"WindowOne", // Èìÿ îêíà
							WS_OVERLAPPEDWINDOW,// | WS_VSCROLL, //ðåæèìû îòîáðàæåíèÿ îêíà
							50, //ïîçèöèÿ ïî èêñ CW_USEDEFAULT
							50, // ïîçèöèÿ ïî èãðåê, åñëè äåôîëò èêñ òî íîëü
							716, //  øèðèíà îêíà CW_USEDEFAULT
 							739, // âûñîòà. òîæå èççà äåôîëòà
							(HWND)NULL, // äåñêðèïòîð ðîäèòåëüñêîãî îêíà
						 	NULL, // äåñêðèïòîð ìåíþ
 							HINSTANCE(hInst), // è ýêçåìïëÿðà ïðèëîæåíèÿ
						 	NULL); // íè÷åãî íå ïåðåäàåì èç WndProc
						 	
	if(!hMainWnd) {
		MessageBox(NULL, "Can't create window", "Error", MB_OK);
		return 0;
  }
  
	ShowWindow(hMainWnd, nCmdShow);
	UpdateWindow(hMainWnd);

  while(GetMessage(&msg, NULL, 0, 0)){
   TranslateMessage(&msg);
    DispatchMessage(&msg);
  }
	return msg.wParam; 
}

LRESULT CALLBACK WndProc(HWND hMainWnd, UINT uMsg, WPARAM wParam, LPARAM lParam){

    HDC hDC,hDC1; // Äåñêðèïòîð îðèåíòàöèè òåêñòà
    PAINTSTRUCT ps; //Ñòðóêòóðà êëèåíòñêîé îáëàñòè(ðàçìåð,òèï..)
    RECT rect; // ðàçìåð êëèåíòñêîé îáëàñòè   
        //GetClientRect(hWnd, &rect); // îáëàñòü ðèñîâàíèÿ
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

    case WM_PAINT: {// åñëè ðèñîâàòü
        hDC = BeginPaint(hMainWnd, &ps);//êîíòåêñò óñòðîéñòâà 
        GetClientRect(hMainWnd, &rect); // îáëàñòü ðèñîâàíèÿ
				HPEN hPen;	
				//scr.draw(hDC);
				sn.draw(hDC);
				sn.move();
				Sleep(500);
        EndPaint(hMainWnd, &ps); //çàêàí÷èâàåì ðèñîâàòü
        if (rungame) {
        InvalidateRect(hMainWnd,NULL,TRUE); // êîìàíäà íà ïåðåðèñîâêó îêíà
		}
        else{
        PostQuitMessage(0); 
		}
				};
        break;
    case WM_DESTROY: //Åñëè çàêðûëîñü îêíî - îòïðàâëÿåì íóëë
        PostQuitMessage(0); 
       // KillTimer(hMainWnd, 1);
        break;
        
case WM_LBUTTONDOWN:
        PostQuitMessage(0); 
       // KillTimer(hMainWnd, 1);
break;
    default:
        return DefWindowProc(hMainWnd, uMsg, wParam, lParam); //åñëè çàêðûëè îêíî
    }
    return 0; 
}
