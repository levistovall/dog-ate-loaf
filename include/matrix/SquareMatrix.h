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

  Polynomial<T> getCharacteristicPolynomial() const;
  Polynomial<T> getCharacteristicPolynomialHelper(const SquareMatrix<T> &lambdaPositions) const;
  T getDeterminant() const;
  SquareMatrix<T> getIdentity() const;
  SquareMatrix<T> getInverse() const;

private:

};


#endif /* SQUAREMATRIX_H_ */
