#include "FactorUtil.h"

bool FactorUtil::isPrimeInteger(const int &n)
{
  if(n < 2)
  {
    return false;
  }

  int greatestPossibleFactorCeiling =
        static_cast<int>(floor(pow(static_cast<double>(n), 0.5))) + 1;
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
  int p = 1;
  std::map<int,int>::const_iterator it; 
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
  if(n < 0)
  {
    pf[-1] = 1;
    m *= -1;
  }
  if(isPrimeInteger(m))
  {
    pf[m] = 1;
    return pf;
  }
  int quotient;
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
      if(isPrimeInteger(greatestRemainingPossibleFactor))
      {
        pf[greatestRemainingPossibleFactor] = 1;
        return pf;
      }
    }
  }
  return pf; 
}

std::map<int,int> FactorUtil::addPrimeFacs(const std::map<int,int> &a,
                                               const std::map<int,int> &b)
{
  std::map<int,int> sum = a;
  std::map<int,int>::const_iterator it;
  for(it = b.begin(); it != b.end(); it++)
  {
    if(sum.count(it->first) > 0)
    {
      sum[it->first] += it->second;
    }
    else
    {
      sum[it->first] = it->second;
    }
  }
  return sum;
}

std::map<int,int> FactorUtil::subtractPrimeFacs(const std::map<int,int> &a,
                                                    const std::map<int,int> &b)
{
  std::map<int,int> difference = a;
  std::map<int,int>::const_iterator it;
  for(it = b.begin(); it != b.end(); it++)
  {
    if(difference.count(it->first) > 0)
    {
      if(difference[it->first] == it->second)
      {
        difference.erase(it->first);
      }
      else
      {
        difference[it->first] -= it->second;
      }
    }
    else
    {
      difference[it->first] = -1 * it->second;
    }
  }
  return difference;
}

bool FactorUtil::isIntegerPairCoprime(const int &a, const int &b)
{
  std::map<int,int> primeFacA = getPrimeFactorization(a);
  std::map<int,int> primeFacB = getPrimeFactorization(b);

  std::map<int,int>::const_iterator it;
  for(it = primeFacA.begin(); it != primeFacA.end(); it++)
  {
    if(primeFacB.count(it->first) > 0)
    {
      return false;
    }
  }
  return true;
}

bool FactorUtil::areIntegersCoprime(const std::vector<int> &v)
{
  std::vector<int>::const_iterator it1;
  for(it1 = v.begin(); it1 != v.end(); it1++)
  {
    std::vector<int>::const_iterator it2;
    for(it2 = it1 + 1; it2 != v.end(); it2++)
    {
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
  const int* lesserInt = &a;
  const int* greaterInt = &b;
  if(a > b)
  {
    lesserInt = &b;
    greaterInt = &a;
  }
  std::map<int,int> greaterPrimeFac = getPrimeFactorization(*greaterInt);
  std::map<int,int> lesserPrimeFac = getPrimeFactorization(*lesserInt);
  int gcf = 1;
  std::map<int,int>::const_iterator it;
  for(it = lesserPrimeFac.begin(); it != lesserPrimeFac.end(); it++)
  {
    if(greaterPrimeFac.count(it->first))
    {
      int numOfCommonOccurrencesOfCurrentPrimeFactor =
          std::min(it->second, greaterPrimeFac[it->first]);
      for(int i = 0; i < numOfCommonOccurrencesOfCurrentPrimeFactor; i++)
      {
        gcf *= it->first;
      }
    }
  }
  return gcf;
}

int FactorUtil::getGcfOfIntegers(const std::vector<int> &v)
{
  std::vector<int>::const_iterator it = v.begin();
  std::vector<int>::const_iterator leastInteger = it;
  for(it = v.begin() + 1; it != v.end(); it++)
  {
    if(*leastInteger > *it)
    {
      leastInteger = it;
    }
  }

  int gcf = *leastInteger;

  for(it = v.begin(); it != v.end(); it++)
  {
    if(it != leastInteger)
    {
      gcf = getGcfOfIntegerPair(gcf, *it);
    }
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
  std::map<int,int> allFactorsOfLcm;
  std::map<int,int> primeFacOfCurrent; 
  std::vector<int>::const_iterator it1;
  std::map<int,int>::const_iterator it2;
  for(it1 = v.begin(); it1 != v.end(); it1++)
  {
    primeFacOfCurrent = getPrimeFactorization(*it1);
    for(it2  = primeFacOfCurrent.begin(); 
        it2 != primeFacOfCurrent.end();
        it2++)
    {
      if((allFactorsOfLcm.count(it2->first) == 0) ||
         (allFactorsOfLcm[it2->first] < it2->second))
      {
        allFactorsOfLcm[it2->first] = it2->second;
      }
    }
  }
  return getProductFromFactors(allFactorsOfLcm);
}