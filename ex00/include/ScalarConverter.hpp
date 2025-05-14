#pragma once

#include <string>

class ScalarConverter {
 public:
  static void convert(const std::string& literal);

 private:
  ScalarConverter();
  static void parseLiteral(const std::string& literal, double& value,
                           bool& isSpecial);
  static void displayChar(double value);
  static void displayInt(double value, bool isSpecial);
  static void displayFloat(double value);
  static void displayDouble(double value);
};
