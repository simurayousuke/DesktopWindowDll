# DesktopWindow.dll

本动态链接库所有函数均采用stdcall方式调用。

|函数名|入口点|返回值|参数|说明|
|----|----|----|----|----|
|Test|_Test@0|BOOL||测试是否载入成功，永远返回true|
|SetDesktopWindow|_SetDesktopWindow@4|BOOL|HWND hwnd|hwnd为窗口句柄，将该窗口设置为桌面|
|RecoverDesktopWindow|_RecoverDesktopWindow@4|BOOL|HWND hwnd|hwnd为窗口句柄，将该窗口从桌面摘除|
|SetWindowVisiblity|_SetWindowVisiblity@8|BOOL|HWND hwnd , BOOL show|hwnd为窗口句柄，show为true时显示该窗口，false时隐藏该窗口|
|GetOriginalDesktopWorkerW|_GetOriginalDesktopWorkerW@0|HWND||获取桌面壁纸的WorkerW窗口句柄|
