#include "../Header/json.h"
#include <fstream>

namespace json {

Json::Json(std::string input_file) {
  this->input_file = input_file;
}

void Json::Init() {
  std::ifstream file;
  file.open(input_file.c_str());

  std::istreambuf_iterator<char> first(file);
  std::istreambuf_iterator<char> last;
  std::string json_str(first, last);

  picojson::parse(v, json_str.begin(), json_str.end(), &err);
}

std::string Json::GetString(std::string key) {
  picojson::object &o = v.get<picojson::object>();
  return o[key].get<std::string>();
}

void Json::GetStringArray(std::string key, std::string *message) {
  picojson::object &o = v.get<picojson::object>();
  picojson::array &a = o[key].get<picojson::array>();
  int counter = 0;
  for (picojson::array::iterator i = a.begin(); i != a.end(); i++) {
    message[counter] = i->get<std::string>();
    counter++;
  }
  return;
}

}
