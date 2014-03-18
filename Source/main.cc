#include "../Library/DxLib/DxLib.h"
#include "../Header/window.h"
#include "../Header/json.h"
#include "../Header/rendering.h"
#include "../Header/keyboard.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
  // 表示初期化
  window:: Window *window = new window::Window();
  window->Init();

  // メッセージ読み込み
  std::string message[256];
  json::Json *message_json = new json::Json("./Data/message.json");
  message_json->Init();
  message_json->GetStringArray("demo", message);
  delete message_json;

  // メッセージ表示
  rendering::Rendering *rendering = new rendering::Rendering();
  rendering->Message(message);
  delete rendering;

  //　キーボード入力待機
  keyboard::Keyboard *keyboard = new keyboard::Keyboard();
  keyboard->WaitInputOnce();
  delete keyboard;

  // 表示終了
  delete window;

  return 0;
}
