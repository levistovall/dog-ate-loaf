/*
 * Polynomial.cpp
 *
 *  Created on: Jul 8, 2018
 *      Author: levistovall
 */

#include "Polynomial.h"

template<typename T>
Polynomial<T>::Polynomial(){}

template<typename T>
Polynomial<T>::Polynomial(std::initializer_list<std::pair<const std::map<std::string, T>, T>> il)
    : std::map<std::map<std::string, T>, T>(il, this->key_comp(), this->get_allocator())
{
  typename Polynomial<T>::iterator it;
  for(it = this->begin(); it != this->end(); it++)
  {
    if(it->second == 0)
    {
      this->erase(it->first);
    }
  }
}

template<typename T>
void Polynomial<T>::addTerm(const std::pair<std::map<std::string, T>, T> &term)
{
  if(this->count(term.first) == 0)
  {
    this->insert(term);
  }
  else if((this->at(term.first) + term.second) != 0)
  {
    this->at(term.first) = this->at(term.first) + term.second;
  }
  else
  {
    this->erase(term.first);
  }
}

template<typename T>
std::pair<std::map<std::string, T>, T> Polynomial<T>::getProductOfTwoTerms(
    const std::pair<std::map<std::string, T>, T> &term1,
    const std::pair<std::map<std::string, T>, T> &term2)
{
  std::pair<std::map<std::string, T>, T> termProduct;

  std::map<std::string, T> variableNameToOrderMap = term1.first;
  typename std::map<std::string, T>::const_iterator it;
  for(it = term2.first.begin(); it != term2.first.end(); it++)
  {
    if(variableNameToOrderMap.count(it->first) == 0)
    {
      variableNameToOrderMap.insert(*it);
    }
    else
    {
      variableNameToOrderMap.at(it->first) = variableNameToOrderMap.at(it->first) + it->second;
    }
  }

  T coefficient = term1.second * term2.second;

  termProduct.first = variableNameToOrderMap;
  termProduct.second = coefficient;

  return termProduct;
}

template<typename T>
std::string Polynomial<T>::toString() const
{
  std::stringstream ss;

  typename Polynomial<T>::const_iterator it;
  for(it = this->begin(); it != this->end(); it++)
  {
    if(it != this->begin())
    {
      ss << " + ";
    }

    ss << it->second;
    if((it->first).size() > 0)
    {
      typename std::map<std::string, T>::const_iterator it_2;
      for(it_2 = it->first.begin(); it_2 != it->first.end(); it_2++)
      {
        ss << "(" << it_2->first << "^" << it_2->second << ")";
      }
    }
  }

  return ss.str();
}

template class Polynomial<int>;
template class Polynomial<double>;
template class Polynomial<float>;
template class Polynomial<Rational>;
