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

}
