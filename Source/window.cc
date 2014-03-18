#include "../Header/window.h"
#include "../Library/DxLib/DxLib.h"

namespace window {

Window::Window() {
  // �w�i�F�ݒ�
  r = 30;
  g = 30;
  b = 30;

  font_size = 18;
  font_family = "�l�r �o�S�V�b�N";
}

Window::~Window() {
  // DX���C�u�����g�p�I������
  DxLib_End();
}

void Window::Init() {
  // �E�B���h�E�Ŏ��s
  ChangeWindowMode(TRUE);

  // 1024x768px�A32bit�Ŏ��s
  SetGraphMode(1024, 768, 32);

  // �ُ폈���ŋ����I��
  if (DxLib_Init() == -1) {
    // DX���C�u�����g�p�I������
    DxLib_End();

    exit(1);
  }

  SetBackgroundColor(r, g, b);

  // �t�H���g�ύX�͏������d���̂ŃE�B���h�E���ɕύX
  ChangeFont(font_family.c_str());
  SetFontSize(font_size);
  ChangeFontType(DX_FONTTYPE_ANTIALIASING_8X8);
}

}
