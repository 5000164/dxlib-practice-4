#ifndef json_h
#define json_h

#include <string>
#include "../Library/picojson.h"

namespace json {

class Json {
public:
  Json(std::string);
  void Init();

  picojson::value v;

private:
  std::string input_file;
  std::string err;
};

}

#endif
