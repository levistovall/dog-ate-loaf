#ifndef PRIMEASSISTANT_H_
#define PRIMEASSISTANT_H_

#include <map>
#include <vector>
#include <iostream>
#include <math.h>

class PrimeAssistant
{
public:
  static bool isPrimeInteger(int n);
  static std::map<int, int> getPrimeFactorization(int n);
  static int  getProductFromFactors(std::map<int,int> primeFac);
  static bool isIntegerPairCoprime(int a, int b);
  static bool areIntegersCoprime(std::vector<int> v);
  static int  getGreatestCommonFactor(int a, int b);
};

#endif
