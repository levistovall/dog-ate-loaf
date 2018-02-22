Rational::Rational(int _numerator, int _denominator)
{
  if(_denominator == 0)
  {
    /*
     * TODO: fix this so it makes sense
     */
    return 0;
  }

  //this->numerator   = _numerator;
  //this->denominator = _denominator;

  this->primeFac = PrimeAssistant::getPrimeFactorization(_numerator);
  std::map<int, int> primeFacDenom = PrimeAssistant::getPrimeFactorization(_denominator);
  std::map<int,int>::iterator it;
  for(it = primeFacDenom.begin(); it != primeFacDenom.end(); it++)
  {
    if((primeFac.count(it->first) > 0)  
    {
      if(primeFac[it->first] != it->second)
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
      primeFac[it-first] = -1 * it->second;
    }
  }


  this->numerator   = 1;
  this->denominator = 1;
  for(it = primeFac.begin(); it != primeFac.end(); i++)
  {
    if(it->second > 0)
    {
      this->numerator *= it->first;
    }
    else
    {
      this->denominator *= it->first;
    }
  }
}

Rational::~Rational();

Rational::getNumerator()
{
  return this->numerator;
}

Rational::getDenominator()
{
  return this->denominator;
}

Rational::getPrimeFac() const
{
  return this->primeFac; 
}

double Rational::toDouble()
{
  return (static_cast<double>(numerator) +
          static_cast<double>(denominator));
}

float Rational::toFloat();
{
  return (static_cast<float>(numerator) +
          static_cast<float>(denominator));
}

int Rational::toInteger();
{
  return numerator / denominator;
}

Rational Rational::operator+(const Rational &r)
{
  
}
float    Rational::operator+(const float  &f);
double   Rational::operator+(const double &d);

Rational Rational::operator-(const Rational &r);
float    Rational::operator-(const float &f);
double   Rational::operator-(const double &d);

Rational Rational::operator*(const Rational &r);
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

int      numerator;
int      denominator;

std::map<int,int> primeFacNumer;
std::map<int,int> primeFacDenom;
