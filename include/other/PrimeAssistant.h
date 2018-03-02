#ifndef PRIMEASSISTANT_H_
#define PRIMEASSISTANT_H_

#include <map>
#include <vector>
#include <iostream>
#include <math.h>

class PrimeAssistant
{
public:
  static bool isPrimeInteger(const int &n);

  static std::map<int, int> getPrimeFactorization(const int &n);
  static int  getProductFromFactors(const std::map<int,int> &primeFac);

  static std::map<int, int> addPrimeFacs(const std::map<int, int>& a,
                                         const std::map<int, int>& b);
  static std::map<int, int> subtractPrimeFacs(const std::map<int, int>& a,
                                              const std::map<int, int>& b);

  static bool isIntegerPairCoprime(const int &a, const int &b);
  static bool areIntegersCoprime(const std::vector<int> &v);

  static int  getGcfOfIntegerPair(const int &a, const int &b);
  static int  getGcfOfIntegers(const std::vector<int> &v);

  static int  getLcmOfIntegerPair(const int &a, const int &b);
  static int  getLcmOfIntegers(const std::vector<int> &v);
};

#endif
