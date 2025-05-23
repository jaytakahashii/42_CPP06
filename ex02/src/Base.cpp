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

void identify(Base* p) {
  if (dynamic_cast<A*>(p))
    std::cout << "A" << std::endl;
  else if (dynamic_cast<B*>(p))
    std::cout << "B" << std::endl;
  else if (dynamic_cast<C*>(p))
    std::cout << "C" << std::endl;
  else
    std::cout << "Unknown\n";
}

void identify(Base& p) {
  try {
    (void)dynamic_cast<A&>(p);
    std::cout << "A" << std::endl;
    return;
  } catch (...) {
  }

  try {
    (void)dynamic_cast<B&>(p);
    std::cout << "B" << std::endl;
    return;
  } catch (...) {
  }

  try {
    (void)dynamic_cast<C&>(p);
    std::cout << "C" << std::endl;
    return;
  } catch (...) {
  }

  std::cout << "Unknown\n";
}
