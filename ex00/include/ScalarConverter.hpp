#pragma once

#include <string>

class ScalarConverter {
 public:
  static void convert(const std::string& literal);

 private:
  ScalarConverter();
  static double parseLiteral(const std::string& literal, bool& isFloat,
                             bool& isSpecial, bool& isChar);
  static void displayChar(double value, bool isChar);
  static void displayInt(double value, bool isSpecial);
  static void displayFloat(double value);
  static void displayDouble(double value);
};
