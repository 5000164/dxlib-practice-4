#include "../Library/DxLib/DxLib.h"
#include "../Header/window.h"
#include "../Header/message.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
  // �\��������
  window:: Window *window = new window::Window();
  window->Init();

  // ���b�Z�[�W�\��
  message::Message *message = new message::Message("demo", 20, 600, 1004, 748);
  message->Init();
  message->Run();
  delete message;

  // �\���I��
  delete window;

  return 0;
}
