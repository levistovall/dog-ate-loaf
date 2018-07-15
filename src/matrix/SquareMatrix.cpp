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
  std::cout << "ENTER CharPolyHelper" << std::endl;
  //Matrix<T> characteristicPolynomial(1, this->numberOfColumns+1);
  Polynomial<T> characteristicPolynomial;
  std::cout << "CharPolyHelper declared charPoly" << std::endl;
  characteristicPolynomial = characteristicPolynomial * 0;
  std::cout << "CharPolyHelper zero'd out charPoly" << std::endl;
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
    std::cout << "CharPolyHelper two rows" << std::endl;
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
    /*characteristicPolynomial.setCoefficientOfTermOfOrder(0, this->getDeterminant());
    T firstOrderCoeff = (this->at(0, 1) * lambdaPositions.at(1, 0)) +
                       (this->at(1, 0) * lambdaPositions.at(0, 1)) -
                       (this->at(0, 0) * lambdaPositions.at(1, 1)) -
                       (this->at(1, 1) * lambdaPositions.at(0, 0));
    characteristicPolynomial.setCoefficientOfTermOfOrder(1, firstOrderCoeff);
    bool hasSecondDegreeTerm =
        ((lambdaPositions.at(0, 0) * lambdaPositions.at(1, 1)) + (lambdaPositions.at(0, 1) * lambdaPositions.at(1, 0))) == 1;
    if(hasSecondDegreeTerm)
    {
      characteristicPolynomial.setCoefficientOfTermOfOrder(2, 1);
    }
    else
    {
      characteristicPolynomial.setCoefficientOfTermOfOrder(2, 0);
    }*/
    return characteristicPolynomial;
  }
  else
  {
    std::cout << "CharPolyHelper over two rows" << std::endl;
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
      std::cout << "CharPolyHelper declared a poly" << std::endl;
      characteristicPolynomial = characteristicPolynomial + (polynomialForThisColumn * subMatrixCharacteristicPolynomial);
      /*for(int j = 0; j < subMatrixCharacteristicPolynomial.getNumberOfColumns(); j++)
      {
        characteristicPolynomial.at(0, j) =
            characteristicPolynomial.at(0, j) +
            (alternator * this->at(0, i) * subMatrixCharacteristicPolynomial.at(0, j));

        characteristicPolynomial.at(0, j + 1) =
            characteristicPolynomial.at(0, j + 1) +
            (alternator * -1 * lambdaPositions.at(0, i) * subMatrixCharacteristicPolynomial.at(0, j));
      }*/
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
