#include <Windows.h>
#include "Window.h"
#include "Renderer.h"

int CALLBACK WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow ) {

		Window window(1024, 768);
		Renderer renderer(window);
		MSG msg = { 0 };
		while(true) {
			if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE)) {
				TranslateMessage(&msg);
				DispatchMessage(&msg);

				if (msg.message == WM_QUIT) break;
			}	
		}
		return 0;

}