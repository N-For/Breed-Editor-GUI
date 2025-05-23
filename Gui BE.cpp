// Gui BE.cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include "Gui BE.h"
#include <Windows.h>
#include <fstream>
#include <string>
#include <direct.h>

#define MAX_LOADSTRING 100
#pragma comment(lib,"shell32")
using namespace std;
// Глобальные переменные:
HINSTANCE hInst;                                // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];            // имя класса главного окна

// Отправить объявления функций, включенных в этот модуль кода:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Разместите код здесь.

    // Инициализация глобальных строк
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_GUIBE, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_GUIBE));

    MSG msg;

    // Цикл основного сообщения:
    while (GetMessage(&msg, nullptr, 0, 0))
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
//  ЦЕЛЬ: Регистрирует класс окна.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON1));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_GUIBE);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_ICON2));

    return RegisterClassExW(&wcex);
}

//
//   ФУНКЦИЯ: InitInstance(HINSTANCE, int)
//
//   ЦЕЛЬ: Сохраняет маркер экземпляра и создает главное окно
//
//   КОММЕНТАРИИ:
//
//        В этой функции маркер экземпляра сохраняется в глобальной переменной, а также
//        создается и выводится главное окно программы.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Сохранить маркер экземпляра в глобальной переменной

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  ФУНКЦИЯ: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  ЦЕЛЬ: Обрабатывает сообщения в главном окне.
//
//  WM_COMMAND  - обработать меню приложения
//  WM_PAINT    - Отрисовка главного окна
//  WM_DESTROY  - отправить сообщение о выходе и вернуться
//
//
INT_PTR CALLBACK dg(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_CREATE:
        _mkdir("set");
        DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG1), hWnd, dg);
        DestroyWindow(hWnd);
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Разобрать выбор в меню:
            switch (wmId)
            {
            case IDM_ABOUT:
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: Добавьте сюда любой код прорисовки, использующий HDC...
            EndPaint(hWnd, &ps);
        }
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
INT_PTR CALLBACK dg(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{

    switch (message)
    {
    case WM_INITDIALOG:

    case WM_COMMAND:
 
            switch (int id = LOWORD(wParam)) {
            case IDC_BUTTON2:
            {
                system("explorer https://clck.ru/3EzXDS");
            }
            case IDC_BUTTON3:
            {
                system("start BE-modify.exe");
            }
            case IDC_BUTTON1:
            
                char k1[100];
                char k2[100];
                char k3[100];
                char k4[100];
                char k5[100];
                char k6[100];
                char k7[100];
                char k8[100];
                char k9[100];
                char k10[100];
                char k11[100];
                char k12[100];
                char k13[100];
                char k14[100];
                char k15[100];
                char k16[100];
                char k17[100];
                char k18[100];
                char k19[100];
                char k20[100];
                char k21[100];
                char k22[100];
                char k23[100];
                char k24[100];
                char k25[100];
                char k26[100];
                char k27[100];
                char k28[100];
                GetDlgItemTextA(hDlg, IDC_EDIT1, k1, 100);
                SetDlgItemTextA(hDlg, IDC_EDIT1, k1);
                GetDlgItemTextA(hDlg, IDC_EDIT2, k2, 100);
                SetDlgItemTextA(hDlg, IDC_EDIT2, k2);
                GetDlgItemTextA(hDlg, IDC_EDIT3, k3, 100);
                SetDlgItemTextA(hDlg, IDC_EDIT3, k3);
                GetDlgItemTextA(hDlg, IDC_EDIT4, k4, 100);
                SetDlgItemTextA(hDlg, IDC_EDIT4, k4);
                GetDlgItemTextA(hDlg, IDC_EDIT5, k5, 100);
                SetDlgItemTextA(hDlg, IDC_EDIT5, k5);
                GetDlgItemTextA(hDlg, IDC_EDIT6, k6, 100);
                SetDlgItemTextA(hDlg, IDC_EDIT6, k6);
                GetDlgItemTextA(hDlg, IDC_EDIT7, k7, 100);
                SetDlgItemTextA(hDlg, IDC_EDIT7, k7);
                GetDlgItemTextA(hDlg, IDC_EDIT8, k8, 100);
                SetDlgItemTextA(hDlg, IDC_EDIT8, k8);
                GetDlgItemTextA(hDlg, IDC_EDIT9, k9, 100);
                SetDlgItemTextA(hDlg, IDC_EDIT9, k9);
                GetDlgItemTextA(hDlg, IDC_EDIT10, k10, 100);
                SetDlgItemTextA(hDlg, IDC_EDIT10, k10);
                GetDlgItemTextA(hDlg, IDC_EDIT11, k11, 100);
                SetDlgItemTextA(hDlg, IDC_EDIT11, k11);
                GetDlgItemTextA(hDlg, IDC_EDIT12, k12, 100);
                SetDlgItemTextA(hDlg, IDC_EDIT12, k12);
                GetDlgItemTextA(hDlg, IDC_EDIT13, k13, 100);
                SetDlgItemTextA(hDlg, IDC_EDIT13, k13);
                GetDlgItemTextA(hDlg, IDC_EDIT14, k14, 100);
                SetDlgItemTextA(hDlg, IDC_EDIT14, k14);
                GetDlgItemTextA(hDlg, IDC_EDIT15, k15, 100);
                SetDlgItemTextA(hDlg, IDC_EDIT15, k15);
                GetDlgItemTextA(hDlg, IDC_EDIT16, k16, 100);
                SetDlgItemTextA(hDlg, IDC_EDIT16, k16);
                GetDlgItemTextA(hDlg, IDC_EDIT17, k17, 100);
                SetDlgItemTextA(hDlg, IDC_EDIT17, k17);
                GetDlgItemTextA(hDlg, IDC_EDIT18, k18, 100);
                SetDlgItemTextA(hDlg, IDC_EDIT18, k18);
                GetDlgItemTextA(hDlg, IDC_EDIT19, k19, 100);
                SetDlgItemTextA(hDlg, IDC_EDIT19, k19);
                GetDlgItemTextA(hDlg, IDC_EDIT20, k20, 100);
                SetDlgItemTextA(hDlg, IDC_EDIT20, k20);
                GetDlgItemTextA(hDlg, IDC_EDIT21, k21, 100);
                SetDlgItemTextA(hDlg, IDC_EDIT21, k21);
                GetDlgItemTextA(hDlg, IDC_EDIT22, k22, 100);
                SetDlgItemTextA(hDlg, IDC_EDIT22, k22);
                GetDlgItemTextA(hDlg, IDC_EDIT23, k23, 100);
                SetDlgItemTextA(hDlg, IDC_EDIT23, k23);
                GetDlgItemTextA(hDlg, IDC_EDIT24, k24, 100);
                SetDlgItemTextA(hDlg, IDC_EDIT24, k24);
                GetDlgItemTextA(hDlg, IDC_EDIT25, k25, 100);
                SetDlgItemTextA(hDlg, IDC_EDIT25, k25);
                GetDlgItemTextA(hDlg, IDC_EDIT26, k26, 100);
                SetDlgItemTextA(hDlg, IDC_EDIT26, k26);
                GetDlgItemTextA(hDlg, IDC_EDIT27, k27, 100);
                SetDlgItemTextA(hDlg, IDC_EDIT27, k27);
                GetDlgItemTextA(hDlg, IDC_EDIT28, k28, 100);
                SetDlgItemTextA(hDlg, IDC_EDIT28, k28);
                ofstream l("liber.for");
                l << k1 << endl;
                l << k2 << endl;
                l << k3 << endl;
                l << k4 << endl;
                l << k5 << endl;
                l << k6 << endl;
                l << k7 << endl;
                l << k8 << endl;
                l << k9 << endl;
                l << k10 << endl;
                l << k11 << endl;
                l << k12 << endl;
                l << k13 << endl;
                l << k14 << endl;
                l << k15 << endl;
                l << k16 << endl;
                l << k17 << endl;
                l << k18 << endl;
                l << k19 << endl;
                l << k20 << endl;
                l << k21 << endl;
                l << k22 << endl;
                l << k23 << endl;
                l << k24 << endl;
                l << k25 << endl;
                l << k26 << endl;
                l << k27 << endl;
                l << k28 << endl;
                l.close();
                string  a[30];
                fstream c("liber.for");
                for (int x = 0;x <= 28;x++) {
                    getline(c, a[x]);
                }
                a[5] ="set/"+ a[5] + ".set";
                ofstream k(a[5]);
                k << "{breed\n";
                k << "\t{behaviour "+a[0]+"}\n";
                k << "\t{skin \"" + a[1] + "\"}\n";
                k << "\t{portrait " + a[25] + "}\n";
                k << "\t{icon " + a[2] + "}\n";
                k << "\t{icon_priority 0}\n";
                k << "\t{tags \"" + a[3] + "\"}\n";
                k << "\t{nationality " + a[4] + "}\n";
                k << "\t{voice " + a[4] + "}\n";
                k << "\t{armors\n";
                k << "\t\t{head " + a[6] + "}\n";
                k << "\t}\n";
                k << "\t{perks\n";
                k << "\t\t{\"rifle\" lvl_" + a[7] + "}\n";
                k << "\t\t{\"melee\" lvl_" + a[13] + "}\n";
                k << "\t\t{\"pistol\" lvl_" + a[8] + "}\n";
                k << "\t\t{\"smg\" lvl_" + a[9] + "}\n";
                k << "\t\t{\"mgun\" lvl_" + a[10] + "}\n";
                k << "\t\t{\"rocketlauncher\" lvl_" + a[12] + "}\n";
                k << "\t\t{\"at_rifle\" lvl_" + a[11] + "}\n";

                k << "\t\t{\"speed\" " + a[14] + "}\n";
                k << "\t\t{\"stamina\" \"" + a[15] + "%\"}\n";
                k << "\t\t{\"stamina_regeneration\" \"" + a[17] + "%\"}\n";
                k << "\t\t{\"health\" \"" + a[16] + "%\"}\n";
                k << "\t\t{\"health_regeneration\" \"" + a[18] + "%\"}\n";
                k << "\t}\n";
                k << "\t{veterancy\n";

                k << "\t\t{\"lvl_1\" " + a[19] + "}\n";
                k << "\t\t{\"lvl_2\" " + a[20] + "}\n";
                k << "\t\t{\"lvl_3\" " + a[21] + "}\n";
                k << "\t\t{\"lvl_4\" " + a[22] + "}\n";
                k << "\t\t{\"lvl_5\" " + a[23] + "}\n";
                k << "\t}\n";
                k << "\t{inventory\n";
                k << "\t\t{item \""+a[26]+"\"}\n";
                k << "\t\t{item \"" + a[27] + " ammo\"\ "+a[24]+" }\n";
                k << "\t}\n";
                k << "}\n\n\n\n\n\n\n\n\n\n\n";
                k.close();
}              

            /*l << k1;
            string k2;
        */
        
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            remove("liber.for");
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
