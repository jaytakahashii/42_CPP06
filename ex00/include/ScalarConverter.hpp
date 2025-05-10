#pragma once
#include <string>

class ScalarConverter {
 public:
  static void convert(const std::string& literal);

 private:
  ScalarConverter();  // インスタンス化禁止
  ScalarConverter(const ScalarConverter&);
  ScalarConverter& operator=(const ScalarConverter&);
  ~ScalarConverter();
};
