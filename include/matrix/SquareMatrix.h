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
  Polynomial<T> getCharacteristicPolynomial() const;
  Polynomial<T> getCharacteristicPolynomialHelper(const SquareMatrix<T> &lambdaPositions) const;

};


#endif /* SQUAREMATRIX_H_ */
