#pragma once

#include <exception>
#include <string>

class ScalarConverter {
 public:
  static void convert(const std::string& literal);

 private:
  static double parseLiteral(const std::string& literal, bool& isFloat,
                             bool& isSpecial, bool& isChar);
  static void displayChar(double value, bool isSpecial);
  static void displayInt(double value, bool isSpecial);
  static void displayFloat(double value);
  static void displayDouble(double value);

  class InvalidInputException : public std::exception {
   public:
    const char* what() const throw();
  };

  class NonDisplayableException : public std::exception {
   public:
    const char* what() const throw();
  };
};
