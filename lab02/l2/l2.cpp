// l2.cpp: определяет точку входа для приложения.
//

#include "stdafx.h"
#include "l2.h"
#include "commdlg.h"
#include "Commctrl.h"
#define MAX_LOADSTRING 100
#define IDC_BUTTON1                     112
#define IDC_BUTTON2                     113
#define IDC_BUTTON3                     114
#define IDC_BUTTON                      115
#define IDC_LIST7                      116
// Глобальные переменные:
int num=8;
int ListItem1;
int Pos;
COLORREF colorText = RGB(255, 0, 0);
HINSTANCE hInst;								// текущий экземпляр
HWND hDlg,hWndD,hWnd,hWndD2,hListBox;
TCHAR szTitle[MAX_LOADSTRING];					// Текст строки заголовка
TCHAR szWindowClass[MAX_LOADSTRING];			// имя класса главного окна
TCHAR szButton[MAX_LOADSTRING]=TEXT("Button");

TCHAR szButtonTitle[MAX_LOADSTRING]=TEXT("Модальный-системный диалог");	
TCHAR szButtonTitle1[MAX_LOADSTRING]=TEXT("Модальный диалог");					// The title bar text
TCHAR szButtonTitle2[MAX_LOADSTRING]=TEXT("Немодальный диалог");					// The title bar text
TCHAR szButtonTitle3[MAX_LOADSTRING]=TEXT("Стандартный диалог");

// Отправить объявления функций, включенных в этот модуль кода:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About2(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	Dial2(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	Dial3(HWND, UINT, WPARAM, LPARAM);

int APIENTRY _tWinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPTSTR    lpCmdLine,
                     int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

 	// TODO: разместите код здесь.
	MSG msg;
	HACCEL hAccelTable;

	// Инициализация глобальных строк
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_L2, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Выполнить инициализацию приложения:
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_L2));

	// Цикл основного сообщения:
	while (GetMessage(&msg, NULL, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int) msg.wParam;
}



//
//  ФУНКЦИЯ: MyRegisterClass()
//
//  НАЗНАЧЕНИЕ: регистрирует класс окна.
//
//  КОММЕНТАРИИ:
//
//    Эта функция и ее использование необходимы только в случае, если нужно, чтобы данный код
//    был совместим с системами Win32, не имеющими функции RegisterClassEx'
//    которая была добавлена в Windows 95. Вызов этой функции важен для того,
//    чтобы приложение получило "качественные" мелкие значки и установило связь
//    с ними.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_L2));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= MAKEINTRESOURCE(IDC_L2);
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}

//
//   ФУНКЦИЯ: InitInstance(HINSTANCE, int)
//
//   НАЗНАЧЕНИЕ: сохраняет обработку экземпляра и создает главное окно.
//
//   КОММЕНТАРИИ:
//
//        В данной функции дескриптор экземпляра сохраняется в глобальной переменной, а также
//        создается и выводится на экран главное окно программы.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
    HWND hWndB,hWndB1,hWndB2,hWndB3;

   hInst = hInstance; // Сохранить дескриптор экземпляра в глобальной переменной

   hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, 400, 400, NULL, NULL, hInstance, NULL);

	hWndD2 = CreateDialog(hInstance,MAKEINTRESOURCE(IDD_DIALOG3),hWnd,Dial3);

   hWndB = CreateWindow(szButton, szButtonTitle,  WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,
      30, 40, 300, 50, hWnd, HMENU(IDC_BUTTON), hInstance, NULL);

   hWndB1 = CreateWindow(szButton, szButtonTitle1,  WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,
      30, 100, 300, 50, hWnd, HMENU(IDC_BUTTON1), hInstance, NULL);

   hWndB2 = CreateWindow(szButton, szButtonTitle2,  WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,
      30, 160, 300, 50, hWnd, HMENU(IDC_BUTTON2), hInstance, NULL);

   hWndB3 = CreateWindow(szButton, szButtonTitle3,  WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,
      30, 220, 300, 50, hWnd, HMENU(IDC_BUTTON3), hInstance, NULL);
      hListBox = CreateWindow(TEXT("listbox"), NULL, WS_CHILD|WS_VISIBLE|WS_VSCROLL|LBS_NOTIFY|WS_BORDER , 20, 20, 140, 30, hWndD2, HMENU(IDC_LIST7), hInstance, NULL);
   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);
	
  SendMessage(hListBox, LB_ADDSTRING, 0, (LPARAM) TEXT("Заголовок 1"));
  SendMessage(hListBox, LB_ADDSTRING, 0, (LPARAM) TEXT("Заголовок 2"));
  SendMessage(hListBox, LB_ADDSTRING, 0, (LPARAM) TEXT("Заголовок 3"));
  
   return TRUE;
}

//
//  ФУНКЦИЯ: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  НАЗНАЧЕНИЕ:  обрабатывает сообщения в главном окне.
//
//  WM_COMMAND	- обработка меню приложения
//  WM_PAINT	-Закрасить главное окно
//  WM_DESTROY	 - ввести сообщение о выходе и вернуться.
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;
	RECT rect={100,100,100,100};
	TCHAR mainMessage[] = L"Текст для работы с диалоговыми окнами!";

	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;break;
	case WM_COMMAND:
		wmId    = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// Разобрать выбор в меню:
		switch (wmId)
		{	case IDC_BUTTON1:
			case IDM_ABOUT2:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG1), hWnd, About2);
			break;

			case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
			case IDC_BUTTON:
			case ID_32771:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG2), hWnd, Dial2);
			break;
			case IDC_BUTTON2:
			case ID_32772:
				ShowWindow(hWndD2, SW_NORMAL);
			UpdateWindow(hWndD2);
			ShowWindow(hListBox, WS_VISIBLE);break;
			case IDC_BUTTON3:
			case ID_32773:
				MessageBox(hWnd,L"Стандартный диалог",L"Внимание",MB_OK|MB_ICONWARNING);break;

		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;
		
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
        GetClientRect(hWnd,&rect); // получаем ширину и высоту области для рисования
        SetTextColor(hdc, colorText); // устанавливаем цвет контекстного устройства
        DrawText(hdc, mainMessage, -1, &rect, DT_SINGLELINE|DT_CENTER|DT_TOP); // рисуем текст
        EndPaint(hWnd, &ps); // заканчиваем рисовать
        break;
		// TODO: добавьте любой код отрисовки...
		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// Обработчик сообщений для окна "О программе".
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}

INT_PTR CALLBACK About2(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{	HWND hEdit1 = GetDlgItem(hDlg,IDC_EDIT1);
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		SendMessage(GetDlgItem(hDlg,IDC_SLIDER1),TBM_SETRANGE, TRUE, MAKELONG(1,100));
		SendMessage(GetDlgItem(hDlg,IDC_SLIDER1),TBM_SETPOS, TRUE, num);
	//	SendMessage(GetDlgItem(hDlg,IDC_EDIT1),WM_SETTEXT, 0,(LPARAM));
		return (INT_PTR)TRUE;
	case WM_HSCROLL:

		if (LOWORD(wParam) == SB_PAGERIGHT){
		num += 10;
		}

		if (LOWORD(wParam) == SB_PAGELEFT){
		num -= 10;
		
		}
		if (LOWORD(wParam) == SB_LINELEFT){
		num--;
		}
		if (LOWORD(wParam) == SB_LINERIGHT){
		num++;
		}
		if (LOWORD(wParam) == SB_THUMBTRACK){
		num = HIWORD(wParam);
		}
		SetScrollPos(GetDlgItem(hDlg,IDC_SLIDER1),SB_CTL,num,TRUE);
		wchar_t buffer[10];
		_itow_s(num,buffer,10);
		SetWindowText(hEdit1, buffer);
		colorText = RGB(num, 0, 0);
		UpdateWindow(hWnd);
		UpdateWindow(hDlg);
		break;
	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}

INT_PTR CALLBACK Dial2(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;	

	case WM_COMMAND:
if (LOWORD(wParam) == IDOK )
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
if (LOWORD(wParam) == IDC_BUTTON5){
char buf[250];
GetWindowText(GetDlgItem(hDlg,IDC_EDIT2),(LPWSTR)buf,250);
SendMessage(GetDlgItem(hDlg,IDC_LIST1),LB_ADDSTRING,0,(LPARAM)buf);
SetWindowText(GetDlgItem(hDlg,IDC_EDIT2),L"");
		if (LOWORD(wParam) == IDOK )
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
}
		
			
	}	
	return (INT_PTR)FALSE;

}

INT_PTR CALLBACK Dial3(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{	char Buf[256];
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
        {
            switch(LOWORD(wParam))
            {
                case IDC_LIST7:
                {
                    
                        if(HIWORD(wParam)==LBN_DBLCLK)
                        {
								ListItem1=(int)SendMessage(hListBox,LB_GETCURSEL,0,0);
                                SendMessage(hListBox,LB_GETTEXT,ListItem1,(LPARAM)Buf);
								SetWindowText(hWnd,(LPCWSTR)Buf);
							
                            return (INT_PTR)TRUE;
                        }
                    
				}break;}
			
		
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
		}}
	return (INT_PTR)FALSE;

}
	