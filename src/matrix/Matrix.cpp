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
  numberOfRows = m.getNumberOfRows();
  numberOfColumns = m.getNumberOfColumns();
  content = m.getContent();
  return *this;
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

template<typename T>
std::string Matrix<T>::toString() const
{
  std::stringstream ss;
  ss << "[";
  for(int i = 0; i < numberOfRows; i++)
  {
    if(i > 0)
    {
      ss << " ";
    }
    ss << "[";
    for(int j = 0; j < numberOfColumns; j++)
    {
      ss << content[i][j];
      if(j < numberOfColumns-1)
      {
        ss << " ";
      }
    }
    ss << "]";
    if(i < numberOfRows-1)
    {
      ss << std::endl;
    }
  }
  ss << "]" << std::endl;
  return ss.str();
}
