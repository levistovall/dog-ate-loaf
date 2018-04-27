#ifndef MATRIX_EXCEPTIONS_H_
#define MATRIX_EXCEPTIONS_H_

#include <iostream>
#include <exception>

class incompatible_matrix_multiplicands_exception: public std::exception
{
public:
  virtual const char* what() const throw()
  {
    std::stringstream ss;
    ss << "In order to multiply matrices, the first multiplicand "
       << "must have a number of columns equivalent to the number "
       << "of rows in the second multiplicand.";
    return ss.str().c_str();
  }
};

class incompatible_matrix_addends_exception: public std::exception
{
public:
  virtual const char* what() const throw()
  {
    std::stringstream ss;
    ss << "In order to add or subtract matrices, the matrix "
       << "addends must have equal numbers of rows and equal "
       << "numbers of columns.";
    return ss.str().c_str();
  }
};

#endif
