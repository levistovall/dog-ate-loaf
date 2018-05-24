#ifndef SQUAREMATRIX_H_
#define SQUAREMATRIX_H_

#include "Matrix.h"

template<typename T>
class SquareMatrix : public Matrix<T>
{
public:
  SquareMatrix(int dimension_);
  SquareMatrix(const SquareMatrix &m);
  SquareMatrix(const Matrix<T> &m);

  T getDeterminant() const;
  SquareMatrix<T> getIdentity() const;
  SquareMatrix<T> getInverse() const;
};


#endif /* SQUAREMATRIX_H_ */
