
LRESULT CALLBACK
WindowProc(HWND
hwnd,
UINT uMsg, WPARAM
wParam,
LPARAM lParam
) {
switch (uMsg) {
case WM_CLOSE:
PostQuitMessage(0);
break;

case WM_DESTROY:
return 0;
case WM_KEYDOWN: {
switch (wParam) {
case VK_ESCAPE:
PostQuitMessage(0);
break;
case VK_RIGHT:
MOVE = 0;
break;
case VK_UP:
MOVE = 1;
break;
case VK_LEFT:
MOVE = 2;
break;
case VK_DOWN:
MOVE = 3;
break;
case VK_RETURN:
ENTER = true;
default:
break;
}
}
break;

default:
return
DefWindowProc(hwnd, uMsg, wParam, lParam
);
}
return 0;
}