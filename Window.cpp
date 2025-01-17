#include <Windows.h>
#include "Window.h"

LRESULT CALLBACK WinProc(HWND handle, UINT msg, WPARAM wparam, LPARAM lparam) {
    if (msg == WM_DESTROY ||
        msg == WM_CLOSE) {
        PostQuitMessage(0);
        return 0;
    }

    return DefWindowProc(handle, msg, wparam, lparam);
}

Window::Window(int width, int height) {
    WNDCLASS wc = { 0 };
    wc.style = CS_OWNDC;
    wc.lpfnWndProc = WinProc;
    wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wc.lpszClassName = L"DX Demo App";
    RegisterClass(&wc);

    m_handle = CreateWindowW(L"DX Demo App", L"DX Demo App",
        WS_POPUP | WS_CAPTION | WS_SYSMENU | WS_VISIBLE,
        100, 100, width, height,
        nullptr, nullptr, nullptr, nullptr);
}

HWND Window::getHandle() {
    return m_handle;
}