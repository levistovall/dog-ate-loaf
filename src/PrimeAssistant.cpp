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
  std::map<int, int> pf;
  if(isPrimeInteger(n))
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
      std::cout << i << " : " << pf[i] << std::endl;
      greatestRemainingPossibleFactor = n / getProductFromFactors(pf);
      std::cout << "greatest remaining possible factor: " << greatestRemainingPossibleFactor << std::endl;
      if(isPrimeInteger(greatestRemainingPossibleFactor))
      {
        pf[greatestRemainingPossibleFactor] = 1;
        std::cout << greatestRemainingPossibleFactor << " : " << pf[greatestRemainingPossibleFactor] << std::endl;
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
  std::cout << "##########################" << std::endl;
  std::cout << "#ENTER areIntegersCoprime#" << std::endl;
  std::cout << "##########################" << std::endl;
  std::vector<int>::iterator it1;
  for(it1 = v.begin(); it1 != v.end(); it1++)
  {
    std::cout << "Checking " << *it1 << std::endl;
    std::vector<int>::iterator it2;
    for(it2 = it1 + 1; it2 != v.end(); it2++)
    {
      std::cout << " for coprimality with " << *it2 << std::endl;
      if(!isIntegerPairCoprime(*it1, *it2))
      {
        std::cout << "################################" << std::endl;
        std::cout << "#ENTER areIntegersCoprime false#" << std::endl;
        std::cout << "################################" << std::endl;
        return false;
      }
    }
  }
  std::cout << "################################" << std::endl;
  std::cout << "#ENTER areIntegersCoprime  true#" << std::endl;
  std::cout << "################################" << std::endl;
  return true;
}
