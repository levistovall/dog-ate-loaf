#include "Matrix.h"

template<typename T>
Matrix<T>::Matrix(int numberOfRows_, int numberOfColumns_)
{
  this->numberOfRows = numberOfRows_;
  this->numberOfColumns = numberOfColumns_;

  this->content.resize(this->numberOfRows);
  std::vector<std::vector<T>>::iterator it;
  for(it = this->content.begin(); it != this->content.end(); it++)
  {

  }
}

template<typename T>
Matrix<T>::~Matrix(){}

template<typename T>
int Matrix<T>::getNumberOfRows() const
{
  return this->numberOfRows;
}

template<typename T>
Matrix<T> &Matrix<T>::operator[](int index)
{
  return (this->content)[index];
}

template<typename T>
const Matrix<T> &Matrix<T>::operator[](int index) const
{
  return this->content[index];
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
auto operator*(const Matrix<T1> &v, const Matrix<T2> &u)
{

}
