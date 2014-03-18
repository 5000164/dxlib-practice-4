#include "../Header/keyboard.h"
#include "../Library/DxLib/DxLib.h"
#include "../Header/system.h"

namespace keyboard {

  void Keyboard::WaitInputOnce() {
  dx_system::System *system = new dx_system::System();

  // �L�[���Ȃɂ�������Ă��Ȃ���ԂɂȂ�܂Ői�܂Ȃ�
  while (CheckHitKeyAll() != 0) {
    system->Watch();
  }

  // �L�[���Ȃɂ�������Ă����ԂɂȂ�܂Ői�܂Ȃ�
  while (CheckHitKeyAll() == 0) {
    system->Watch();
  }

  delete system;

  return;
}

bool Keyboard::IsPressEsc() {
  bool result = false;

  if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) {
    result = true;
  }

  return result;
}

bool Keyboard::IsPressReturn() {
  bool result = false;

  if (CheckHitKey(KEY_INPUT_RETURN) == 1) {
    result = true;
  }

  return result;
}

bool Keyboard::IsPressUp() {
  bool result = false;

  if (CheckHitKey(KEY_INPUT_UP) == 1) {
    result = true;
  }

  return result;
}

bool Keyboard::IsPressDown() {
  bool result = false;

  if (CheckHitKey(KEY_INPUT_DOWN) == 1) {
    result = true;
  }

  return result;
}

}
