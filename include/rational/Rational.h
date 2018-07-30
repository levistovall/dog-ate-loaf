#ifndef RATIONAL_H_
#define RATIONAL_H_

#include <map>
#include <vector>
#include <cmath>
#include <string.h>
#include <sstream>
#include "FactorUtil.h"
#include "division_by_zero_exception.h"

class Rational
{
public:
  /*
   * this constructor throws a division_by_zero_exception
   * if the denominator is 0
   */
  Rational(int _numerator = 1, int _denominator = 1);
  virtual ~Rational();

  /*
   * the method getNumerator returns the value of
   * the numerator of the Rational
   */
  int getNumerator() const;

  /*
   * the method getNumerator returns the value of
   * the denominator of the Rational
   */
int getDenominator() const;

  /*
   * the method getPrimeFac returns the prime
   * factorization of the rational as a map of keys to powers.
   */
  std::map<int, int> getPrimeFac() const;

  /*
   * The method toString returns a std::string of the
   * format "(n/m)" where n is the numerator and m is the
   * denominator
   */
  std::string toString() const;

  double toDouble() const;
  float  toFloat() const;
  int    toInteger() const;

  /*
   * the double tol is used to determine whether two
   * floating point numbers are sufficiently close that
   * they can be considered equal.
   */
  static constexpr double tol = 1e-10;

  Rational operator+=(const Rational &r);
  Rational operator+=(const int      &i);

  Rational operator-=(const Rational &r);
  Rational operator-=(const int      &i);

  Rational operator*=(const Rational &r);
  Rational operator*=(const int      &i);

  Rational operator/=(const Rational &r);
  Rational operator/=(const int      &i);

private:
  int numerator;
  int denominator;

};

Rational operator+(const Rational &r, const Rational &q);
Rational operator+(const Rational &r, const int      &i);
Rational operator+(const int      &i, const Rational &r);
float    operator+(const Rational &r, const float    &f);
float    operator+(const float    &f, const Rational &r);
double   operator+(const Rational &r, const double   &d);
double   operator+(const double   &d, const Rational &r);

Rational operator-(const Rational &r, const Rational &q);
Rational operator-(const Rational &r, const int      &i);
Rational operator-(const int      &i, const Rational &r);
float    operator-(const Rational &r, const float    &f);
float    operator-(const float    &f, const Rational &r);
double   operator-(const Rational &r, const double   &d);
double   operator-(const double   &d, const Rational &r);

Rational operator*(const Rational &r, const Rational &q);
Rational operator*(const Rational &r, const int      &i);
Rational operator*(const int      &i, const Rational &r);
float    operator*(const Rational &r, const float    &f);
float    operator*(const float    &f, const Rational &r);
double   operator*(const Rational &r, const double   &d);
double   operator*(const double   &d, const Rational &r);

Rational operator/(const Rational &r, const Rational &q);
Rational operator/(const Rational &r, const int      &i);
Rational operator/(const int      &i, const Rational &r);
float    operator/(const Rational &r, const float    &f);
float    operator/(const float    &f, const Rational &r);
double   operator/(const Rational &r, const double   &d);
double   operator/(const double   &d, const Rational &r);

bool     operator==(const Rational &r, const Rational &q); 
bool     operator==(const Rational &r, const int      &i); 
bool     operator==(const int      &i, const Rational &r); 
bool     operator==(const Rational &r, const float    &f); 
bool     operator==(const float    &f, const Rational &r); 
bool     operator==(const Rational &r, const double   &d); 
bool     operator==(const double   &d, const Rational &r); 

bool     operator!=(const Rational &r, const Rational &q); 
bool     operator!=(const Rational &r, const int      &i); 
bool     operator!=(const int      &i, const Rational &r); 
bool     operator!=(const Rational &r, const float    &f); 
bool     operator!=(const float    &f, const Rational &r); 
bool     operator!=(const Rational &r, const double   &d); 
bool     operator!=(const double   &d, const Rational &r); 

bool     operator<(const Rational &r, const Rational &q);
bool     operator<(const Rational &r, const int      &i); 
bool     operator<(const int      &i, const Rational &r); 
bool     operator<(const Rational &r, const float    &f); 
bool     operator<(const float    &f, const Rational &r); 
bool     operator<(const Rational &r, const double   &d); 
bool     operator<(const double   &d, const Rational &r); 

bool     operator>(const Rational &r, const Rational &q); 
bool     operator>(const Rational &r, const int      &i); 
bool     operator>(const int      &i, const Rational &r); 
bool     operator>(const Rational &r, const float    &f); 
bool     operator>(const float    &f, const Rational &r); 
bool     operator>(const Rational &r, const double   &d); 
bool     operator>(const double   &d, const Rational &r); 

bool     operator<=(const Rational &r, const Rational &q); 
bool     operator<=(const Rational &r, const int      &i); 
bool     operator<=(const int      &i, const Rational &r); 
bool     operator<=(const Rational &r, const float    &f); 
bool     operator<=(const float    &f, const Rational &r); 
bool     operator<=(const Rational &r, const double   &d); 
bool     operator<=(const double   &d, const Rational &r); 

bool     operator>=(const Rational &r, const Rational &q); 
bool     operator>=(const Rational &r, const int      &i); 
bool     operator>=(const int      &i, const Rational &r); 
bool     operator>=(const Rational &r, const float    &f); 
bool     operator>=(const float    &f, const Rational &r); 
bool     operator>=(const Rational &r, const double   &d); 
bool     operator>=(const double   &d, const Rational &r); 

std::ostream &operator<<(std::ostream &out, Rational const &r);

#endif
