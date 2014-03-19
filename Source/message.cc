#include "../Header/message.h"
#include "../Library/DxLib/DxLib.h"
#include "../Header/json.h"
#include "../Header/system.h"
#include "../Header/keyboard.h"

namespace message {

Message::Message(std::string object_name, int start_x, int start_y, int end_x, int end_y) {
  this->object_name = object_name;
  start = new point::Point(start_x, start_y);
  end = new point::Point(end_x, end_y);
  number_of_page = 1;
  caret = new point::Point(0, 0);

  font_family = "‚l‚r ƒSƒVƒbƒN";
  font_size = 20;
  font_width = 20;
  line_height = (int)round(font_size * 1.73);
  margin_x = 20;
  margin_y = 10;
  r = 230;
  g = 230;
  b = 230;
  shadow_x = 0;
  shadow_y = 2;
  shadow_r = 5;
  shadow_g = 5;
  shadow_b = 5;
}

Message::~Message() {
  delete start;
  delete end;
  delete caret;
  delete[] message;
}

void Message::Init() {
  font_color_dx = GetColor(r, g, b);
  shadow_color_dx = GetColor(shadow_r, shadow_g, shadow_b);
  
  json::Json *message_json = new json::Json("./Data/message.json");
  message_json->Init();
  picojson::object &o = message_json->v.get<picojson::object>();
  picojson::object &info = o["info"].get<picojson::object>();
  picojson::object &demo = o[object_name].get<picojson::object>();
  number_of_data = (int)info[object_name].get<double>();
  message = new std::string[number_of_data];
  for (int i = 0; i < number_of_data; i++) {
    message[i] = demo[std::to_string(i)].get<std::string>();
  }
  delete message_json;

  ChangeFontType(DX_FONTTYPE_ANTIALIASING_8X8);
  ChangeFont(font_family.c_str());
  SetFontSize(font_size);
}

void Message::Run() {
  SetDrawScreen(DX_SCREEN_BACK);
  ClearDrawScreen();
  DrawBackground();

  dx_system::System *system = new dx_system::System();

  for (int i = 0; i < number_of_data; i++) {
    for (int j = 0; j < (int)message[i].size(); j += 2) {
      system->Watch();

      char c[3];
      c[0] = message[i][j];
      c[1] = message[i][j + 1];
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
        NextPage();
      } else {
        DrawString(x, y, c, font_color_dx);
        caret->x++;
      }
    }
    NextPage();
  }

  delete system;

  return;
}

void Message::DrawBackground() {
  int color;
  color = GetColor(50, 50, 50);
  DrawBox(start->x, start->y, end->x, end->y, color, TRUE);
  color = GetColor(250, 250, 250);
  DrawBox(start->x, start->y, end->x, end->y, color, FALSE);
  color = GetColor(230, 230, 230);
  DrawTriangle(end->x - 30, end->y - 20, end->x - 10, end->y - 20, end->x - 20, end->y - 10, color, TRUE);

  return;
}

void Message::NextPage() {
  caret->x = 0;
  caret->y = 0;
  number_of_page++;

  keyboard::Keyboard *keyboard = new keyboard::Keyboard();

  ScreenFlip();
  keyboard->WaitInputOnce();
  SetDrawScreen(DX_SCREEN_BACK);
  ClearDrawScreen();
  DrawBackground();

  delete keyboard;

  return;
}

}
