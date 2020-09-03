// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include "pch.h"
#include "dllmain.h"

HWND _WORKERW = nullptr;

BOOL __stdcall EnumWindowsProc(HWND hwnd, LPARAM lParam) {
	HWND hNextWin;
	hNextWin = FindWindowExA(hwnd, 0, "SHELLDLL_DefView", 0);
	if (hNextWin) {
		if (GetNextWindow(hNextWin, GW_HWNDNEXT) || GetNextWindow(hNextWin, GW_HWNDPREV))
			return true;
		_WORKERW = FindWindowEx(0, hwnd, L"WorkerW", 0);
		return false;
	}
	return true;
}


HWND GetWorkerW() {
	HWND windowHandle = FindWindow(L"Progman", nullptr);
	if (nullptr == _WORKERW) {
		int result;
		SendMessageTimeout(windowHandle, 0x052c, 0, 0, SMTO_NORMAL, 0x3e8, (PDWORD_PTR)&result);
		EnumWindows(EnumWindowsProc, (LPARAM)nullptr);
	}
	return windowHandle;
}


DLLAPI BOOL  __stdcall SetDesktopWindow(HWND hwnd)
{
	HWND workerW = GetWorkerW();
	ShowWindow(_WORKERW, SW_HIDE);
	GetWindowLongA(hwnd, GWL_STYLE);
	SetParent(hwnd, workerW);
	ShowWindow(hwnd, SW_SHOWMAXIMIZED);
	return TRUE;
}

DLLAPI BOOL  __stdcall RecoverDesktopWindow(HWND hwnd)
{
	HWND workerW = GetWorkerW();
	ShowWindow(_WORKERW, SW_SHOW);
	SetParent((HWND)hwnd, GetDesktopWindow());
	return TRUE;
}

DLLAPI BOOL  __stdcall SetWindowVisiblity(HWND hwnd, BOOL show)
{
	return ShowWindow(hwnd, show ? SW_SHOW : SW_HIDE);
}

DLLAPI HWND __stdcall GetOriginalDesktopWorkerW()
{
	if (nullptr == _WORKERW) {
		HWND windowHandle = FindWindow(L"Progman", nullptr);
		int result;
		SendMessageTimeout(windowHandle, 0x052c, 0, 0, SMTO_NORMAL, 0x3e8, (PDWORD_PTR)&result);
		EnumWindows(EnumWindowsProc, (LPARAM)nullptr);
	}
	return _WORKERW;
}

DLLAPI BOOL __stdcall Test()
{
	return TRUE;
}