#include <windows.h>
#include <tchar.h>



LPSTR NazwaKlasy = "Klasa Okienka";
MSG Komunikat;

LRESULT CALLBACK WndProc( HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam );

/*
        TUTAJ DEKLARUJEMY KONTROLKI !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
*/

HWND hText1,hText2,hText3;
HWND button1,button2,button3,hStatic,hStatic1,hStatic2,hStatic3;
HDC hdc ;
int a,b,c;
int x = 90, y = 150, vx = 5, vy = 7, dx = 180, dy = 180;
//void on_paint(HWND hwnd)
//{
	//hText1 = CreateWindowEx( WS_EX_CLIENTEDGE, "EDIT", "255", WS_CHILD | WS_VISIBLE | WS_BORDER| ES_MULTILINE , 62, 50, 50, 25, hwnd, (HMENU)2 , NULL, NULL );
	 //button2 = CreateWindowEx( 0, "BUTTON", "MIXUJ KOLORY", WS_CHILD | WS_VISIBLE,100, 100, 150, 30, hwnd, (HMENU)1 , NULL, NULL );

	//HWND editID = GetDlgItem( hwnd, 2 );
   //     _TCHAR buff[ 4 ];
  //      GetWindowText( editID, buff, 20 );
  //      int a = _ttoi( buff );
//	static PAINTSTRUCT ps;
//	BeginPaint(hwnd, &ps);
//	HPEN hpen = CreatePen(PS_SOLID, 3, RGB(a,b,c)); //todo: zoptymalizowaÊ!
//	HBRUSH hbrush = CreateSolidBrush(RGB(a,c,b));
//	SelectObject(ps.hdc, hpen);
//	SelectObject(ps.hdc, hbrush);
//	Ellipse(ps.hdc, x, y, x+dx, y+dy);
//SelectObject(ps.hdc, GetStockObject(NULL_PEN));
	//SelectObject(ps.hdc, GetStockObject(NULL_BRUSH));
//	DeleteObject(hpen);
	//DeleteObject(hbrush);
	//EndPaint(hwnd, &ps);
//}
/*
        TUTAJ KO—CZYMY DEKLAROWANIE KONTROLEK!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
*/
int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow )
{

    // WYPE£NIANIE STRUKTURY
    WNDCLASSEX wc;

    wc.cbSize = sizeof( WNDCLASSEX );
    wc.style = 0;
    wc.lpfnWndProc = WndProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = hInstance;
    wc.hIcon = LoadIcon( NULL, IDI_APPLICATION );
    wc.hCursor = LoadCursor( NULL, IDC_ARROW );
    wc.hbrBackground =( HBRUSH )( COLOR_WINDOW + 1 );
    wc.lpszMenuName = NULL;
    wc.lpszClassName = NazwaKlasy;
    wc.hIconSm = LoadIcon( NULL, IDI_APPLICATION );
    wc.style = CS_DBLCLKS;

    // REJESTROWANIE KLASY OKNA
    if( !RegisterClassEx( & wc ) )
    {
        MessageBox( NULL, " odmowa rejestracji tego okna!", "UPS",
        MB_ICONEXCLAMATION | MB_OK );
        return 1;
    }

    // TWORZENIE OKNA
    HWND hwnd;

    hwnd = CreateWindowEx( WS_EX_CLIENTEDGE, NazwaKlasy, "KO£O BARW RGB", WS_SYSMENU ,
    CW_USEDEFAULT, CW_USEDEFAULT, 400, 375, NULL, NULL, hInstance, NULL );

    if( hwnd == NULL )
    {
        MessageBox( NULL, "Okno odmÛwi≥o przyjúcia na úwiat!", "S£ABO", MB_ICONEXCLAMATION );
        return 1;
    }

    ShowWindow( hwnd, nCmdShow ); // Pokaø okienko...
    UpdateWindow( hwnd );


    // PÍtla komunikatÛw
    while( GetMessage( & Komunikat, NULL, 0, 0 ) )
    {
        TranslateMessage( & Komunikat );
        DispatchMessage( & Komunikat );
    }
    return Komunikat.wParam;

}


// OBS£UGA ZDARZE—
LRESULT CALLBACK WndProc( HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam )
{

    switch( msg )
    {
    case WM_CLOSE:
        DestroyWindow( hwnd );
        break;
    case WM_DESTROY:
        PostQuitMessage( 0 );
       break;
    case WM_CREATE:
     hText1 = CreateWindowEx( WS_EX_CLIENTEDGE, "EDIT", "0", WS_CHILD | WS_VISIBLE | WS_BORDER| ES_MULTILINE , 62, 50, 50, 25, hwnd, (HMENU)2 , NULL, NULL );
     hText2 = CreateWindowEx( WS_EX_CLIENTEDGE, "EDIT", "0", WS_CHILD | WS_VISIBLE | WS_BORDER| ES_MULTILINE , 162, 50, 50, 25, hwnd, (HMENU)3, NULL, NULL );
     hText3 = CreateWindowEx( WS_EX_CLIENTEDGE, "EDIT", "0", WS_CHILD | WS_VISIBLE | WS_BORDER| ES_MULTILINE , 262, 50, 50, 25, hwnd, (HMENU)4, NULL, NULL );

     button2 = CreateWindowEx( 0, "BUTTON", "MIXUJ KOLORY", WS_CHILD | WS_VISIBLE,100, 100, 150, 30, hwnd, (HMENU)1 , NULL, NULL );
      hStatic = CreateWindowEx( 0, "STATIC", "RED", WS_CHILD | WS_VISIBLE |
    SS_CENTER, 62, 25, 50, 15, hwnd, NULL, NULL, NULL );
     hStatic1 = CreateWindowEx( 0, "STATIC", "GREEN", WS_CHILD | WS_VISIBLE |
    SS_CENTER, 162, 25, 50, 15, hwnd, NULL, NULL, NULL );
     hStatic2 = CreateWindowEx( 0, "STATIC", "BLUE", WS_CHILD | WS_VISIBLE |
    SS_CENTER, 262, 25, 50, 15, hwnd, NULL, NULL, NULL );
     hStatic3 = CreateWindowEx( 0, "STATIC", "PODAJ SK£ADOWE RGB OD 0 DO 255", WS_CHILD | WS_VISIBLE |
    SS_CENTER, 62, 8, 250, 15, hwnd, NULL, NULL, NULL );
    break;
case WM_PAINT:
    {


        static PAINTSTRUCT ps;
        BeginPaint(hwnd, &ps);
        HBRUSH hbrush = CreateSolidBrush(RGB(a,c,b));
        SelectObject(ps.hdc, hbrush);
        Ellipse(ps.hdc, x, y, x+dx, y+dy);
        SelectObject(ps.hdc, GetStockObject(NULL_BRUSH));
        DeleteObject(hbrush);
        EndPaint(hwnd, &ps);
}
break;
 case WM_COMMAND:
      switch (LOWORD(wParam))
    {
 case 1:

        HWND editID = GetDlgItem( hwnd, 2 );
        _TCHAR buff[ 4 ];
        GetWindowText( editID, buff, 20 );
        a = _ttoi( buff );

        HWND edit1ID = GetDlgItem( hwnd, 3 );
        _TCHAR buff1[ 4 ];
        GetWindowText( edit1ID, buff1, 20 );
        b = _ttoi( buff1 );

        HWND edit2ID = GetDlgItem( hwnd, 4 );
        _TCHAR buff2[ 4 ];
        GetWindowText( edit2ID, buff2, 20 );
        c = _ttoi( buff2 );
        InvalidateRect(hwnd, NULL, TRUE);
        UpdateWindow(hwnd);
        if(a >255)
        MessageBox( hwnd, "Bez jaj, przecieø by≥o napisane, øe od 0 do 255", "èle!", MB_ICONINFORMATION );
        if(b >255)
        MessageBox( hwnd, "Bez jaj, przecieø by≥o napisane, øe od 0 do 255", "èle!", MB_ICONINFORMATION );
        if(c >255)
        MessageBox( hwnd, "Bez jaj, przecieø by≥o napisane, øe od 0 do 255", "èle!", MB_ICONINFORMATION );
        }
   break;

    break;
break;




        default:
        return DefWindowProc( hwnd, msg, wParam, lParam );
    }

    return 0;
}
