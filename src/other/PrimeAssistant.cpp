#include "PrimeAssistant.h"

bool PrimeAssistant::isPrimeInteger(int n)
{
  if(n < 2)
  {
    return false;
  }

  for(int i = 2; i < n/2 + 1; i++)
  {
    if(n%i == 0)
    {
      return false;
    }
  } 
  return true;
}

int PrimeAssistant::getProductFromFactors(std::map<int, int> primeFac)
{
  int p = 1;
  std::map<int,int>::iterator it; 
  for(it = primeFac.begin(); it != primeFac.end(); it++)
  {
    for(int i = 0; i < it->second; i++)
    {
      p *= it->first;
      std::cout << "multiplying by " << it->first << " for " << (i+1) << " time." << std::endl; 
    }    
  }
  return p;
}

std::map<int, int> PrimeAssistant::getPrimeFactorization(int n)
{
  std::cout << "Getting prime factorization of " << n << std::endl;
  std::map<int, int> pf;
  if(n < 0)
  {
    pf[-1] = 1;
  }
  if(isPrimeInteger(n) || isPrimeInteger(-1*n) || n*n == 1)
  {
    pf[n] = 1;
    return pf;
  }
  int quotient;
  int greatestRemainingPossibleFactor = n/2;
  for(int i = 2; i <= greatestRemainingPossibleFactor; i++)
  {
    if(isPrimeInteger(i) && (n%i == 0))
    {
      pf[i] = 0;
      quotient = n; 
      while(quotient%i == 0)
      {
        quotient /= i;
        pf[i]++;
      }
      greatestRemainingPossibleFactor = n / getProductFromFactors(pf);
      if(isPrimeInteger(greatestRemainingPossibleFactor))
      {
        pf[greatestRemainingPossibleFactor] = 1;
        return pf;
      }
    }
  }
  return pf; 
}

bool PrimeAssistant::isIntegerPairCoprime(int a, int b)
{
  std::cout << "############################" << std::endl;
  std::cout << "#ENTER isIntegerPairCoprime#" << std::endl;
  std::cout << "############################" << std::endl;
  std::map<int, int> primeFacA = getPrimeFactorization(a);
  std::map<int, int> primeFacB = getPrimeFactorization(b);

  std::map<int, int>::iterator it;
  for(it = primeFacA.begin(); it != primeFacA.end(); it++)
  {
    if(primeFacB.count(it->first) > 0)
    {
      return false;
    }
  }
  std::cout << "############################" << std::endl;
  std::cout << "#EXIT  isIntegerPairCoprime#" << std::endl;
  std::cout << "############################" << std::endl;
  return true;
}

bool PrimeAssistant::areIntegersCoprime(std::vector<int> v)
{
  std::vector<int>::iterator it1;
  for(it1 = v.begin(); it1 != v.end(); it1++)
  {
    std::vector<int>::iterator it2;
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

int PrimeAssistant::getGcfOfIntegerPair(int a, int b)
{
  int lesserInt;
  if(a > b)
  {
    lesserInt = b;
  }
  else
  {
    lesserInt = a;
  }
  int gcf = lesserInt;
  int i = 2;
  while(gcf > 1)
  {
    if((a % gcf == 0) && (b % gcf == 0))
    {
      return gcf;
    }
    else
    {
      gcf = lesserInt / i;
      i++; 
    }
  }
  return 1;
}

int PrimeAssistant::getGcfOfIntegers(std::vector<int> v)
{
  std::vector<int>::iterator it = v.begin();
  int leastInteger = *it;
  for(it = v.begin() + 1; it != v.end(); it++)
  {
    if(leastInteger > *it)
    {
      leastInteger = *it;
    }
  }

  int gcf = leastInteger;

  for(it = v.begin(); it != v.end(); it++)
  {
    if(*it > leastInteger)
    {
      gcf = getGcfOfIntegerPair(gcf, *it);
    }
  }
  return gcf;
}

int PrimeAssistant::getLcmOfIntegerPair(int a, int b)
{
  int gcf = getGcfOfIntegerPair(a, b);
  return (gcf * (a / gcf) * (b / gcf));
}

int PrimeAssistant::getLcmOfIntegers(std::vector<int> v)
{
  std::map<int, int> allFactorsOfLcm;
  std::map<int, int> primeFacOfCurrent; 
  std::vector<int>::iterator it1;
  std::map<int, int>::iterator it2;
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
