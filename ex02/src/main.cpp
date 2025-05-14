#include <cstdlib>
#include <ctime>
#include <iostream>

#include "Base.hpp"

int main() {
  std::srand(std::time(NULL));  // 乱数初期化

  Base* ptr = generate();

  std::cout << "identify(Base*): ";
  identify(ptr);

  std::cout << "identify(Base&): ";
  identify(*ptr);

  delete ptr;
  return 0;
}
