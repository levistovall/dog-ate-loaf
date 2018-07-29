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
    int alternator = 1;
    for(int i = 0; i < this->numberOfColumns; i++)
    {
      SquareMatrix<T> subMatrix = this->getSubMatrixExcludingSpecifiedRowAndColumn(0, i);
      determinant += alternator * this->at(0, i) * subMatrix.getDeterminant();
      alternator *= -1;
    }
    return determinant;
  }
}

template<typename T>
Polynomial<T> SquareMatrix<T>::getCharacteristicPolynomial() const
{
  return getCharacteristicPolynomialHelper(this->getIdentity());
}

template<typename T>
Polynomial<T> SquareMatrix<T>::getCharacteristicPolynomialHelper(const SquareMatrix<T> &lambdaPositions) const
{
  Polynomial<T> characteristicPolynomial;
  characteristicPolynomial = characteristicPolynomial * 0;
  if(this->numberOfRows == 1)
  {
    characteristicPolynomial =
    {
        {{}, this->at(0, 0)},
        {{{"lambda", 1}}, (-1 * lambdaPositions.at(0, 0))}
    };
    return characteristicPolynomial;
  }
  else if(this->numberOfRows == 2)
  {
    Polynomial<T> upperLeftPolynomial =
        {
            {{}, this->at(0, 0)},
            {{{"lambda", 1}}, (-1 * lambdaPositions.at(0, 0))}
        };
    Polynomial<T> upperRightPolynomial =
        {
            {{}, this->at(0, 1)},
            {{{"lambda", 1}}, (-1 * lambdaPositions.at(0, 1))}
        };
    Polynomial<T> lowerLeftPolynomial =
        {
            {{}, this->at(1, 0)},
            {{{"lambda", 1}}, (-1 * lambdaPositions.at(1, 0))}
        };
    Polynomial<T> lowerRightPolynomial =
        {
            {{}, this->at(1, 1)},
            {{{"lambda", 1}}, (-1 * lambdaPositions.at(1, 1))}
        };
    characteristicPolynomial = (upperLeftPolynomial * lowerRightPolynomial) -
                               (upperRightPolynomial * lowerLeftPolynomial);

    return characteristicPolynomial;
  }
  else
  {
    int alternator = 1;
    for(int i = 0; i < this->numberOfColumns; i++)
    {
      SquareMatrix<T> subMatrix = this->getSubMatrixExcludingSpecifiedRowAndColumn(0, i);
      SquareMatrix<T> subMatrixLambdaPositions = lambdaPositions.getSubMatrixExcludingSpecifiedRowAndColumn(0, i);
      Polynomial<T> subMatrixCharacteristicPolynomial = subMatrix.getCharacteristicPolynomialHelper(subMatrixLambdaPositions);
      Polynomial<T> polynomialForThisColumn =
          {
              {{}, (this->at(0, i) * alternator)},
              {{}, (-1 * lambdaPositions.at(0, i) * alternator)}
          };
      characteristicPolynomial = characteristicPolynomial + (polynomialForThisColumn * subMatrixCharacteristicPolynomial);
      alternator *= -1;
    }
    return characteristicPolynomial;
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
