#ifndef DIVISION_BY_ZERO_EXCEPTION_H_
#define DIVISION_BY_ZERO_EXCEPTION_H_

#include <iostream>
#include <exception>

class division_by_zero_exception: public std::exception
{
public:
  virtual const char* what() const throw()
  {
    return "Division by zero exception";
  }
};

#endif
