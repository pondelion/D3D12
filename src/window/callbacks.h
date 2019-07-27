#ifndef CALLBACKS_
#define CALLBACKS_
#include <windows.h>


namespace window {

LRESULT CALLBACK MainWndProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp) {
  switch (msg) {
  case WM_CLOSE:
    if (MessageBox(hwnd, L"Exiting", L"Exit", MB_YESNO | MB_ICONQUESTION) == IDYES) {
      // Cleanup all resources here.
      DestroyWindow(hwnd);
    }
    return 0;
  case WM_DESTROY:
    PostQuitMessage(0);
    break;
  default:
    return DefWindowProc(hwnd, msg, wp, lp);
  }
  return DefWindowProc(hwnd, msg, wp, lp);
}

}

#endif
