#ifndef message_h
#define message_h

#include <string>
#include "./json.h"
#include "./point.h"

namespace message {

class Message {
public:
  Message(std::string, int, int, int, int);
  ~Message();
  void Init();
  void Run();

private:
  void MakeDrawScreen();
  void DrawScreen();
  void DrawBackground();
  void NextPage();

  std::string object_name;
  std::string font_family;
  int font_size;
  int font_width;
  int line_height;
  int margin_x;
  int margin_y;
  int r;
  int g;
  int b;
  int shadow_x;
  int shadow_y;
  int shadow_r;
  int shadow_g;
  int shadow_b;
  int font_color_dx;
  int shadow_color_dx;
  int number_of_data;
  std::string *message;
  int number_of_page;
  bool continuation_flag;
  point::Point *start;
  point::Point *end;
  point::Point *caret;
  int draw_screen;
};

}

#endif
