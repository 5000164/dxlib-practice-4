#include "../Header/message.h"
#include "../Library/DxLib/DxLib.h"
#include "../Header/json.h"
#include "../Header/system.h"
#include "../Header/keyboard.h"

namespace message {

Message::Message(std::string object_name) {
  this->object_name = object_name;
  continuation_flag = true;
}

Message::~Message() {
  delete start;
  delete end;
  delete caret;
  delete message_json;
}

void Message::Init() {
  start = new point::Point(20, 600);
  end = new point::Point(1024 - 20, 768 - 20);
  caret = new point::Point(0, 0);
  message_json = new json::Json("./Data/message.json");
  message_json->Init();
}

void Message::Run() {
  picojson::object &o = message_json->v.get<picojson::object>();
  picojson::object &demo = o["demo"].get<picojson::object>();

  std::string test = demo["1"].get<std::string>();



  SetDrawScreen(DX_SCREEN_BACK);
  ClearDrawScreen();

  int Cr;
  Cr = GetColor(50, 50, 50);
  DrawBox(start->x, start->y, end->x, end->y, Cr, TRUE);
  Cr = GetColor(250, 250, 250);
  DrawBox(start->x, start->y, end->x, end->y, Cr, FALSE);

  int font_size = 20;
  int font_width = 20;
  int line_height = (int)round(font_size * 1.73);
  std::string font_family = "ÇlÇr ÉSÉVÉbÉN";

  ChangeFont(font_family.c_str());
  SetFontSize(font_size);
  ChangeFontType(DX_FONTTYPE_ANTIALIASING_8X8);

  int margin_x;
  int margin_y;
  int r;
  int g;
  int b;
  int shadow_r;
  int shadow_g;
  int shadow_b;
  int shadow_x;
  int shadow_y;
  int font_color_dx;
  int shadow_color_dx;
  margin_x = 20;
  margin_y = 10;
  r = 230;
  g = 230;
  b = 230;
  shadow_r = 5;
  shadow_g = 5;
  shadow_b = 5;
  shadow_x = 0;
  shadow_y = 2;
  font_color_dx = GetColor(r, g, b);
  shadow_color_dx = GetColor(shadow_r, shadow_g, shadow_b);



  for (int i = 0; i < (int)test.size(); i += 2) {
    char c[3];
    c[0] = test[i];
    c[1] = test[i + 1];
    c[2] = '\0';

    int x = start->x + margin_x + (caret->x * font_width);
    int y = start->y + margin_y + (caret->y * line_height) + ((line_height - font_size) / 2);

    if (x + font_width + margin_x > end->x) {
      caret->x = 0;
      caret->y++;
      x = start->x + margin_x + (caret->x * font_width);
      y = start->y + margin_y + (caret->y * line_height) + ((line_height - font_size) / 2);
    }

    if (y + font_size + ((line_height - font_size) / 2) + margin_y > end->y) {
    } else {
      DrawString(x, y, c, font_color_dx);
    }

    caret->x++;
  }

  ScreenFlip();



  dx_system::System *system = new dx_system::System();
  keyboard::Keyboard *keyboard = new keyboard::Keyboard();

  while (continuation_flag) {
    system->Watch();
    keyboard->WaitInputOnce();

    if (keyboard->IsPressReturn()) {
      continuation_flag = false;
    }
  }

  delete keyboard;
  delete system;

  return;
}

}
