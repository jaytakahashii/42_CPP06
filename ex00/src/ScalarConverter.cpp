#include "ScalarConverter.hpp"

#include <cctype>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>
#include <stdexcept>

#include "color.hpp"
#include "utils.hpp"

double ScalarConverter::parseLiteral(const std::string& literal, bool& isFloat,
                                     bool& isSpecial, bool& isChar) {
  isFloat = false;
  isSpecial = false;
  isChar = false;
  double value = 0.0;

  // 特殊値
  if (literal == "nan" || literal == "+inf" || literal == "-inf") {
    isSpecial = true;
    return std::strtod(literal.c_str(), NULL);
  }
  if (literal == "nanf" || literal == "+inff" || literal == "-inff") {
    isSpecial = true;
    isFloat = true;
    return std::strtod(literal.c_str(), NULL);
  }

  // char単体（例: 'a'）
  if (literal.length() == 1 && !std::isdigit(literal[0])) {
    isChar = true;
    return static_cast<double>(literal[0]);
  }

  // float末尾除去
  std::string copy = literal;
  if (literal.length() > 1 && literal[literal.length() - 1] == 'f') {
    isFloat = true;
    copy = literal.substr(0, literal.length() - 1);
  }

  char* endptr;
  value = std::strtod(copy.c_str(), &endptr);
  if (*endptr != '\0') {
    throw std::invalid_argument(literal);
  }

  return value;
}

// ---------- 表示部 ----------
void ScalarConverter::displayChar(double value, bool isChar) {
  std::cout << "char: ";
  if (!isChar || value < 0 || value > 127) {
    std::cout << "impossible" << std::endl;
  } else {
    char c = static_cast<char>(value);
    if (!isDisplayableChar(c))
      std::cout << "Non displayable" << std::endl;
    else
      std::cout << "'" << c << "'" << std::endl;
  }
}

void ScalarConverter::displayInt(double value, bool isSpecial) {
  std::cout << "int: ";
  if (isSpecial ||
      value < static_cast<double>(std::numeric_limits<int>::min()) ||
      value > static_cast<double>(std::numeric_limits<int>::max())) {
    std::cout << "impossible" << std::endl;
  } else {
    std::cout << static_cast<int>(value) << std::endl;
  }
}

void ScalarConverter::displayFloat(double value) {
  std::cout << "float: ";
  std::cout << std::fixed << std::setprecision(1) << static_cast<float>(value)
            << "f" << std::endl;
}

void ScalarConverter::displayDouble(double value) {
  std::cout << "double: ";
  std::cout << std::fixed << std::setprecision(1) << static_cast<double>(value)
            << std::endl;
}

// ---------- メイン ----------
void ScalarConverter::convert(const std::string& literal) {
  bool isFloat, isSpecial, isChar;
  double value;

  value = parseLiteral(literal, isFloat, isSpecial, isChar);

  displayChar(value, isSpecial);
  displayInt(value, isSpecial);
  displayFloat(value);
  displayDouble(value);
}
