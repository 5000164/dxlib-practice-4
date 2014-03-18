#ifndef keyboard_h
#define keyboard_h

namespace keyboard {

class Keyboard {
public:
  void WaitInputOnce();
  bool IsPressEsc();
  bool IsPressReturn();
  bool IsPressUp();
  bool IsPressDown();
};

}

#endif
