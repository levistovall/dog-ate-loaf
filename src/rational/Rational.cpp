#include "Rational.h"

Rational::Rational(int _numerator, int _denominator)
{
  /*
   * We cannot create a rational with denominator 0.
   */
  if(_denominator == 0)
  {
    throw division_by_zero_exception();
  }
  else if(_numerator == 0)
  {
    numerator   = _numerator;
    denominator = 1;
  }
  else
  {
    /*
     * Get the numerator and denominator in simplest terms.
     */
    int gcf = FactorUtil::getGcfOfIntegerPair(_numerator, _denominator);
    numerator   = _numerator / gcf;
    denominator = _denominator / gcf;

    /*
     * Do not store negatives for both numerator
     * and denominator, and if only one is negative, store the factor of -1
     * in the numerator
     */
    if(denominator < 0)
    {
      denominator *= -1;
      numerator   *= -1;
    }
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
  std::map<int,int>::const_iterator it;
  for(it = primeFacDenom.begin(); it != primeFacDenom.end(); it++)
  {
    /*
     * numerator and denominator have this factor in common
     */
    if(primeFacNumer.count(it->first) > 0)
    {
      /*
       * if numerator and denominator have this factor to the same power, it cancels
       */
      if(primeFacNumer[it->first] == it->second)
      {
        primeFacNumer.erase(it->first);
      }
      else
      {
        primeFacNumer[it->first] -= it->second;
      }
    }
    else
    {
      primeFacNumer[it->first] = -1 * it->second;
    }
  }
  return primeFacNumer;
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
  Rational sum((r.getNumerator() * q.getDenominator()) + (q.getNumerator() * r.getDenominator()),
               (r.getDenominator() * q.getDenominator()));
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

bool operator<(const Rational &r, const Rational &q)
{
  return (r.toDouble() < q.toDouble());
}

bool operator<(const Rational &r, const int &i)
{
  return ((r.getNumerator() / r.getDenominator()) < i);
}

bool operator<(const int &i, const Rational &r)
{
  return (i < (r.getNumerator() / r.getDenominator()));
}

bool operator<(const Rational &r, const float &f)
{
  return (r.toFloat() < f);
}

bool operator<(const float &f, const Rational &r)
{
  return (f < r.toFloat());
}

bool operator<(const Rational &r, const double &d)
{
  return (r.toDouble() < d);
}

bool operator<(const double &d, const Rational &r)
{
  return (d < r.toDouble());
}

bool operator>(const Rational &r, const Rational &q)
{
  return (r.toDouble() > q.toDouble());
}

bool operator>(const Rational &r, const int &i)
{
  return ((r.getNumerator() / r.getDenominator()) > i);
}

bool operator>(const int &i, const Rational &r)
{
  return (i > (r.getNumerator() / r.getDenominator()));
}

bool operator>(const Rational &r, const float &f)
{
  return (r.toFloat() > f);
}

bool operator>(const float &f, const Rational &r)
{
  return (f > r.toFloat());
}

bool operator>(const Rational &r, const double &d)
{
  return (r.toDouble() > d);
}

bool operator>(const double &d, const Rational &r)
{
  return (d > r.toDouble());
}

std::ostream &operator<<(std::ostream &out, const Rational &r)
{
  out << r.toString();
  return out;
}
