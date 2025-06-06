#include "ScalarConverter.hpp"

#include <cctype>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>
#include <stdexcept>
#include <string>

#include "color.hpp"

static bool isSpecialValue(const std::string& literal) {
  return literal == "nan" || literal == "+inf" || literal == "-inf" ||
         literal == "nanf" || literal == "+inff" || literal == "-inff" ||
         literal == "inf" || literal == "inff";
}

void ScalarConverter::parseLiteral(const std::string& literal, double& value,
                                   bool& isSpecial) {
  if (isSpecialValue(literal)) {
    isSpecial = true;
    value = std::strtod(literal.c_str(), NULL);
    return;
  }

  if (literal.length() == 1 && !std::isdigit(literal[0])) {
    value = static_cast<double>(literal[0]);
    return;
  }

  std::string copy = literal;
  if (literal.length() > 1 && literal[literal.length() - 1] == 'f') {
    copy = literal.substr(0, literal.length() - 1);
  }

  char* endptr;
  value = std::strtod(copy.c_str(), &endptr);
  if (*endptr != '\0') {
    throw std::invalid_argument("Invalid literal: " + literal);
  }
}

void ScalarConverter::displayChar(double value) {
  std::cout << "char: ";
  if (std::isnan(value) || value < 0 || value > 127) {
    std::cout << "impossible" << std::endl;
    return;
  }

  char c = static_cast<char>(value);
  if (std::isprint(c)) {
    std::cout << "'" << c << "'" << std::endl;
  } else {
    std::cout << "Non displayable" << std::endl;
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

void ScalarConverter::displayFloat(double value, bool isSpecial) {
  std::cout << "float: ";

  if (isSpecial) {
    std::cout << static_cast<float>(value);
    std::cout << "f" << std::endl;
    return;
  }

  std::ostringstream oss;
  oss << value;
  std::string strValue = oss.str();

  std::cout << static_cast<float>(value);
  if (strValue.find('.') == std::string::npos && !isSpecialValue(strValue)) {
    std::cout << ".0";
  }
  std::cout << "f" << std::endl;
}

void ScalarConverter::displayDouble(double value, bool isSpecial) {
  std::cout << "double: ";

  if (isSpecial) {
    std::cout << static_cast<double>(value) << std::endl;
    return;
  }

  std::ostringstream oss;
  oss << value;
  std::string strValue = oss.str();

  std::cout << static_cast<double>(value);
  if (strValue.find('.') == std::string::npos && !isSpecialValue(strValue)) {
    std::cout << ".0";
  }
  std::cout << std::endl;
}

void ScalarConverter::convert(const std::string& literal) {
  bool isSpecial = false;
  double value = 0.0;

  parseLiteral(literal, value, isSpecial);

  displayChar(value);
  displayInt(value, isSpecial);
  displayFloat(value, isSpecial);
  displayDouble(value, isSpecial);
}
