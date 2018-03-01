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

std::string Rational::toString()
{
  std::stringstream ss;
  ss << "(" << this->numerator   << "/" 
             << this->denominator << ")";
  return ss.str();
}

double Rational::toDouble()
{
  return (static_cast<double>(numerator) /
          static_cast<double>(denominator));
}

float Rational::toFloat()
{
  return (static_cast<float>(numerator) /
          static_cast<float>(denominator));
}

int Rational::toInteger()
{
  return numerator / denominator;
}

Rational Rational::operator+(const Rational &r)
{
  int sumDenominator = 
        PrimeAssistant::getLcmOfIntegerPair(this->denominator,
                                            r.getDenominator());
  int balanceFactorForThisNumerator  = sumDenominator / this->denominator;
  int balanceFactorForOtherNumerator = sumDenominator / r.getDenominator();
  int sumNumerator = this->numerator  * balanceFactorForThisNumerator +
                     r.getNumerator() * balanceFactorForOtherNumerator;
  Rational sum(sumNumerator, sumDenominator);
  return sum;
}

float    Rational::operator+(const float  &f)
{
  return (this->toFloat() + f);
}

double   Rational::operator+(const double &d)
{
  return (this->toDouble() + d);
}

Rational Rational::operator-(const Rational &r)
{
  return *this + (-1 * r);
}
/*
float    Rational::operator-(const float &f);
double   Rational::operator-(const double &d);
*/
Rational Rational::operator*(const Rational &r)
{
  Rational product(this->numerator   * r.getNumerator(), 
                   this->denominator * r.getDenominator());
  return product;
}
Rational Rational::operator*(const int &i)
{
  Rational product(this->numerator * i, this->denominator);
  return product;
}
/*
float    Rational::operator*(const float &f);
double   Rational::operator*(const double &d);

Rational Rational::operator/(const Rational &r);
float    Rational::operator/(const float &f);
double   Rational::operator/(const double &d);

Rational Rational::operator=(const Rational &r);
float    Rational::operator=(const float &f);
double   Rational::operator=(const double &d);

bool     Rational::operator==(const Rational &r); 
bool     Rational::operator==(const float &f); 
bool     Rational::operator==(const double &d); 

bool     Rational::operator!=(const Rational &r); 
bool     Rational::operator!=(const float &f); 
bool     Rational::operator!=(const double &d); 
*/
int      numerator;
int      denominator;

std::map<int,int> primeFacNumer;
std::map<int,int> primeFacDenom;
