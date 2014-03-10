#include <windows.h>

LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance,
				   HINSTANCE hPrevInstance,
				   LPSTR lpCmdLine,
				   int nShowCmd) {

	HWND hWnd;

	WNDCLASSEX wc;

	ZeroMemory(&wc, sizeof(WNDCLASSEX));

	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = WindowProc;
	wc.hInstance = hInstance;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH) COLOR_WINDOW;
	wc.lpszClassName = L"Try DX11 in desktop";

	RegisterClassEx(&wc);

	hWnd = CreateWindowEx(NULL,wc.lpszClassName,L"Try DX11 in desktop",WS_OVERLAPPEDWINDOW,200,200,
						  640,400,NULL,NULL,hInstance,NULL);
	
	ShowWindow(hWnd,nShowCmd);

	MSG message;

	while (GetMessage(&message, NULL, 0, 0)) {
		TranslateMessage(&message);
		DispatchMessage(&message);
	}
	return message.wParam;
}

LRESULT CALLBACK WindowProc(HWND hWnd,UINT message,WPARAM wParam,LPARAM lParam) {
	switch (message) {
		case WM_DESTROY:{
			PostQuitMessage(0);
			return 0;
		}
		default:
			break;
	}
	return DefWindowProc(hWnd, message, wParam, lParam);
}