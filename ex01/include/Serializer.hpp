#pragma once

#include <inttypes.h>

#include <string>

struct Data {
  int id;
  std::string name;
};

class Serializer {
 private:
  Serializer();

 public:
  static uintptr_t serialize(Data *ptr);
  static Data *deserialize(uintptr_t raw);
};
