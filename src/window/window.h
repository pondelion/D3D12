#ifndef WINDOW_
#define WINDOW_
#include <windows.h>
#include <string>


namespace window {

enum class WindowType {
  MainWindow,
  SubWindow
};

class Window {

 private:
  std::string tag_;
  WindowType window_type_;
  HWND hwnd_;
  RECT rect_;
};

}

#endif
