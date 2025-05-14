#include "Base.hpp"

#include <cstdlib>
#include <iostream>

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base() {
}

Base* generate() {
  int r = std::rand() % 3;
  if (r == 0)
    return new A();
  if (r == 1)
    return new B();
  return new C();
}

// ポインタ版：dynamic_cast + nullptr チェック
void identify(Base* p) {
  if (dynamic_cast<A*>(p))
    std::cout << "A\n";
  else if (dynamic_cast<B*>(p))
    std::cout << "B\n";
  else if (dynamic_cast<C*>(p))
    std::cout << "C\n";
  else
    std::cout << "Unknown\n";
}

// 参照版：dynamic_cast 例外を利用して判定
void identify(Base& p) {
  try {
    (void)dynamic_cast<A&>(p);
    std::cout << "A\n";
    return;
  } catch (...) {
  }

  try {
    (void)dynamic_cast<B&>(p);
    std::cout << "B\n";
    return;
  } catch (...) {
  }

  try {
    (void)dynamic_cast<C&>(p);
    std::cout << "C\n";
    return;
  } catch (...) {
  }

  std::cout << "Unknown\n";
}
