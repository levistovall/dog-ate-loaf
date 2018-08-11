#include "SquareMatrix.h"

template<typename T>
SquareMatrix<T>::SquareMatrix(int dimension_) : Matrix<T>(dimension_, dimension_){}

template<typename T>
SquareMatrix<T>::SquareMatrix(const Matrix<T> &m) : Matrix<T>(m)
{
  if(m.getNumberOfColumns() != m.getNumberOfRows())
  {
    /*
     * No intuitive way to make a square matrix from a non-square matrix
     */
    throw non_square_matrix_passed_to_square_matrix_constructor_exception();
  }
}

template<typename T>
T SquareMatrix<T>::getDeterminant() const
{
  /*
   * The determinant of a 1x1 matrix is equal to its only value
   */
  if(this->numberOfRows == 1)
  {
    return this->at(0, 0);
  }
  /*
   * If the SquareMatrix A has dimension n > 1, use the fact that the determinant, in general,
   * is equal to the sum from j = 0 to j = n-1 of aij * det(Cij), where Cij is the matrix formed
   * by deleting row i and column j from A.
   */
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
  /*
   * Let this SquareMatrix be A, and consider a variable lambda. This method will
   * return the polynomial resulting from determinant(A - lambda * lambdaPositions)
   */
  Polynomial<T> characteristicPolynomial;
  characteristicPolynomial = characteristicPolynomial * 0;
  if(this->numberOfRows == 1)
  {
    /*
     * If the Square Matrix A is [[a]] then A - lambda * lambdaPositions = [[a - lambda]]
     * and the characteristic polynomial is the determinant of this,
     * then the characteristic polynomial is simply a - lambda
     */
    characteristicPolynomial =
    {
        {{}, this->at(0, 0)},
        {{{"lambda", 1}}, (-1 * lambdaPositions.at(0, 0))}
    };
    return characteristicPolynomial;
  }
  else
  {
    /*
     * If this SquareMatrix has dimension greater than 1, use the fact that
     * for any square matrix A, the determinant, in general,
     * is equal to the sum from j = 0 to j = n-1 of aij * det(Cij), where Cij is the matrix formed
     * by deleting row i and column j from A.
     */

    /*
     * The number that will be used to obtain correct cofactors
     */
    int alternator = 1;

    /*
     * For each column i of the matrix, add the product of the entry at row 0, col i and the determinant of
     * the submatrix formed by deleting row 0 and col i from this matrix to the characteristic polynomial
     * which will be returned.
     */
    for(int i = 0; i < this->numberOfColumns; i++)
    {
      /*
       * Get the matrix formed by deleting row 0 and column i of this matrix
       */
      SquareMatrix<T> subMatrix = this->getSubMatrixExcludingSpecifiedRowAndColumn(0, i);
      /*
       * Get the positions at which we should subtract lambda
       */
      SquareMatrix<T> subMatrixLambdaPositions = lambdaPositions.getSubMatrixExcludingSpecifiedRowAndColumn(0, i);
      /*
       * Recursively call getCharacteristicPolynomialHelper on the submatrix using the matrix of lambda positions
       */
      Polynomial<T> subMatrixCharacteristicPolynomial = subMatrix.getCharacteristicPolynomialHelper(subMatrixLambdaPositions);
      /*
       * Get the entry of this matrix at row 0, column i as a polynomial in lambda, using
       * the matrix lambdaPositions to determine whether there should be a lambda term.
       */
      Polynomial<T> polynomialForThisColumn =
          {
              {{}, (this->at(0, i) * alternator)},
              {{{"lambda", 1}}, (-1 * lambdaPositions.at(0, i) * alternator)}
          };
      /*
       * Add the product of the entry at row 0, col i and the corresponding minor to the
       * characteristic polynomial
       */
      characteristicPolynomial = characteristicPolynomial + (polynomialForThisColumn * subMatrixCharacteristicPolynomial);
      alternator *= -1;
    }
    return characteristicPolynomial;
  }
}

template<typename T>
SquareMatrix<T> SquareMatrix<T>::getIdentity() const
{
  /*
   * Build the identity matrix of same dimension as this
   * SquareMatrix
   */
  SquareMatrix<T> identity(this->getNumberOfRows());
  for(int i = 0; i < identity.getNumberOfRows(); i++)
  {
    for(int j = 0; j < identity.getNumberOfColumns(); j++)
    {
      /*
       * Entries on the diagonal are 1.
       */
      if(i == j)
      {
        identity.at(i, j) = 1;
      }
      /*
       * All others are 0.
       */
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
  /*
   * Get the matrix obtained by joining this SquareMatrix to the identity matrix of the same
   * dimension
   */
  Matrix<T> thisJoinedWithIdentity = this->getHorizontalJointWithOther(this->getIdentity());
  /*
   * Perform echelon row reduction on the result
   */
  Matrix<T> reducedJoint = thisJoinedWithIdentity.getRowReducedEchelonForm();
  /*
   * Take the right half; it is the inverse of this matrix if it has one, and a matrix of nan
   * if it doesn't
   */
  return reducedJoint.getColumnRangeAsMatrix(this->getNumberOfRows(), 2 * this->getNumberOfRows());
}

template class SquareMatrix<int>;
template class SquareMatrix<double>;
template class SquareMatrix<float>;
template class SquareMatrix<Rational>;
