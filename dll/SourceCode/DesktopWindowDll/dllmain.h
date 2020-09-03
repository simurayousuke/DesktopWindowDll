#pragma once
#ifndef DLLAPI
#define DLLAPI extern "C" _declspec(dllexport)
#endif
namespace DesktopWindow {
	HWND _WORKERW;
	DLLAPI BOOL __stdcall Test();
	DLLAPI BOOL  __stdcall SetDesktopWindow(HWND viewId);
	DLLAPI BOOL  __stdcall RecoverDesktopWindow(HWND viewId);
}