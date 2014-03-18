#ifndef message_h
#define message_h

#include <string>
#include "./json.h"
#include "./point.h"

namespace message {

class Message {
public:
  Message(std::string);
  ~Message();
  void Init();
  void Run();

  std::string object_name;

private:
  json::Json *message_json;
  bool continuation_flag;
  point::Point *start;
  point::Point *end;
  point::Point *caret;
};

}

#endif
