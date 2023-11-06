#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    HWND hwnd = GetConsoleWindow();
    HDC hdc = GetDC(hwnd);

    int screen_width = GetSystemMetrics(SM_CXSCREEN);
    int screen_height = GetSystemMetrics(SM_CYSCREEN);
    int window_width = 750;
    int window_height = 500;

    MoveWindow(hwnd, (screen_width - window_width) / 2, (screen_height - window_height) / 2, 750, 500, true);

    HPEN pen = CreatePen(PS_SOLID, 1, RGB(0, 43, 127));
    HBRUSH brush = CreateSolidBrush(RGB(0, 43, 127));
    SelectObject(hdc, pen);
    SelectObject(hdc, brush);
    Rectangle(hdc, 0, 0, 250, 500);
    DeleteObject(pen);
    DeleteObject(brush);

    pen = CreatePen(PS_SOLID, 1, RGB(255, 255, 255));
    brush = CreateSolidBrush(RGB(255, 255, 255));
    SelectObject(hdc, pen);
    SelectObject(hdc, brush);
    Rectangle(hdc, 250, 0, 500, 500);
    DeleteObject(pen);
    DeleteObject(brush);

    pen = CreatePen(PS_SOLID, 1, RGB(206, 17, 38));
    brush = CreateSolidBrush(RGB(206, 17, 38));
    SelectObject(hdc, pen);
    SelectObject(hdc, brush);
    Rectangle(hdc, 500, 0, 750, 500);
    DeleteObject(pen);
    DeleteObject(brush);

    CONSOLE_CURSOR_INFO cci;
    cci.bVisible = false;
    cci.dwSize = 100;
    SetConsoleCursorInfo(h, &cci);
    Sleep(INFINITE);

    return 0;
}