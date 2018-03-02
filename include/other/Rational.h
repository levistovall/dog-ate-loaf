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

  std::string toString() const;

  double   toDouble() const;
  float    toFloat() const;
  int      toInteger() const;


private:
  int      numerator;
  int      denominator;

  std::map<int,int> primeFac;
};

Rational operator+(const Rational &r, const Rational &q);
Rational operator+(const Rational &r, const int      &i);
Rational operator+(const int &i,      const Rational &r);
float    operator+(const Rational &r, const float    &f);
float    operator+(const float &f,    const Rational &r);
double   operator+(const Rational &r, const double   &d);
double   operator+(const double &d,   const Rational &r);

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

/*Rational operator=(const Rational &r, const Rational &q);
Rational operator=(const Rational &r, const int      &i);
Rational operator=(const int      &i, const Rational &r);
float    operator=(const Rational &r, const float    &f);
float    operator=(const float    &f, const Rational &r);
double   operator=(const Rational &r, const double   &d);
double   operator=(const double   &d, const Rational &r);
*/
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

#endif
