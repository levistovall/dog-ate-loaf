#ifndef VECTOR_H_
#define VECTOR_H_

#include <map>
#include <vector>
#include <iostream>
#include <math.h>
#include <typeinfo>

template<typename T>
class Matrix
{
public:
  Matrix(int numberOfRows_, int numberOfColumns_);
  virtual ~Matrix();

  int getNumberOfRows() const;

  int getNumberOfColumns() const;

  const Matrix<T> &operator[](int index) const;

  Matrix<T> &operator[](int index);

private:
  std::vector<std::vector<T>> content;
  int numberOfRows;
  int numberOfColumns;
};

template<typename T1, typename T2>
auto operator*(const T1 &t1, const Matrix<T2> &a) -> Matrix<decltype(T1{} * T2{})>;

template<typename T1, typename T2>
auto operator*(const Matrix<T1> &a, const T2 &t2) -> Matrix<decltype(T1{} * T2{})>;

template<typename T1, typename T2>
auto operator*(const Matrix<T1> &a, const Matrix<T2> &b) -> Matrix<decltype(T1{} * T2{})>;

template<typename T1, typename T2>
auto operator+(const Matrix<T1> &a, const Matrix<T2> &b) -> Matrix<decltype(T1{} + T2{})>;

template<typename T1, typename T2>
auto operator-(const Matrix<T1> &a, const Matrix<T2> &b) -> Matrix<decltype(T1{} - T2{})>;


#endif
