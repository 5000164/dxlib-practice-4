#include "../Header/system.h"
#include "../Library/DxLib/DxLib.h"

namespace dx_system {

void System::Watch() {
  // �ُ폈���ŋ����I��
  if (ProcessMessage() == -1) {
    // DX���C�u�����g�p�I������
    DxLib_End();

    exit(1);
  }

  return;
}

}
