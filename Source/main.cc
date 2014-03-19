#include "../Library/DxLib/DxLib.h"
#include "../Header/window.h"
#include "../Header/message.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
  // 表示初期化
  window:: Window *window = new window::Window();
  window->Init();

  // メッセージ表示
  message::Message *message = new message::Message("demo", 20, 600, 1004, 748);
  message->Init();
  message->Run();
  delete message;

  // 表示終了
  delete window;

  return 0;
}
