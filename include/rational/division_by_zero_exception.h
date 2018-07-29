#ifndef DIVISION_BY_ZERO_EXCEPTION_H_
#define DIVISION_BY_ZERO_EXCEPTION_H_

#include <iostream>
#include <exception>

/**
 * The class division_by_zero_exception will be thrown by Rational
 * in the event that a Rational is constructed with a zero
 * denominator
 */
class division_by_zero_exception: public std::exception
{
public:
  virtual const char* what() const throw()
  {
    return "Division by zero exception";
  }
};

#endif
