#ifndef NUMERICALMETHODS_H_
#define NUMERICALMETHODS_H_

#include <map>
#include <vector>
#include <iostream>
#include <math.h>
#include <typeinfo>
#include "Matrix.h"
#include "SquareMatrix.h"
#include "FactorUtil.h"
#include "Rational.h"

template<typename T>
Matrix<T> newtonRaphson(const Matrix<T> &m, int numberOfIterations);

template<typename T>
Matrix<T> computeDerivative(const Matrix<T> &polygon);

#endif /* NUMERICALMETHODS_H_ */
