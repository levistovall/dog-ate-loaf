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
    return this->content.at(0).at(0);
  }
  else if(this->numberOfRows == 2)
  {
    return ((this->content.at(0).at(0) * this->content.at(1).at(1)) - (this->content.at(0).at(1) * this->content.at(1).at(0)));
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

template class SquareMatrix<int>;
template class SquareMatrix<double>;
template class SquareMatrix<float>;
template class SquareMatrix<Rational>;
