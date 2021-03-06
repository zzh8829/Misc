/*-------------------------------------
   EMF2.C -- Enhanced Metafile Demo #2
             (c) Charles Petzold, 1996
  -------------------------------------*/

#include <windows.h>

LRESULT CALLBACK WndProc (HWND, UINT, WPARAM, LPARAM) ;

int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance,
                    PSTR szCmdLine, int iCmdShow)
     {
     static char szAppName[] = "EMF2" ;
     HWND        hwnd ;
     MSG         msg ;
     WNDCLASSEX  wndclass ;

     wndclass.cbSize        = sizeof (wndclass) ;
     wndclass.style         = CS_HREDRAW | CS_VREDRAW ;
     wndclass.lpfnWndProc   = WndProc ;
     wndclass.cbClsExtra    = 0 ;
     wndclass.cbWndExtra    = 0 ;
     wndclass.hInstance     = hInstance ;
     wndclass.hIcon         = LoadIcon (NULL, IDI_APPLICATION) ;
     wndclass.hCursor       = LoadCursor (NULL, IDC_ARROW) ;
     wndclass.hbrBackground = (HBRUSH) GetStockObject (WHITE_BRUSH) ;
     wndclass.lpszMenuName  = NULL ;
     wndclass.lpszClassName = szAppName ;
     wndclass.hIconSm       = LoadIcon (NULL, IDI_APPLICATION) ;

     RegisterClassEx (&wndclass) ;

     hwnd = CreateWindow (szAppName, "Enhanced Metafile Demo #2",
                          WS_OVERLAPPEDWINDOW,
                          CW_USEDEFAULT, CW_USEDEFAULT,
                          CW_USEDEFAULT, CW_USEDEFAULT,
                          NULL, NULL, hInstance, NULL) ;

     ShowWindow (hwnd, iCmdShow) ;
     UpdateWindow (hwnd) ;

     while (GetMessage (&msg, NULL, 0, 0))
          {
          TranslateMessage (&msg) ;
          DispatchMessage (&msg) ;
          }
     return msg.wParam ;
     }

LRESULT CALLBACK WndProc (HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
     {
     HDC          hdc, hdcEMF ;
     HENHMETAFILE hemf ;
     PAINTSTRUCT  ps ;
     RECT         rect ;

     switch (iMsg)
          {
          case WM_CREATE:
               hdcEMF = CreateEnhMetaFile (NULL, "emf2.emf", NULL,
                                           "EMF2\0EMF Demo #2\0") ;

               Rectangle (hdcEMF, 100, 100, 200, 200) ;

               MoveToEx  (hdcEMF, 100, 100, NULL) ;
               LineTo    (hdcEMF, 200, 200) ;

               MoveToEx  (hdcEMF, 200, 100, NULL) ;
               LineTo    (hdcEMF, 100, 200) ;

               hemf = CloseEnhMetaFile (hdcEMF) ;

               DeleteEnhMetaFile (hemf) ;
               return 0 ;

          case WM_PAINT:
               hdc = BeginPaint (hwnd, &ps) ;

               GetClientRect (hwnd, &rect) ;

               rect.left   =     rect.right  / 4 ;
               rect.right  = 3 * rect.right  / 4 ;
               rect.top    =     rect.bottom / 4 ;
               rect.bottom = 3 * rect.bottom / 4 ;

               hemf = GetEnhMetaFile ("emf2.emf") ;

               PlayEnhMetaFile (hdc, hemf, &rect) ;

               DeleteEnhMetaFile (hemf) ;

               EndPaint (hwnd, &ps) ;
               return 0 ;

          case WM_DESTROY:
               PostQuitMessage (0) ;
               return 0 ;
          }
     return DefWindowProc (hwnd, iMsg, wParam, lParam) ;
     }
