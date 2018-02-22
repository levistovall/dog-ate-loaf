#ifndef RATIONAL_H_
#define RATIONAL_H_

class Rational
{
public:
  Rational(int _numerator = 1, int _denominator = 1);
  virtual ~Rational();

  int       & getNumerator();
  int const & getDenominator();

  std::map<int, int> const & getPrimeFac();

  double   toDouble();
  float    toFloat();
  int      toInteger();

  Rational operator+(const Rational &r);
  float    operator+(const float &f);
  double   operator+(const double &d);

  Rational operator-(const Rational &r);
  float    operator-(const float &f);
  double   operator-(const double &d);

  Rational operator*(const Rational &r);
  float    operator*(const float &f);
  double   operator*(const double &d);

  Rational operator/(const Rational &r);
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
