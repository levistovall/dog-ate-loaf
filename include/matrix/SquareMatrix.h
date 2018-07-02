#ifndef SQUAREMATRIX_H_
#define SQUAREMATRIX_H_

#include "Matrix.h"

template<typename T>
class SquareMatrix : public Matrix<T>
{
public:
  SquareMatrix(int dimension_);
  SquareMatrix(const SquareMatrix<T> &m);
  SquareMatrix(const Matrix<T> &m);

  Matrix<T> getCharacteristicPolynomial() const;
  Matrix<T> getCharacteristicPolynomialHelper(const SquareMatrix<T> &lambdaPositions) const;
  T getDeterminant() const;
  SquareMatrix<T> getIdentity() const;
  SquareMatrix<T> getInverse() const;

private:

};


#endif /* SQUAREMATRIX_H_ */
