#include "Matrix.h"

template class Matrix<int>;
template class Matrix<double>;
template class Matrix<float>;
template class Matrix<Rational>;

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
Matrix<T>::Matrix(const Matrix<T> &m)
{
  numberOfRows = m.getNumberOfRows();
  numberOfColumns = m.getNumberOfColumns();

  content.resize(numberOfRows);
  for(int i = 0; i < numberOfRows; i++)
  {
    content.at(i).resize(numberOfColumns);
    for(int j = 0; j < numberOfColumns; j++)
    {
      content.at(i).at(j) = m[i][j];
    }
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
int Matrix<T>::getNumberOfColumns() const
{
  return numberOfColumns;
}

template<typename T>
Matrix<T> Matrix<T>::operator=(const Matrix<T>& m)
{

}

template<typename T>
std::vector<T> &Matrix<T>::operator[](int index)
{
  return content.at(index);
}

template<typename T>
const std::vector<T> &Matrix<T>::operator[](int index) const
{
  return content.at(index);
}

template<typename T>
std::vector<std::vector<T> > &Matrix<T>::getContent()
{
  return content;
}

template<typename T>
const std::vector<std::vector<T> > &Matrix<T>::getContent() const
{
  return content;
}

template<typename T1, typename T2>
auto operator*(const T1 &t1, const Matrix<T2> &a) -> Matrix<decltype(T1{} * T2{})>&
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
auto operator*(const Matrix<T1> &a, const T2 &t2) -> Matrix<decltype(T1{} * T2{})>&
{
  Matrix<decltype(T1{} * T2{})> result(a.getNumberOfRows(), a.getNumberOfColumns());
  for(int i = 0; i < result.getNumberOfRows(); i++)
  {
    for(int j = 0; j < result.getNumberOfColumns(); j++)
    {
      result[i][j] = a[i][j] * t2;
    }
  }
  return result;
}

template<typename T1, typename T2>
auto operator*(const Matrix<T1> &v, const Matrix<T2> &u) -> Matrix<decltype(T1{} * T2{})>&
{

}
