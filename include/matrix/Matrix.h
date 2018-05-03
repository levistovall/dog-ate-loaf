#ifndef MATRIX_H_
#define MATRIX_H_

#include <map>
#include <vector>
#include <iostream>
#include <math.h>
#include <typeinfo>
#include "Rational.h"
#include "matrix_exceptions.h"

template<typename T>
class Matrix
{
public:
  Matrix(int numberOfRows_, int numberOfColumns_);
  Matrix(const Matrix &m);
  virtual ~Matrix();

  int getNumberOfRows() const;
  int getNumberOfColumns() const;

  Matrix<T> operator=(const Matrix &m);

  const std::vector<T> &operator[](int index) const;
  std::vector<T> &operator[](int index);

  const std::vector<std::vector<T> > &getContent() const;
  std::vector<std::vector<T> > &getContent();

  std::string toString() const;

private:
  std::vector<std::vector<T> > content;
  int numberOfRows;
  int numberOfColumns;
};

template<typename T>
std::ostream &operator<<(std::ostream &out, Matrix<T> const &m)
{
  out << m.toString();
  return out;
}

template<typename T1, typename T2>
auto operator*(const T1 &t1, const Matrix<T2> &a) -> Matrix<decltype(T1{} * T2{})>
{
  Matrix<decltype(T1{} * T2{})> result(a.getNumberOfRows(), a.getNumberOfColumns());
  for(int i = 0; i < result.getNumberOfRows(); i++)
  {
    for(int j = 0; j < result.getNumberOfColumns(); j++)
    {
      result[i][j] = a[i][j] * t1;
    }
  }
  return result;
}

template<typename T1, typename T2>
auto operator*(const Matrix<T1> &a, const T2 &t2) -> Matrix<decltype(T1{} * T2{})>
{
  return t2 * a;
}

template<typename T1, typename T2>
auto operator*(const Matrix<T1> &a, const Matrix<T2> &b) -> Matrix<decltype(T1{} * T2{})>
{
  if(a.getNumberOfColumns() == b.getNumberOfRows())
  {
    Matrix<decltype(T1{} * T2{})> result(a.getNumberOfRows(), b.getNumberOfColumns());
    for(int i = 0; i < a.getNumberOfRows(); i++)
    {
      for(int j = 0; j < b.getNumberOfColumns(); j++)
      {
        result[i][j] = 0;
        for(int k = 0; k < a.getNumberOfColumns(); k++)
        {
          result[i][j] += a[i][k] * b[k][j];
        }
      }
    }
    return result;
  }
  else
  {
    throw incompatible_matrix_multiplicands_exception();
  }
}

template<typename T1, typename T2>
auto operator+(const Matrix<T1> &a, const Matrix<T2> &b) -> Matrix<decltype(T1{} + T2{})>
{
  if(((a.getNumberOfRows() == b.getNumberOfRows()) && (a.getNumberOfColumns() == b.getNumberOfColumns())))
  {
    Matrix<decltype(T1{} * T2{})> result(a.getNumberOfRows(), a.getNumberOfColumns());
    for(int i = 0; i < result.getNumberOfRows(); i++)
    {
      for(int j = 0; j < result.getNumberOfColumns(); j++)
      {
        result[i][j] = a[i][j] + b[i][j];
      }
    }
    return result;
  }
  else
  {
    throw incompatible_matrix_addends_exception();
  }
}

template<typename T1, typename T2>
auto operator-(const Matrix<T1> &a, const Matrix<T2> &b) -> Matrix<decltype(T1{} - T2{})>
{
  return (a + (-1 * b));
}

#endif
