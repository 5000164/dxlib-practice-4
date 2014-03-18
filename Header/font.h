#ifndef font_h
#define font_h

#include <string>

namespace font {

class Font {
public:
  Font();
  void Draw(std::string, int, int);

  int font_color_dx;

private:
  int font_color[3];
  double line_height;
  int shadow_color[3];
  int shadow_color_dx;
  int shadow_position[2];
};

}

#endif
