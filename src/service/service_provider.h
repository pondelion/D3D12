#ifndef SERVICE_PROVIDER_
#define SERVICE_PROVIDER_
#include <stdexcept>
#include <memory>
#include "base_service.h"
#include "window/window_manager.h"
#include "d3d/d3d_manager.h"


namespace service {


enum class CoreServiceType {
  WindowManagerService,
  D3DManagerService,
};


class ServiceProvider {
 protected:
  ServiceProvider() = default;

 public:
  ServiceProvider(ServiceProvider const &) = delete;
  ServiceProvider& operator=(ServiceProvider const &) = delete;

  static ServiceProvider& Instance() {
    static ServiceProvider instance_;
    return instance_;
  }
  Service& GetCoreService(CoreServiceType const svc_type) const {
    switch (svc_type)
    {
    case CoreServiceType::WindowManagerService:
      return window::WindowManager::Instance();
    case CoreServiceType::D3DManagerService:
      return d3d::D3DManager::Instance();
    default:
      throw std::runtime_error("invalid core service type");
    }
  }

};

}

#endif
