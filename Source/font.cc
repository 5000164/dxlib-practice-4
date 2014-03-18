#include "../Header/font.h"
#include "../Library/DxLib/DxLib.h"

namespace font {

Font::Font() {
  font_color[0] = 230;
  font_color[1] = 230;
  font_color[2] = 230;
  line_height = 1.73;
  shadow_color[0] = 5;
  shadow_color[1] = 5;
  shadow_color[2] = 5;
  shadow_position[0] = 0;
  shadow_position[1] = 2;
  font_color_dx = GetColor(font_color[0], font_color[1], font_color[2]);
  shadow_color_dx = GetColor(shadow_color[0], shadow_color[1], shadow_color[2]);
}

void Font::Draw(std::string text, int x, int y) {
  DrawString(x, y, text.c_str(), font_color_dx);

  return;
}

}
