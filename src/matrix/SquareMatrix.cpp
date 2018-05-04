#include "SquareMatrix.h"

template class Matrix<int>;
template class Matrix<double>;
template class Matrix<float>;
template class Matrix<Rational>;

template<typename T>
SquareMatrix<T>::SquareMatrix(int dimension_) : Matrix(dimension_, dimension_){}

template<typename T>
T SquareMatrix<T>::getDeterminant() const
{
  if(numberOfRows == 1)
  {
    return content[0][0];
  }
  else if(numberOfRows == 2)
  {
    return ((content[0][0] * content[1][1]) - (content[0][1] * content[1][0]));
  }
  else
  {
    T determinant = 0;
    int alternator = -1;
    for(int i = 0; i < numberOfColumns; i++)
    {
      SquareMatrix<T> subMatrix(numberOfColumns-1) = this->getSubMatrixExcludingSpecifiedRowAndColumn(0, i);
      determinant += alternator * subMatrix.getDeterminant();
      alternator *= -1;
    }
    return determinant;
  }
}
