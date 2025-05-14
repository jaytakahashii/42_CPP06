#include <iostream>

#include "Serializer.hpp"

int main() {
  Data original;
  original.id = 42;
  original.name = "OpenAI";

  uintptr_t raw = Serializer::serialize(&original);
  Data* copy = Serializer::deserialize(raw);

  std::cout << "Original ptr: " << &original << std::endl;
  std::cout << "Deserialized ptr: " << copy << std::endl;

  std::cout << "ID: " << copy->id << ", Name: " << copy->name << std::endl;

  if (copy == &original) {
    std::cout << "✅ Pointer match: Deserialization successful" << std::endl;
  } else {
    std::cout << "❌ Pointer mismatch" << std::endl;
  }

  return 0;
}
