#include "Matrix.h"

template<typename T>
Matrix<T>::Matrix(const int numberOfRows_, const int numberOfColumns_)
{
  numberOfRows = numberOfRows_;
  numberOfColumns = numberOfColumns_;

  content.resize(numberOfRows);
  for(int i = 0; i < numberOfRows; i++)
  {
    content.at(i).resize(numberOfColumns);
  }
}

template<typename T>
Matrix<T>::Matrix(const Matrix<T> &m) : Matrix<T>(m.getNumberOfRows(), m.getNumberOfColumns())
{
  for(int i = 0; i < numberOfRows; i++)
  {
    for(int j = 0; j < numberOfColumns; j++)
    {
      this->at(i, j) = m.at(i, j);
    }
  }
}

template<typename T>
Matrix<T>::~Matrix()
{}

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
  if((numberOfRows == m.getNumberOfRows()) and (numberOfColumns == m.getNumberOfColumns()))
  {
    for(int i = 0; i < numberOfRows; i++)
    {
      for(int j = 0; j < numberOfColumns; j++)
      {
        this->at(i, j) = m.at(i, j);
      }
    }
    return *this;
  }
  else
  {
    throw invalid_matrix_assignment_exception();
  }
}

template<typename T>
const T &Matrix<T>::at(int rowIdx, int columnIdx) const
{
  return content.at(rowIdx).at(columnIdx);
}

template<typename T>
T &Matrix<T>::at(int rowIdx, int columnIdx)
{
  return content.at(rowIdx).at(columnIdx);
}

template<typename T>
std::string Matrix<T>::toString() const
{
  std::stringstream ss;
  ss << std::endl << "[";
  for(int i = 0; i < numberOfRows; i++)
  {
    if(i > 0)
    {
      ss << " ";
    }
    ss << "[";
    for(int j = 0; j < numberOfColumns; j++)
    {
      ss << this->at(i, j);
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

template<typename T>
Matrix<T> Matrix<T>::getTranspose() const
{
  Matrix<T> transpose(numberOfColumns, numberOfRows);
  for(int i = 0; i < numberOfRows; i++)
  {
    for(int j = 0; j < numberOfColumns; j++)
    {
      transpose.at(j, i) = this->at(i, j);
    }
  }
  return transpose;
}

template<typename T>
Matrix<T> Matrix<T>::getRowReducedEchelonForm() const
{
  Matrix<T> reduced(*this);
  for(int i = 0; i < reduced.getNumberOfRows(); i++)
  {
    T pivotReciprocal = 1 / reduced.at(i, i);
    for(int j = i; j < reduced.getNumberOfColumns(); j++)
    {
      reduced.at(i, j) = reduced.at(i, j) * pivotReciprocal;
    }

    for(int j = 0; j < reduced.getNumberOfRows(); j++)
    {
      if(j != i)
      {
        T factor = reduced.at(j, i) / reduced.at(i, i);
        for(int k = i; k < reduced.getNumberOfColumns(); k++)
        {
          reduced.at(j, k) = reduced.at(j, k) - (factor * reduced.at(i, k));
        }
      }
    }
  }
  return reduced;
}

template<typename T>
Matrix<T> Matrix<T>::getHorizontalJointWithOther(Matrix<T> other) const
{
  if(this->getNumberOfRows() == other.getNumberOfRows())
  {
    Matrix<T> joint(this->getNumberOfRows(), this->getNumberOfColumns() + other.getNumberOfColumns());
    for(int i = 0; i < this->getNumberOfRows(); i++)
    {
      for(int j = 0; j < this->getNumberOfColumns(); j++)
      {
        joint.at(i, j) = this->at(i, j);
      }

      for(int j = 0; j < other.getNumberOfColumns(); j++)
      {
        joint.at(i, j + this->getNumberOfColumns()) = other.at(i, j);
      }
    }
    return joint;
  }
  else
  {

  }
}

template<typename T>
Matrix<T> Matrix<T>::getColumnRangeAsMatrix(int colStartIdx, int colEndIdx) const
{
  if((colEndIdx <= this->getNumberOfColumns()) &&
     (colStartIdx < colEndIdx) &&
     (colStartIdx >= 0))
  {
    Matrix<T> columnSubset(this->getNumberOfRows(), (colEndIdx - colStartIdx));
    for(int i = 0; i < columnSubset.getNumberOfRows(); i++)
    {
      for(int j = 0; j < columnSubset.getNumberOfColumns(); j++)
      {
        columnSubset.at(i, j) = this->at(i, colStartIdx + j);
      }
    }
    std::cout << " get ColumnRangeAsMatrix: " << columnSubset << std::endl;
    return columnSubset;
  }
  else
  {

  }
}

template<typename T>
Matrix<T> Matrix<T>::getSubMatrixExcludingSpecifiedRowAndColumn(int rowToNixIdx, int colToNixIdx) const
{
  Matrix<T> subMatrix(numberOfRows-1, numberOfColumns-1);
  int rowToCopyIdx = 0;
  int colToCopyIdx;
  for(int i = 0; i < subMatrix.getNumberOfRows(); i++)
  {
    colToCopyIdx = 0;
    if(i == rowToNixIdx)
    {
      rowToCopyIdx ++;
    }
    for(int j = 0; j < subMatrix.getNumberOfColumns(); j++)
    {
      if(j == colToNixIdx)
      {
        colToCopyIdx ++;
      }
      subMatrix.at(i, j) = this->at(rowToCopyIdx, colToCopyIdx);
      colToCopyIdx++;
    }
    rowToCopyIdx++;
  }
  return subMatrix;
}

template class Matrix<int>;
template class Matrix<double>;
template class Matrix<float>;
template class Matrix<Rational>;
