#include "Rational.h"

Rational::Rational(int _numerator, int _denominator)
{
  if(_denominator == 0)
  {
    throw division_by_zero_exception();
  }
  else
  {
    this->primeFac = PrimeAssistant::getPrimeFactorization(_numerator);
    std::cout << "calling getPF on denom in Rational constructor. " << std::endl;
    std::map<int, int> primeFacDenom = PrimeAssistant::getPrimeFactorization(_denominator);
    std::map<int,int>::iterator it;
    for(it = primeFacDenom.begin(); it != primeFacDenom.end(); it++)
    {
      if(primeFac.count(it->first) > 0)  
      {
        if(primeFac[it->first] == it->second)
        {
          primeFac.erase(it->first);
        }
        else
        {
          primeFac[it->first] -= it->second;
        }
      }
      else
      {
        primeFac[it->first] = -1 * it->second;
      }
    }
  
    this->numerator   = 1;
    this->denominator = 1;
    for(it = primeFac.begin(); it != primeFac.end(); it++)
    {
      if(it->second > 0)
      {
        for(int i = 0; i < it->second; i++)
        {
          this->numerator *= it->first;
        }
      }
      else
      {
        for(int i = 0; i < (-1 * it->second); i++)
        {
          this->denominator *= it->first;
        }
      }
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

const std::map<int, int> & Rational::getPrimeFac()
{
  return this->primeFac; 
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

/*
 * The operators follow, and are not member functions.
 */
Rational operator+(const Rational &r, const Rational &q)
{
  int sumDenominator = 
        PrimeAssistant::getLcmOfIntegerPair(r.getDenominator(),
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

double operator+(const Rational &r, const double &d)
{
  return (r.toDouble() + d);
}
/*
Rational operator-(const Rational &r, const Rational &q)
{
  return (r + (-1 * q));
}

float    operator-(const float &f);
double   operator-(const double &d);
*/
Rational operator*(const Rational &r, const Rational &q)
{
  Rational product(r.getNumerator()   * q.getNumerator(), 
                   r.getDenominator() * q.getDenominator());
  return product;
}
Rational operator*(const Rational &r, const int &i)
{
  Rational product(r.getNumerator() * i, r.getDenominator());
  return product;
}
/*
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
*/
