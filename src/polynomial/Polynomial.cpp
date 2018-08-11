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
  /*
   * Once the initializer list constructor of the super class
   * has built terms, iterate over all terms and eliminate any zero terms
   */
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
  /*
   * If, for whatever reason, the input term has coefficient 0,
   * do nothing. Otherwise, proceed to the routine.
   */
  if(term.second != 0)
  {
    /*
     * If there are no like terms in this Polynomial, simply insert
     * the argument term as a new term of the polynomial
     */
    if(this->count(term.first) == 0)
    {
      this->insert(term);
    }
    /*
     * If there is an existing like term in the Polynomial, and the
     * coefficient of the existing like term and the
     * coefficient of the argument term do not add to 0,
     * add the coefficient of the argument term to the coefficient
     * of the existing term in this Polynomial
     */
    else if((this->at(term.first) + term.second) != 0)
    {
      this->at(term.first) = this->at(term.first) + term.second;
    }
    /*
     * If there is an existing like term but the coefficients cancel,
     * erase the existing like term
     */
    else
    {
      this->erase(term.first);
    }
  }
}

template<typename T>
std::pair<std::map<std::string, T>, T> Polynomial<T>::getProductOfTwoTerms(
    const std::pair<std::map<std::string, T>, T> &term1,
    const std::pair<std::map<std::string, T>, T> &term2)
{
  std::pair<std::map<std::string, T>, T> termProduct;

  /*
   * To determine what variables will be in the product and their
   * respective orders, start with the variables in the first term
   */
  std::map<std::string, T> variableNameToOrderMap = term1.first;
  typename std::map<std::string, T>::const_iterator it;
  /*
   * Iterate over the variables in the second term
   */
  for(it = term2.first.begin(); it != term2.first.end(); it++)
  {
    /*
     * If the first term does not have the current term2 variable,
     * add the variable with its corresponding order to the result
     */
    if(variableNameToOrderMap.count(it->first) == 0)
    {
      variableNameToOrderMap.insert(*it);
    }
    /*
     * If the current variable is common between the two terms, add its order
     * in the first term to its order in the second term to get its order in the product.
     */
    else
    {
      variableNameToOrderMap.at(it->first) = variableNameToOrderMap.at(it->first) + it->second;
    }
  }

  /*
   * To get the coefficient, simply multiply the coefficients of the two terms
   */
  T coefficient = term1.second * term2.second;

  /*
   * Set the coefficient and variable to order mapping of the resulting term,
   * and then return it.
   */
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

template<typename T>
Polynomial<T> Polynomial<T>::evaluateWithVariableValues(std::map<std::string, T> varNameToValueMap)
{
  Polynomial<T> evaluated;

  /*
   * Iterate over the variable-value pairs in the argument
   */
  typename std::map<std::string, T>::iterator varIterator;
  for(varIterator = varNameToValueMap.begin(); varIterator != varNameToValueMap.end(); varNameIter++)
  {
    typename Polynomial<T>::iterator termIterator;
    for(termIterator = this->begin(); termIterator != this->end(); termIterator++)
    {
      if(termIterator->first.count(varIterator->first) != 0)
      {

      }
    }
  }
}

template<typename T>
bool Polynomial<T>::containsVariable(std::string varName)
{
  /*
   * Iterate over all terms in the Polynomial
   */
  typename Polynomial<T>::iterator termIterator;
  for(termIterator = this->begin(); termIterator != this->end(); termIterator++)
  {
    /*
     * For each term, check if the input variable is in it.
     * If so, return true.
     */
    if(termIterator->first.count(varName) != 0)
    {
      return true;
    }
  }

  /*
   * If we haven't returned true after checking all terms, return false.
   */
  return false;
}

template class Polynomial<int>;
template class Polynomial<double>;
template class Polynomial<float>;
template class Polynomial<Rational>;
