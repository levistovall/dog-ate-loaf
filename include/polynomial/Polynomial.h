#ifndef POLYNOMIAL_H_
#define POLYNOMIAL_H_

#include <map>
#include <vector>
#include <iostream>
#include <math.h>
#include <typeinfo>
#include <initializer_list>
#include "Rational.h"


/*
 * The class template Polynomial<T> can represent a sum of products of scalars and variables
 * of any order but cannot represent anything with a polynomial in the denominator.
 * It achieves this by inheriting std::map<std::map<std::string, T>, T>, which might be more
 * helpfully represented as std::map<std::map<VARIABLE_NAME, DEGREE>, COEFFICIENT>
 */
template<typename T>
class Polynomial : public std::map<std::map<std::string, T>, T>
{
public:
  /*
   * Plain ol' constructor
   */
  Polynomial();

  /*
   * This constructor uses an initializer list which is available courtesy of
   * std::map so that polynomials can be constructed in a *relatively* concise way
   * as opposed to being built term by term
   */
  Polynomial(std::initializer_list<std::pair<const std::map<std::string, T>, T>> il);

  /*
   * The method addTerm takes a term, e.g. a(x^2)(y^3) and adds it to
   * this Polynomial, adding a to the coefficient of a like term if it exists,
   * deleting the like term if the existing coefficient is -a, or creating a new
   * key-value pairing if a like term did not previously exist
   */
  void addTerm(const std::pair<std::map<std::string, T>, T> &term);

  /*
   * The method getProductOfTwoTerms takes two pairings of coefficients
   * to variable-degree maps and returns a product. For example, the two terms
   * could respectively represent 6(x^2) and 2(x)(y^2). In that case this method
   * would return a term to represent 12(x^3)(y^2).
   */
  static std::pair<std::map<std::string, T>, T> getProductOfTwoTerms(
      const std::pair<std::map<std::string, T>, T> &term1,
      const std::pair<std::map<std::string, T>, T> &term2);

  std::string toString() const;

  /*
   * Returns as a Polynomial the value of this Polynomial when evaluated when its variables
   * corresponding to the keys of the map varNameToValueMap have the values specified by the
   * values of the same map.
   * For example, if the Polynomial was x + y + 1 then passing a map {{x : 5}} to this
   * method would yield the Polynomial y + 6. If the map {{x : 3}, {y : 2}} were
   * passed instead, this method would yield a Polynomial with only a constant term, 6.
   */
  Polynomial<T> evaluateWithVariableValues(std::map<std::string, T> varNameToValueMap);

  /*
   * The method containsVariable determines whether this Polynomial has
   * any terms with a variable that has the name passed as varName
   */
  bool containsVariable(std::string varName);
};

/*
 * This operator achieves scalar multiplication of a Polynomial
 */
template<typename T1, typename T2>
auto operator*(const T1 &scalar, const Polynomial<T2> &p) -> Polynomial<decltype(T1{} * T2{})>
{
  Polynomial<decltype(T1{} * T2{})> scalarMultiple;
  typename std::map<std::map<std::string, T2>, T2>::const_iterator p_it;
  /*
   * iterate over the terms in the polynomial, get the product with the scalar,
   * and add the result to the returned polynomial
   */
  for(p_it = p.begin(); p_it != p.end(); p_it++)
  {
    std::pair<std::map<std::string, decltype(T1{} * T2{})>, decltype(T1{} * T2{})> multipliedTerm;
    multipliedTerm.first = p_it->first;
    multipliedTerm.second = p_it->second * scalar;
    scalarMultiple.addTerm(multipliedTerm);
  }

  return scalarMultiple;
}

/*
 * This operator achieves scalar multiplication of Polynomial in the opposite order
 * to the above
 */
template<typename T1, typename T2>
auto operator*(const Polynomial<T1> &p, const T2 &scalar) -> Polynomial<decltype(T1{} * T2{})>
{
  return scalar * p;
}

/*
 * This operator achieves multiplication of two polynomials
 */
template<typename T1, typename T2>
auto operator*(const Polynomial<T1> &p, const Polynomial<T2> &q) -> Polynomial<decltype(T1{} * T2{})>
{
  Polynomial<decltype(T1{} * T2{})> product;

  typename std::map<std::map<std::string, T1>, T1>::const_iterator p_it;
  typename std::map<std::map<std::string, T2>, T2>::const_iterator q_it;
  /*
   * Iterate over the first polynomial
   */
  for(p_it = p.begin(); p_it != p.end(); p_it++)
  {
    /*
     * For every term in the first polynomial,
     * iterate over all the terms in the second polynomial
     */
    std::map<std::string, decltype(T1{} * T2{})> variableOrderMap;
    for(q_it = q.begin(); q_it != q.end(); q_it++)
    {
      /*
       * Get the product of the current term of the first polynomial
       * with the current term of the second polynomial.
       */
      std::pair<std::map<std::string, decltype(T1{} * T2{})>, decltype(T1{} * T2{})> termProduct =
          Polynomial<decltype(T1{} * T2{})>::getProductOfTwoTerms(*p_it, *q_it);
      /*
       * Add it to the polynomial which will be returned.
       */
      product.addTerm(termProduct);
    }
  }

  return product;
}

/*
 * This operator achieves addition of two polynomials.
 */
template<typename T1, typename T2>
auto operator+(const Polynomial<T1> &p, const Polynomial<T2> &q) -> Polynomial<decltype(T1{} * T2{})>
{
  /*
   * Make a new polynomial to return.
   */
  Polynomial<decltype(T1{} * T2{})> sum;

  /*
   * Add all terms from the first polynomial.
   */
  typename std::map<std::map<std::string, T1>, T1>::const_iterator p_it;
  for(p_it = p.begin(); p_it != p.end(); p_it++)
  {
    sum.addTerm(*p_it);
  }

  /*
   * Add all terms from the second polynomial.
   */
  typename std::map<std::map<std::string, T2>, T2>::const_iterator q_it;
  for(q_it = q.begin(); q_it != q.end(); q_it++)
  {
    sum.addTerm(*q_it);
  }

  return sum;
}

/*
 * This operator achieves subtraction from polynomial of another
 */
template<typename T1, typename T2>
auto operator-(const Polynomial<T1> &p, const Polynomial<T2> &q) -> Polynomial<decltype(T1{} * T2{})>
{
  return p + (-1 * q);
}

/*
 * This operator allows ostreams to handle Polynomials
 */
template<typename T>
std::ostream &operator<<(std::ostream &out, Polynomial<T> const &p)
{
  out << p.toString();
  return out;
}

#endif
