#include "Rational.h"

Rational::Rational(int _numerator, int _denominator)
{
  if(_denominator == 0)
  {
    throw division_by_zero_exception();
  }
  else
  {
    int gcf = FactorUtil::getGcfOfIntegerPair(_numerator, _denominator);
    this->numerator   = _numerator / gcf;
    this->denominator = _denominator / gcf;
  }
}

/*
 * Intentional empty destructor.
 */
Rational::~Rational(){}

int Rational::getNumerator() const
{
  return this->numerator;
}

int Rational::getDenominator() const
{
  return this->denominator;
}

/*const double& Rational::getTol() const
{
  return Rational::tol;
}*/

std::map<int, int> Rational::getPrimeFac() const
{
  std::map<int,int> primeFacNumer = 
                      FactorUtil::getPrimeFactorization(this->numerator);
  std::map<int,int> primeFacDenom = 
                      FactorUtil::getPrimeFactorization(this->denominator);
  return FactorUtil::subtractPrimeFacs(primeFacNumer, primeFacDenom); 
}

std::string Rational::toString() const
{
  std::stringstream ss;
  ss << "(" << this->numerator   << "/" 
             << this->denominator << ")";
  return ss.str();
}

double Rational::toDouble() const
{
  return (static_cast<double>(numerator) /
          static_cast<double>(denominator));
}

float Rational::toFloat() const
{
  return (static_cast<float>(numerator) /
          static_cast<float>(denominator));
}

int Rational::toInteger() const
{
  return numerator / denominator;
}

Rational Rational::operator+=(const Rational &r)
{
  *this = *this + r;
  return *this;
}

Rational Rational::operator+=(const int &i)
{
  *this = *this + i;
  return *this;
}

Rational Rational::operator-=(const Rational &r)
{
  *this = *this - r;
  return *this;
}

Rational Rational::operator-=(const int &i)
{
  *this = *this - i;
  return *this;
}

Rational Rational::operator*=(const Rational &r)
{
  *this = *this * r;
  return *this;
}

Rational Rational::operator*=(const int &i)
{
  *this = *this * i;
  return *this;
}

Rational Rational::operator/=(const Rational &r)
{
  *this = *this / r;
  return *this;
}

Rational Rational::operator/=(const int &i)
{
  *this = *this / i;
  return *this;
}

/*
 * The arithmetic and comparison operators follow,
 * and are not member functions.
 */
Rational operator+(const Rational &r, const Rational &q)
{
  int sumDenominator = 
        FactorUtil::getLcmOfIntegerPair(r.getDenominator(),
                                            q.getDenominator());
  int balanceFactorForThisNumerator  = sumDenominator / r.getDenominator();
  int balanceFactorForOtherNumerator = sumDenominator / q.getDenominator();
  int sumNumerator = r.getNumerator() * balanceFactorForThisNumerator +
                     q.getNumerator() * balanceFactorForOtherNumerator;
  Rational sum(sumNumerator, sumDenominator);
  return sum;
}

Rational operator+(const Rational &r, const int  &i)
{
  Rational intAsRational(i, 1);
  return (r + intAsRational);
}

Rational operator+(const int  &i, const Rational &r)
{
  return (r + i);
}

float operator+(const Rational &r, const float &f)
{
  return (r.toFloat() + f);
}

float operator+(const float &f, const Rational &r)
{
  return (r + f);
}

double operator+(const Rational &r, const double &d)
{
  return (r.toDouble() + d);
}

double operator+(const double &d, const Rational &r)
{
  return (r + d);
}

Rational operator-(const Rational &r, const Rational &q)
{
  return (r + (-1 * q));
}

Rational operator-(const Rational &r, const int  &i)
{
  Rational intAsRational(i, 1);
  return (r - intAsRational);
}

Rational operator-(const int  &i, const Rational &r)
{
  Rational intAsRational(i, 1);
  return (intAsRational - r);
}

float operator-(const Rational &r, const float &f)
{
  return (r + (-1 * f));
}

float operator-(const float &f, const Rational &r)
{
  return (f + (-1 * r));
}

double operator-(const Rational &r, const double &d)
{
  return (r + (-1 * d));
}

double operator-(const double &d, const Rational &r)
{
  return (d + (-1 * r));
}

Rational operator*(const Rational &r, const Rational &q)
{
  Rational product(r.getNumerator()   * q.getNumerator(), 
                   r.getDenominator() * q.getDenominator());
  return product;
}

Rational operator*(const Rational &r, const int &i)
{
  Rational product((r.getNumerator() * i), r.getDenominator());
  return product;
}

Rational operator*(const int &i, const Rational &r)
{
  return (r * i);
}

float operator*(const Rational &r, const float &f)
{
  return (r.toFloat() * f);
}

float operator*(const float &f, const Rational &r)
{
  return (r * f);
}

double operator*(const Rational &r, const double &d)
{
  return (r.toDouble() * d);
}

double operator*(const double &d, const Rational &r)
{
  return (r * d);
}

Rational operator/(const Rational &r, const Rational &q)
{
  Rational quotient((r.getNumerator()   * q.getDenominator()),
                    (r.getDenominator() * q.getNumerator()));
  return quotient;
}

Rational operator/(const Rational &r, const int &i)
{
  Rational intAsRational(i, 1);
  return (r / intAsRational);
}

Rational operator/(const int &i, const Rational &r)
{
  Rational intAsRational(i, 1);
  return (intAsRational / r);
}

float operator/(const Rational &r, const float &f)
{
  return (r.toFloat() / f);
}

float operator/(const float &f, const Rational &r)
{
  return (f / r.toFloat());
}

double operator/(const Rational &r, const double &d)
{
  return (r.toDouble() / d);
}

double operator/(const double &d, const Rational &r)
{
  return (d / r.toDouble());
}

bool operator==(const Rational &r, const Rational &q)
{
  return ((r.getNumerator()   == q.getNumerator()) &&
          (r.getDenominator() == q.getDenominator()));
}

bool operator==(const Rational &r, const int &i)
{
  return ((r.getNumerator() == i) && (r.getDenominator() == 1));
}

bool operator==(const int &i, const Rational &r)
{
  return (r == i);
}

bool operator==(const Rational &r, const float &f)
{
  return (std::abs(r.toFloat() - f) < Rational::tol);
}

bool operator==(const float &f, const Rational &r)
{
  return (r == f);
}

bool operator==(const Rational &r, const double &d)
{
  return (std::abs(r.toDouble() - d) < Rational::tol);
}

bool operator==(const double &d, const Rational &r)
{
  return (r == d);
}

bool operator!=(const Rational &r, const Rational &q)
{
  return !(r == q);
}

bool operator!=(const Rational &r, const int &i)
{
  return !(r == i);
}

bool operator!=(const int &i, const Rational &r)
{
  return !(r == i);
}

bool operator!=(const Rational &r, const float &f)
{
  return !(r == f);
}

bool operator!=(const float &f, const Rational &r)
{
  return !(r == f);
}

bool operator!=(const Rational &r, const double &d)
{
  return !(r == d);
}

bool operator!=(const double &d, const Rational &r)
{
  return !(r == d);
}
