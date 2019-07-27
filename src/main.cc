#include <memory>
#include <windows.h>
#include <service/service_provider.h>
#include <service/base_service.h>
#include <window/window_manager.h>
#include <d3d/d3d_manager.h>


int WINAPI WinMain(HINSTANCE hInstance,
                   HINSTANCE hPrevInstance,
                   LPSTR lpsCmdLine,
                   int nCmdShow) {
  using namespace service;

  const ServiceProvider& sp{ServiceProvider::Instance()};

  // Window initialization.
  using namespace window;
  HWND hwnd_main, hwnd_sub;
  const WindowManager& wm = static_cast<WindowManager&>(
    sp.GetCoreService(CoreServiceType::WindowManagerService)
  );
  hwnd_main = wm.CreateMainWindow();
  hwnd_sub = wm.CreateSubWindow();

  // D3D Setup
  using namespace d3d;
  const D3DManager& d3dm = static_cast<D3DManager&>(
    sp.GetCoreService(CoreServiceType::D3DManagerService)
  );
  d3dm.Initialize(hwnd_sub);
  d3dm.Run();
}