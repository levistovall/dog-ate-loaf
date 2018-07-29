#include "FactorUtil.h"

bool FactorUtil::isPrimeInteger(const int &n)
{
  /*
   * Return false for negatives, 0, and 1.
   */
  if(n < 2)
  {
    return false;
  }

  /*
   * For integers a and b such that a * b == n, if a > sqrt(n), then
   * b < sqrt(n), so it is only needed to check whether factors as large
   * as sqrt(n) divide n.
   */
  int greatestPossibleFactorCeiling =
        static_cast<int>(floor(pow(static_cast<double>(n), 0.5))) + 1;

  /*
   * Check whether each int from two to the sqrt(n) divides n.
   * If any do, return false. If after every such factor is checked, none
   * divide n, return true.
   */
  for(int i = 2; i < greatestPossibleFactorCeiling; i++)
  {
    if(n%i == 0)
    {
      return false;
    }
  } 
  return true;
}

int FactorUtil::getProductFromFactors(const std::map<int,int> &primeFac)
{
  /*
   * p is the product to be returned.
   */
  int p = 1;
  std::map<int,int>::const_iterator it;

  /*
   * for every key(factor) in primeFac, multiply p by the key as many times as
   * indicated by the value at the given key.
   */
  for(it = primeFac.begin(); it != primeFac.end(); it++)
  {
    for(int i = 0; i < it->second; i++)
    {
      p *= it->first;
    }    
  }
  return p;
}

std::map<int,int> FactorUtil::getPrimeFactorization(const int &n)
{
  /*
   * Get a copy of n because if it is negative we will need to use its
   * absolute value in order for the remainder of the algorithm to work.
   */
  int m = n;
  std::map<int,int> pf;

  /*
   * -1 is added to the primeFactorization map for negative numbers for convenience
   * during use in the Rational class.
   */
  if(n < 0)
  {
    pf[-1] = 1;
    m *= -1;
  }

  /*
   * If m is prime, the prime factorization should only include one factor of m itself.
   */
  if(isPrimeInteger(m))
  {
    pf[m] = 1;
    return pf;
  }

  /*
   * While looping over potential prime factors, the int quotient will be used
   * to see how many times the given factor divides m evenly
   */
  int quotient;

  /*
   * No prime factor of n can be greater than sqrt(n).
   */
  int greatestRemainingPossibleFactor =
      static_cast<int>(floor(pow(static_cast<double>(m), 0.5))) + 1;
  for(int i = 2; i <= greatestRemainingPossibleFactor; i++)
  {
    if(isPrimeInteger(i) && (m%i == 0))
    {
      pf[i] = 0;
      quotient = m;
      while(quotient%i == 0)
      {
        quotient /= i;
        pf[i]++;
      }
      greatestRemainingPossibleFactor = m / getProductFromFactors(pf);
      if(greatestRemainingPossibleFactor < 0)
      {
        greatestRemainingPossibleFactor *= -1;
      }
      if(isPrimeInteger(greatestRemainingPossibleFactor))
      {
        pf[greatestRemainingPossibleFactor] = 1;
        return pf;
      }
    }
  }
  return pf; 
}

bool FactorUtil::isIntegerPairCoprime(const int &a, const int &b)
{
  /*
   * if a and b have any prime factors in common, they
   * are not coprime.
   */
  return (getGcfOfIntegerPair(a, b) == 1);
}

bool FactorUtil::areIntegersCoprime(const std::vector<int> &v)
{
  std::vector<int>::const_iterator it1;
  for(it1 = v.begin(); it1 != v.end(); it1++)
  {
    std::vector<int>::const_iterator it2;
    for(it2 = it1 + 1; it2 != v.end(); it2++)
    {
      /*
       * If any pair of ints in v fails to be coprime,
       * they are not coprime as a group
       */
      if(!isIntegerPairCoprime(*it1, *it2))
      {
        return false;
      }
    }
  }
  return true;
}

int FactorUtil::getGcfOfIntegerPair(const int &a, const int &b)
{
  int m = std::abs(a);
  int n = std::abs(b);

  int remainder = -1;
  while(n != 0)
  {
    remainder = m % n;
    m = n;
    n = remainder;
  }
  return m;
}

int FactorUtil::getGcfOfIntegers(const std::vector<int> &v)
{
  std::vector<int>::const_iterator it = v.begin();
  int gcf;

  for(it = v.begin(); it != v.end(); it++)
  {
    gcf = getGcfOfIntegerPair(gcf, *it);
  }

  return gcf;
}

int FactorUtil::getLcmOfIntegerPair(const int &a, const int &b)
{
  int gcf = getGcfOfIntegerPair(a, b);
  return (gcf * (a / gcf) * (b / gcf));
}

int FactorUtil::getLcmOfIntegers(const std::vector<int> &v)
{
  int lcm = v.at(0);
  for(int i = 1; i < v.size(); i++)
  {
    lcm = getLcmOfIntegerPair(lcm, v.at(i));
  }

  return lcm;
}
