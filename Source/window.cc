#include "../Header/window.h"
#include "../Library/DxLib/DxLib.h"

namespace window {

Window::Window() {
  // 背景色設定
  r = 30;
  g = 30;
  b = 30;
}

Window::~Window() {
  // DXライブラリ使用終了処理
  DxLib_End();
}

void Window::Init() {
  // ウィンドウで実行
  ChangeWindowMode(TRUE);

  // 1024x768px、32bitで実行
  SetGraphMode(1024, 768, 32);

  // 異常処理で強制終了
  if (DxLib_Init() == -1) {
    // DXライブラリ使用終了処理
    DxLib_End();

    exit(1);
  }

  SetBackgroundColor(r, g, b);
  LoadGraphScreen(0, 0, "./Data/background.jpg", FALSE);
}

}
