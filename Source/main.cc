#include "../Library/DxLib/DxLib.h"
#include "../Header/window.h"
#include "../Header/json.h"
#include "../Header/rendering.h"
#include "../Header/keyboard.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
  // �\��������
  window:: Window *window = new window::Window();
  window->Init();

  // ���b�Z�[�W�ǂݍ���
  std::string message[256];
  json::Json *message_json = new json::Json("./Data/message.json");
  message_json->Init();
  message_json->GetStringArray("demo", message);
  delete message_json;

  // ���b�Z�[�W�\��
  rendering::Rendering *rendering = new rendering::Rendering();
  rendering->Message(message);
  delete rendering;

  //�@�L�[�{�[�h���͑ҋ@
  keyboard::Keyboard *keyboard = new keyboard::Keyboard();
  keyboard->WaitInputOnce();
  delete keyboard;

  // �\���I��
  delete window;

  return 0;
}
