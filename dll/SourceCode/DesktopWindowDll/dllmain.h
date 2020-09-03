#pragma once
#ifndef DLLAPI
#define DLLAPI extern "C" __declspec(dllexport)
#endif

	DLLAPI BOOL __stdcall Test();
	DLLAPI BOOL  __stdcall SetDesktopWindow(HWND hwnd);
	DLLAPI BOOL  __stdcall RecoverDesktopWindow(HWND hwnd);
	DLLAPI BOOL  __stdcall SetWindowVisiblity(HWND hwnd,BOOL show);
	DLLAPI HWND __stdcall GetOriginalDesktopWorkerW();




