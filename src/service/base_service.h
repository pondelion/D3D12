#ifndef BASE_SERVICE_
#define BASE_SERVICE_


namespace service {

class Service {
 protected:
  Service() = default;

 public:
  Service(Service const &) = delete;
  Service& operator=(Service const &) = delete;

  static Service& Instance() {
    static Service instance_;
    return instance_;
  }
};

}

#endif
