#include <cstdlib>
#include <iostream>

#include "ScalarConverter.hpp"
#include "color.hpp"

int main(int argc, char** argv) {
  if (argc != 2) {
    std::cerr << "Usage: ./convert <literal>" << std::endl;
    return EXIT_FAILURE;
  }

  try {
    ScalarConverter::convert(argv[1]);
  } catch (const std::invalid_argument& e) {
    std::cerr << RED << e.what() << RESET << std::endl;
    return EXIT_FAILURE;
  } catch (const std::exception& e) {
    std::cerr << RED << "Error: " << e.what() << RESET << std::endl;
    return EXIT_FAILURE;
  }

  return 0;
}
