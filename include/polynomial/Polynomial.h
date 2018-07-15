#ifndef POLYNOMIAL_H_
#define POLYNOMIAL_H_

#include <map>
#include <vector>
#include <iostream>
#include <math.h>
#include <typeinfo>
#include <initializer_list>
#include "Rational.h"

template <class T> struct TermCompare
{
  bool operator() (const std::map<std::string, T> &k, const std::map<std::string, T> &l) const
  {
    if(k.size() != l.size())
    {
      return true;
    }

    typename std::map<std::string, T>::const_iterator it;
    for(it = k.begin(); it != k.end(); it++)
    {
      if(l.count(it->first) == 0)
      {
        std::cout << "has variable" << std::endl;
        return true;
      }
      else if(l.at(it->first) != it->second)
      {
        std::cout << l.at(it->first) << " != " << it->second << std::endl;
        return true;
      }
    }

    return false;
  }
};

template<typename T>
class Polynomial : public std::map<std::map<std::string, T>, T, TermCompare<T> >
{
public:
  Polynomial();
  Polynomial(std::initializer_list<std::pair<const std::map<std::string, T>, T>> il);
  void addTerm(const std::pair<std::map<std::string, T>, T> &term);
  static std::pair<std::map<std::string, T>, T> getProductOfTwoTerms(
      const std::pair<std::map<std::string, T>, T> &term1,
      const std::pair<std::map<std::string, T>, T> &term2);
  std::string toString() const;

};

template<typename T1, typename T2>
auto operator*(const T1 &scalar, const Polynomial<T2> &p) -> Polynomial<decltype(T1{} * T2{})>
{
  std::cout << "ENTER operator* " << std::endl;
  Polynomial<decltype(T1{} * T2{})> scalarMultiple;
  std::cout << "declared scalarMultiple" << std::endl;
  typename std::map<std::map<std::string, T2>, T2, TermCompare<T2> >::const_iterator p_it;
  std::cout << "declared iterator " << std::endl;
  for(p_it = p.begin(); p_it != p.end(); p_it++)
  {
    std::pair<std::map<std::string, decltype(T1{} * T2{})>, decltype(T1{} * T2{})> multipliedTerm;
    std::cout << "declared term " << std::endl;
    multipliedTerm.first = p_it->first;
    std::cout << "ENTER operator* " << std::endl;
    multipliedTerm.second = p_it->second * scalar;
    scalarMultiple.addTerm(multipliedTerm);
  }

  return scalarMultiple;
}

template<typename T1, typename T2>
auto operator*(const Polynomial<T1> &p, const T2 &scalar) -> Polynomial<decltype(T1{} * T2{})>
{
  return scalar * p;
}

template<typename T1, typename T2>
auto operator*(const Polynomial<T1> &p, const Polynomial<T2> &q) -> Polynomial<decltype(T1{} * T2{})>
{
  Polynomial<decltype(T1{} * T2{})> product;

  typename std::map<std::map<std::string, T1>, T1, TermCompare<T1> >::const_iterator p_it;
  typename std::map<std::map<std::string, T2>, T2, TermCompare<T2> >::const_iterator q_it;
  for(p_it = p.begin(); p_it != p.end(); p_it++)
  {
    std::map<std::string, decltype(T1{} * T2{})> variableOrderMap;
    for(q_it = q.begin(); q_it != q.end(); q_it++)
    {
      std::pair<std::map<std::string, decltype(T1{} * T2{})>, decltype(T1{} * T2{})> termProduct =
          Polynomial<decltype(T1{} * T2{})>::getProductOfTwoTerms(*p_it, *q_it);
      product.addTerm(termProduct);
      std::cout << "OPERATOR* " << product<< std::endl;
    }
  }

  return product;
}

template<typename T1, typename T2>
auto operator+(const Polynomial<T1> &p, const Polynomial<T2> &q) -> Polynomial<decltype(T1{} * T2{})>
{
  Polynomial<decltype(T1{} * T2{})> sum;

  typename std::map<std::map<std::string, T1>, T1, TermCompare<T1> >::const_iterator p_it;
  for(p_it = p.begin(); p_it != p.end(); p_it++)
  {
    sum.addTerm(*p_it);
  }

  typename std::map<std::map<std::string, T2>, T2, TermCompare<T2> >::const_iterator q_it;
  for(q_it = q.begin(); q_it != q.end(); q_it++)
  {
    sum.addTerm(*q_it);
  }

  return sum;
}

template<typename T1, typename T2>
auto operator-(const Polynomial<T1> &p, const Polynomial<T2> &q) -> Polynomial<decltype(T1{} * T2{})>
{
  return p + (-1 * q);
}

template<typename T>
std::ostream &operator<<(std::ostream &out, Polynomial<T> const &p)
{
  out << p.toString();
  return out;
}

#endif
