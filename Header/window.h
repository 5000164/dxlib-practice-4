#ifndef window_h
#define window_h

#include <string>

namespace window {

class Window {
public:
  Window();
  ~Window();
  void Init();

private:
  int r;
  int g;
  int b;
};

}

#endif
