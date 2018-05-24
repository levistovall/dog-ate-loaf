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
  Matrix(const int numberOfRows_, const int numberOfColumns_);
  Matrix(const Matrix &m);
  virtual ~Matrix();

  int getNumberOfRows() const;
  int getNumberOfColumns() const;

  Matrix<T> operator=(const Matrix &m);

  const T &at(int rowIdx, int columnIdx) const;
  T &at(int rowIdx, int columnIdx);

  std::string toString() const;

  Matrix<T> getRowReducedEchelonForm() const;
  Matrix<T> getSubMatrixExcludingSpecifiedRowAndColumn(int rowToNixIdx, int colToNixIdx) const;
  Matrix<T> getColumnRangeAsMatrix(int colStartIdx, int colEndIdx) const;
protected:
  std::vector<std::vector<T> > content;
  int numberOfRows;
  int numberOfColumns;

  Matrix<T> getHorizontalJointWithOther(Matrix<T> other) const;
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
      result.at(i, j) = a.at(i, j) * t1;
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
        result.at(i, j) = 0;
        for(int k = 0; k < a.getNumberOfColumns(); k++)
        {
          result.at(i, j) += a.at(i, k) * b.at(k, j);
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
        result.at(i, j) = a.at(i, j) + b.at(i, j);
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
