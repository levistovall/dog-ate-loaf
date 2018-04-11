#include "Matrix.h"

template<typename T>
Matrix<T>::Matrix(int numberOfRows_, int numberOfColumns_)
{
  numberOfRows = numberOfRows_;
  numberOfColumns = numberOfColumns_;

  content.resize(numberOfRows);
  for(auto it = content.begin(); it != content.end(); it++)
  {
    it->resize(numberOfColumns);
  }
}

template<typename T>
Matrix<T>::~Matrix(){}

template<typename T>
int Matrix<T>::getNumberOfRows() const
{
  return numberOfRows;
}

template<typename T>
Matrix<T> &Matrix<T>::operator[](int index)
{
  return content[index];
}

template<typename T>
const Matrix<T> &Matrix<T>::operator[](int index) const
{
  return content[index];
}

template<typename T1, typename T2>
auto operator*(const T1 &t1, const Matrix<T2> &a) -> Matrix<decltype(T1{} * T2{})>
{
  Matrix<decltype(T1{} * T2{})> result(a.getLength());
  for(int i = 0; i < result.getLength(); i++)
  {
    result[i] = a[i] * t1;
  }
}

template<typename T1, typename T2>
auto operator*(const Matrix<T1> &v, const Matrix<T2> &u) -> Matrix<decltype(T1{} * T2{})>
{

}
