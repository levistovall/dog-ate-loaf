#include "SquareMatrix.h"

template<typename T>
SquareMatrix<T>::SquareMatrix(int dimension_) : Matrix<T>(dimension_, dimension_){}

template<typename T>
SquareMatrix<T>::SquareMatrix(const Matrix<T> &m) : Matrix<T>(m)
{
  if(m.getNumberOfColumns() != m.getNumberOfRows())
  {
    throw non_square_matrix_passed_to_square_matrix_constructor_exception();
  }
}

template<typename T>
T SquareMatrix<T>::getDeterminant() const
{
  if(this->numberOfRows == 1)
  {
    return this->at(0, 0);
  }
  else if(this->numberOfRows == 2)
  {
    return ((this->at(0, 0) * this->at(1, 1)) - (this->at(0, 1) * this->at(1, 0)));
  }
  else
  {
    T determinant = 0;
    int alternator = -1;
    for(int i = 0; i < this->numberOfColumns; i++)
    {
      SquareMatrix<T> subMatrix = this->getSubMatrixExcludingSpecifiedRowAndColumn(0, i);
      determinant += alternator * subMatrix.getDeterminant();
      alternator *= -1;
    }
    return determinant;
  }
}

template<typename T>
SquareMatrix<T> SquareMatrix<T>::getIdentity() const
{
  SquareMatrix<T> identity(this->getNumberOfRows());
  for(int i = 0; i < identity.getNumberOfRows(); i++)
  {
    for(int j = 0; j < identity.getNumberOfColumns(); j++)
    {
      if(i == j)
      {
        identity.at(i, j) = 1;
      }
      else
      {
        identity.at(i, j) = 0;
      }
    }
  }
  return identity;
}

template<typename T>
SquareMatrix<T> SquareMatrix<T>::getInverse() const
{
  Matrix<T> thisJoinedWithIdentity = this->getHorizontalJointWithOther(this->getIdentity());
  Matrix<T> reducedJoint = thisJoinedWithIdentity.getRowReducedEchelonForm();
  return reducedJoint.getColumnRangeAsMatrix(this->getNumberOfRows(), 2 * this->getNumberOfRows());
}

template class SquareMatrix<int>;
template class SquareMatrix<double>;
template class SquareMatrix<float>;
template class SquareMatrix<Rational>;
