#ifndef MATRIX_H_
#define MATRIX_H_

#include <map>
#include <vector>
#include <iostream>
#include <math.h>
#include <typeinfo>
#include "Rational.h"

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

private:
  std::vector<std::vector<T> > content;
  int numberOfRows;
  int numberOfColumns;
};

template<typename T1, typename T2>
auto operator*(const T1 &t1, const Matrix<T2> &a) -> Matrix<decltype(T1{} * T2{})>&;

template<typename T1, typename T2>
auto operator*(const Matrix<T1> &a, const T2 &t2) -> Matrix<decltype(T1{} * T2{})>&;

template<typename T1, typename T2>
auto operator*(const Matrix<T1> &a, const Matrix<T2> &b) -> Matrix<decltype(T1{} * T2{})>&;

template<typename T1, typename T2>
auto operator+(const Matrix<T1> &a, const Matrix<T2> &b) -> Matrix<decltype(T1{} + T2{})>&;

template<typename T1, typename T2>
auto operator-(const Matrix<T1> &a, const Matrix<T2> &b) -> Matrix<decltype(T1{} - T2{})>&;

#endif
