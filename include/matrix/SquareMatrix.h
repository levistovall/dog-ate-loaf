#ifndef SQUAREMATRIX_H_
#define SQUAREMATRIX_H_

#include "Matrix.h"

template<typename T>
class SquareMatrix : public Matrix<T>
{
public:
  SquareMatrix(int dimension_);
  SquareMatrix(const SquareMatrix &m);
  SquareMatrix(const Matrix &m);

  T getDeterminant() const;
};


#endif /* SQUAREMATRIX_H_ */
