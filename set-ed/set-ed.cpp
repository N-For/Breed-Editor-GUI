// set-ed.cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include "set-ed.h"
#include <Windows.h>
#include <fstream>
#include <string>
#include <direct.h>
#include <commdlg.h>


using namespace std;
#define MAX_LOADSTRING 100
#define CRT_SECURE_NO_WARNINGS
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
    LoadStringW(hInstance, IDC_SETED, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_SETED));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_SETED));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_SETED);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}/*
ATOM MyRegisterClass1(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_SETED));
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_SETED);
    wcex.lpszClassName = szWindowClass;
    wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}*/

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

   //HWND hWnd1 = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
     //  CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

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
        DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG1), hWnd, dg);

        DestroyWindow(hWnd);
       
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Разобрать выбор в меню:
            switch (wmId)
            {

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
static int n;
string k;
static wchar_t* test;
static wchar_t* test1;
static wchar_t* test2;
int x0 = 0;
HWND hEdit;
OPENFILENAME ofn;
int j = 0;

// a another memory buffer to contain the file name
wchar_t szFile[1000];
const char *strLocal[] = {"rus_RUS.1251","rus_RUS.UTF-8","rus_RUS.866"};

INT_PTR CALLBACK dg(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    
    /*static OPENFILENAME file;
    static HWND hEdit;
    static wchar_t name[256];
    int m, k;;
    static wchar_t* szText;;
    file.lStructSize = sizeof(OPENFILENAME);
    HINSTANCE hlnst;
    file.hInstance = hlnst;
    file.lpstrFile = name;
    */switch (message)
    {
    case WM_INITDIALOG:
    case WM_COMMAND:
        if (x0 == 0) {
            hEdit = CreateWindowEx(WS_EX_STATICEDGE, L"edit", NULL, WS_CHILD | WS_VISIBLE | WS_VSCROLL | ES_MULTILINE | ES_AUTOVSCROLL, 10, 100, 520, 300, hDlg, (HMENU)1001, NULL, NULL);
            x0 = 1;
        }
        switch (int id = LOWORD(wParam)) {
        
        case IDC_BUTTON4:
        {

            char k3[150];
            GetDlgItemTextA(hDlg, IDC_EDIT1, k3, 150);
            SetDlgItemTextA(hDlg, IDC_EDIT1, k3);
            ofstream l1("file.for");
            l1 << k3;
            l1.close();
            fstream l("file.for");
            getline(l, k);
            l << k;
            string k1 = "set/" + k;
            k1 = k1 + ".set";
            l.close();
            char xc1[100];
            strcpy_s(xc1, k1.c_str());
            remove(xc1);

            break;
        }
        case IDC_BUTTON3:
        {
            _mkdir("set");

            char k3[150];
            GetDlgItemTextA(hDlg, IDC_EDIT1, k3, 150);
            SetDlgItemTextA(hDlg, IDC_EDIT1, k3);
            ofstream l1("file.for");
            l1 << k3;
            l1.close();
            fstream l("file.for");
            getline(l, k);
            l << k;
            string k1 = "set/" + k;
            k1 = k1 + ".set";
            l.close();
            ofstream newf(k1);
            newf << "{breed\n}\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
            newf.close();

            wifstream in1;
            in1.open(k1, ios::binary);
            test1 = new wchar_t[0x3ffd];
            in1.read(test1, 0x3ffd);
            in1.close();
            //ofstream cv("да.т");
            //cv << k;
            SetWindowText(hEdit, test1);
            char xc[100];
            strcpy_s(xc, k.c_str());
            SetDlgItemTextA(hDlg, IDC_EDIT1, xc);
            break;
        }
        case IDC_BUTTON2:
        {
            char k4[200];
            GetDlgItemTextA(hDlg, IDC_EDIT1, k4, 150);
            SetDlgItemTextA(hDlg, IDC_EDIT1, k4);
            ofstream l1("file.for");
            l1 << k4;
            l1.close();
            fstream l("file.for");
            getline(l, k);
            l << k;
           /* string k2 = "set/" + k;
            k2 = k2 + ".set";
            */l.close();
            
            
            wofstream out;
            out.open(k,ios::binary);
            n = GetWindowText(hEdit,test,0x71fcf);
            out.write(test, n);
            out.close();
            break;
        }
        case IDC_BUTTON7:
        {
             ZeroMemory(&ofn, sizeof(ofn));
   ofn.lStructSize = sizeof(ofn);
   ofn.hwndOwner = NULL;
   ofn.lpstrFile = szFile;
   ofn.lpstrFile[0] = '\0';
   ofn.nMaxFile = sizeof(szFile);
   ofn.lpstrFilter = L"All\0*.*\0Text\0*.TXT\0";
   ofn.nFilterIndex = 1;
   ofn.lpstrFileTitle = NULL;
   ofn.nMaxFileTitle = 0;
   ofn.lpstrInitialDir = NULL;
   ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

       

        GetOpenFileName(&ofn);

        char libfor[1000];
        wcstombs(libfor, szFile, 1000);
        SetDlgItemTextA(hDlg, IDC_EDIT1, libfor);

            break;
        }
        case IDC_BUTTON1:

           
           wifstream in;
           in.imbue(locale(strLocal[0]));
           in.open(k, ios::binary);

           test = new wchar_t[0x71fcf];
           in.read(test, 0x71fcf);
           in.close();
           SetWindowText(hEdit, test);


  char k1[150];
            char k2[100];
            GetDlgItemTextA(hDlg, IDC_EDIT1, k1, 150);
            SetDlgItemTextA(hDlg, IDC_EDIT1, k1);
            ofstream l("file.for");
            l << k1;
            l.close();
            fstream l1("file.for");
            
            getline(l1, k);
            l1.close();
            static int n;
            
            in.open(k,ios::binary);
            
            test = new wchar_t[0x7fff];
            in.read(test, 0x7fff);
            //test[n] = L'\0';
            in.close();
            SetWindowText(hEdit, test);
            
            /*fstream l3(k);
            string lib;
            char file[10000];
            
            /*for (int i = 0;i <= 50;i++) {
                getline(l3, lib);
              //      lib=lib+"\n";
            }
            
            l3.close();
            */
            /*strcpy_s(file, lib.c_str());
            SetDlgItemTextA(hDlg, IDC_EDIT3, file);
            */
            /*char g[150];
            char g1[150];
            char g2[150];
            char g3[150];
            char g4[150];
            char g5[150];
            char g6[150];
            char g7[150];
            char g8[150];
            char g9[150];
            char g10[150];
            char g11[150];
            char g12[150];
            char g13[150];
            char g14[150];
            char g15[150];
            char g16[150];
            char g17[150];
            char g18[150];
            char g19[150];
            char g20[150];
            char g21[150];
            char g22[150];
            char g23[150];
            char g24[150];
            char g25[150];
            char g26[150];
            char g27[150];
            char g28[150];
            char g29[150];
            char g30[150];
            char g31[150];
            char g32[150];
            char g33[150];
            char g34[150];
            char g35[150];
            char g36[150];
            char g37[150];
            char g38[150];
            char g39[150];
            char g40[150];
            char g41[150];
            char g42[150];
            char g43[150];
            char g44[150];
            char g45[150];
            char g46[150];
            char g47[150];
            char g48[150];
            char g49[150];
            strcpy_s(g, lib[0].c_str());
            strcpy_s(g1, lib[1].c_str());
            strcpy_s(g2, lib[2].c_str());
            strcpy_s(g3, lib[3].c_str());
            strcpy_s(g4, lib[4].c_str());
            strcpy_s(g5, lib[5].c_str());
            strcpy_s(g6, lib[6].c_str());
            strcpy_s(g7, lib[7].c_str());
            strcpy_s(g8, lib[8].c_str());
            strcpy_s(g9, lib[9].c_str());
            strcpy_s(g10, lib[10].c_str());
            strcpy_s(g11, lib[11].c_str());
            strcpy_s(g12, lib[12].c_str());
            strcpy_s(g13, lib[13].c_str());
            strcpy_s(g14, lib[14].c_str());
            strcpy_s(g15, lib[15].c_str());
            strcpy_s(g16, lib[16].c_str());
            strcpy_s(g17, lib[17].c_str());
            strcpy_s(g18, lib[18].c_str());
            strcpy_s(g19, lib[19].c_str());
            strcpy_s(g20, lib[20].c_str());
            strcpy_s(g21, lib[21].c_str());
            strcpy_s(g22, lib[22].c_str());
            strcpy_s(g23, lib[23].c_str());
            strcpy_s(g24, lib[24].c_str());
            strcpy_s(g25, lib[25].c_str());
            strcpy_s(g26, lib[26].c_str());
            strcpy_s(g27, lib[27].c_str());
            strcpy_s(g28, lib[28].c_str());
            strcpy_s(g29, lib[29].c_str());
            strcpy_s(g30, lib[30].c_str());
            strcpy_s(g31, lib[31].c_str());
            strcpy_s(g32, lib[32].c_str());
            strcpy_s(g33, lib[33].c_str());
            strcpy_s(g34, lib[34].c_str());
            strcpy_s(g35, lib[35].c_str());
            strcpy_s(g36, lib[36].c_str());
            strcpy_s(g37, lib[37].c_str());
            strcpy_s(g38, lib[38].c_str());
            strcpy_s(g39, lib[39].c_str());
            strcpy_s(g40, lib[40].c_str());
            strcpy_s(g41, lib[41].c_str());
            strcpy_s(g42, lib[42].c_str());
            strcpy_s(g43, lib[43].c_str());
            strcpy_s(g44, lib[44].c_str());
            strcpy_s(g45, lib[45].c_str());
            strcpy_s(g46, lib[46].c_str());
            strcpy_s(g47, lib[47].c_str());
            strcpy_s(g48, lib[48].c_str());
            strcpy_s(g49, lib[49].c_str());
            
            SetWindowText(te, g);*/

            //            for (int i = 0;i <= 50;i++) {
                //SetDlgItemTextA(hDlg, IDC_EDIT2, g);
            


  //          }
            

            break;
        }



        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            remove("file.for");
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}