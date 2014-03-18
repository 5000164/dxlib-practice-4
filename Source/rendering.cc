#include "../Header/rendering.h"
#include "../Library/DxLib/DxLib.h"
#include "../Header/font.h"

namespace rendering {

void Rendering::Message(std::string *message) {
  font::Font *font = new font::Font();

  SetDrawScreen(DX_SCREEN_BACK);
  ClearDrawScreen();

  font->Draw(message[0], 50, 50);
  font->Draw(message[1], 50, 50);
  font->Draw(message[2], 50, 50);

  ScreenFlip();

  return;
}

}
