#ifndef WINDOW_MANAGER_
#define WINDOW_MANAGER_
#include <vector>
#include "service/base_service.h"


namespace window {

class WindowManager : public service::Service {
 public:
  HWND CreateMainWindow();

 private:
  std::vector<Window> windows_;
};


}

#endif