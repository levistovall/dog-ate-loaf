#ifndef FACTORUTIL_H_
#define FACTORUTIL_H_

#include <map>
#include <vector>
#include <iostream>
#include <math.h>

/**
 * The class FactorUtil provides utilities which might be
 * characterized as number theory lite, with the restriction that
 * it operates only on int datatypes.
 */
class FactorUtil
{
public:

  /*
   * Returns true if n is prime, false if it is negative, composite, 0, or 1.
   */
  static bool isPrimeInteger(const int &n);

  /*
   * The method getPrimeFactorization provides prime factorizations of ints as a
   * std::map, where the keys are the prime factors of the int,
   * and their respective values are the power to which the given
   * factor is raised in the int.
   *
   * e.g. getPrimeFactorization(8) == {{2, 3}}
   */
  static std::map<int, int> getPrimeFactorization(const int &n);

  /**
   * The method getProductFromFactors provides the ability to yield the int corresponding to
   * a map of factors to their powers which represents a prime factorization
   *
   * e.g. getProductFromFactors({{2, 1}, {5, 1}}) == 10
   */
  static int  getProductFromFactors(const std::map<int,int> &primeFac);

  /**
   * The method isIntegerPairCoprime returns true if two given integers are coprime
   * and false if they are not.
   */
  static bool isIntegerPairCoprime(const int &a, const int &b);

  /**
   * The method areIntegersCoprime returns true if every integer in
   * input vector v is coprime with every other vector in v,
   * and false if any two integers in v have a gcf > 1.
   */
  static bool areIntegersCoprime(const std::vector<int> &v);

  /**
   * The method getGcfOfIntegerPair returns the greatest common factor
   * of ints a and b
   */
  static int  getGcfOfIntegerPair(const int &a, const int &b);

  /**
   * The method getGcfOfIntegerPair returns the greatest common factor
   * of every integer in vector v.
   */
  static int  getGcfOfIntegers(const std::vector<int> &v);

  /**
   * The method getLcmOfIntegerPair returns the least common multiple of
   * ints a and b.
   */
  static int  getLcmOfIntegerPair(const int &a, const int &b);

  /**
   * The method getLcmOfIntegers returns the least common multiple
   * of every int in vector v.
   */
  static int  getLcmOfIntegers(const std::vector<int> &v);
};

#endif
