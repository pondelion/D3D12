#ifndef SERVICE_PROVIDER_
#define SERVICE_PROVIDER_
#include <exception>
#include <memory>
#include <base_service.h>


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
      return WindowManager::Instance();
    case CoreServiceType::D3DManagerService:
      return D3DManager::Instance();
    default:
      throw std::runtime_error("invalid core service type");
    }
  }

};

}

#endif
