#ifndef RATIONAL_H_
#define RATIONAL_H_

#include <map>
#include <vector>
#include <math.h>
#include <string.h>
#include <sstream>
#include "PrimeAssistant.h"
#include "division_by_zero_exception.h"

class Rational
{
public:
  Rational(int _numerator = 1, int _denominator = 1);
  virtual ~Rational();

  int getNumerator() const;
  int getDenominator() const;

  const std::map<int, int> & getPrimeFac();

  std::string toString();

  double   toDouble();
  float    toFloat();
  int      toInteger();

  Rational operator+(const Rational &r);
  Rational operator+(const int &i);
  float    operator+(const float &f);
  double   operator+(const double &d);

  Rational operator-(const Rational &r);
  Rational operator-(const int &i);
  float    operator-(const float &f);
  double   operator-(const double &d);

  Rational operator*(const Rational &r);
  Rational operator*(const int &i);
  float    operator*(const float &f);
  double   operator*(const double &d);

  Rational operator/(const Rational &r);
  Rational operator/(const int &i);
  float    operator/(const float &f);
  double   operator/(const double &d);

  Rational operator=(const Rational &r);
  float    operator=(const float &f);
  double   operator=(const double &d);

  bool     operator==(const Rational &r); 
  bool     operator==(const float &f); 
  bool     operator==(const double &d); 

  bool     operator!=(const Rational &r); 
  bool     operator!=(const float &f); 
  bool     operator!=(const double &d); 

private:
  int      numerator;
  int      denominator;

  std::map<int,int> primeFac;
};

#endif
