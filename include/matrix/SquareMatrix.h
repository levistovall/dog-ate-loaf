#ifndef SQUAREMATRIX_H_
#define SQUAREMATRIX_H_

#include "Matrix.h"
#include "Polynomial.h"

template<typename T>
class SquareMatrix : public Matrix<T>
{
public:
  SquareMatrix(int dimension_);
  SquareMatrix(const SquareMatrix<T> &m);
  SquareMatrix(const Matrix<T> &m);

  /*
   * the method getDeterminant returns the determinant
   * of the square matrix
   */
  T getDeterminant() const;

  /*
   * the method getIdentity returns a square matrix of the same
   * dimensions as this matrix with a 1 in every position where
   * the row index is equal to the column index and a 0 in every
   * other position
   */
  SquareMatrix<T> getIdentity() const;

  /*
   * the method getInverse returns the inverse of the square matrix if it
   * has one,
   */
  SquareMatrix<T> getInverse() const;

  /*
   * the method getCharacteristicPolynomial returns the CharacteristicPolynomial
   * of the SquareMatrix by calling getCharacteristicPolynomialHelper with the
   * identity matrix as its argument.
   */
  Polynomial<T> getCharacteristicPolynomial() const;

  /*
   * the method getCharacteristicPolynomialHelper returns the determinant in
   * polynomial form of the SquareMatrix - lambda * lambdaPositions
   */
  Polynomial<T> getCharacteristicPolynomialHelper(const SquareMatrix<T> &lambdaPositions) const;

};


#endif /* SQUAREMATRIX_H_ */
