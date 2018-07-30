#ifndef MATRIX_H_
#define MATRIX_H_

#include <map>
#include <vector>
#include <iostream>
#include <math.h>
#include <typeinfo>
#include "Rational.h"
#include "matrix_exceptions.h"

template<typename T>
class Matrix
{
public:
  Matrix(const int &numberOfRows_, const int &numberOfColumns_);
  Matrix(const Matrix &m);
  virtual ~Matrix();

  /*
   * the method getNumberOfRows returns the value
   * of the numberOfRows attribute of the matrix
   */
  int getNumberOfRows() const;

  /*
   * the method getNumberOfColumns returns the value
   * of the numberOfColumns attribute of the matrix
   */
  int getNumberOfColumns() const;

  Matrix<T> operator=(const Matrix &m);

  /*
   * the at methods return the value store at the input
   * row and column indices.
   */
  const T &at(int rowIdx, int columnIdx) const;
  T &at(int rowIdx, int columnIdx);

  /*
   * the method toString returns a std::string
   * of the format [[1 2]
   *                [3 4]]
   */
  std::string toString() const;

  /*
   * the method getTranspose calculates and
   * returns the transpose of the matrix object
   */
  Matrix<T> getTranspose() const;

  /*
   * the method getRowReducedEchelonForm calculates and returns the
   * row-reduced echeclon form of the matrix
   */
  Matrix<T> getRowReducedEchelonForm() const;

  /*
   * the method getSubMatrixExcludingSpecifiedRowAndColumn returns
   * the matrix yielded by removing the row at the index specified
   * by rowIdxToNix and the column specified by colIdxToNix
   *
   * this method is largely motivated by the need to achieve this end
   * during calculation of the determinant.
   */
  Matrix<T> getSubMatrixExcludingSpecifiedRowAndColumn(int rowToNixIdx, int colToNixIdx) const;

  /*
   * the method getColumnRangeAsMatrix selects the columns in the matrix object
   * for colStartIdx inclusive to colEndIdx exclusive and returns the matrix composed
   * of the selected columns.
   */
  Matrix<T> getColumnRangeAsMatrix(int colStartIdx, int colEndIdx) const;
protected:
  /*
   * the vector of vectors content contains the values that make up the matrix
   */
  std::vector<std::vector<T> > content;
  int numberOfRows;
  int numberOfColumns;

  /*
   * the method getHoriontalJointWithOther returns the matrix formed
   * by joining every row in this matrix object with the
   * corresponding row of other, but will throw an
   * incompatible_matrix_horizontal_joint_exception if other
   * does not have the same number of rows as this matrix.
   */
  Matrix<T> getHorizontalJointWithOther(Matrix<T> other) const;
};

template<typename T>
std::ostream &operator<<(std::ostream &out, Matrix<T> const &m)
{
  out << m.toString();
  return out;
}

/*
 * Scalar multiplication of matrices
 */
template<typename T1, typename T2>
auto operator*(const T1 &t1, const Matrix<T2> &a) -> Matrix<decltype(T1{} * T2{})>
{
  Matrix<decltype(T1{} * T2{})> result(a.getNumberOfRows(), a.getNumberOfColumns());
  for(int i = 0; i < result.getNumberOfRows(); i++)
  {
    for(int j = 0; j < result.getNumberOfColumns(); j++)
    {
      result.at(i, j) = a.at(i, j) * t1;
    }
  }
  return result;
}

/*
 * Scalar multiplication of matrices
 */
template<typename T1, typename T2>
auto operator*(const Matrix<T1> &a, const T2 &t2) -> Matrix<decltype(T1{} * T2{})>
{
  return t2 * a;
}

/*
 * Matrix multiplication
 */
template<typename T1, typename T2>
auto operator*(const Matrix<T1> &a, const Matrix<T2> &b) -> Matrix<decltype(T1{} * T2{})>
{
  /*
   * In order to multiply matrix a by matrix b as a * b,
   * the number of columns in a must be equal to the number of rows
   * in b.
   */
  if(a.getNumberOfColumns() == b.getNumberOfRows())
  {
    /*
     * The matrix product will have the same number of rows as a
     * and the same number of columns as b
     */
    Matrix<decltype(T1{} * T2{})> result(a.getNumberOfRows(), b.getNumberOfColumns());

    /*
     * For the ith row in matrix a
     */
    for(int i = 0; i < a.getNumberOfRows(); i++)
    {
      /*
       * Get its dot product with the jth row in b
       * for every j
       */
      for(int j = 0; j < b.getNumberOfColumns(); j++)
      {
        /*
         * and store the result at the ith row and jth column
         * of the matrix product.
         */
        result.at(i, j) = 0;
        for(int k = 0; k < a.getNumberOfColumns(); k++)
        {
          result.at(i, j) += a.at(i, k) * b.at(k, j);
        }
      }
    }
    return result;
  }
  else
  {
    throw incompatible_matrix_multiplicands_exception();
  }
}

/*
 * Matrix addition
 */
template<typename T1, typename T2>
auto operator+(const Matrix<T1> &a, const Matrix<T2> &b) -> Matrix<decltype(T1{} + T2{})>
{
  /*
   * if the addends do not have the same numbers of rows and columns,
   * we can't add them
   */
  if(((a.getNumberOfRows() == b.getNumberOfRows()) && (a.getNumberOfColumns() == b.getNumberOfColumns())))
  {
    /*
     * The sum matrix will have the same dimensions as the addends
     */
    Matrix<decltype(T1{} * T2{})> result(a.getNumberOfRows(), a.getNumberOfColumns());

    /*
     * The value at the ith row and jth column of the sum
     * should be the sum of the values at the ith row and jth
     * column of the addends
     */
    for(int i = 0; i < result.getNumberOfRows(); i++)
    {
      for(int j = 0; j < result.getNumberOfColumns(); j++)
      {
        result.at(i, j) = a.at(i, j) + b.at(i, j);
      }
    }
    return result;
  }
  else
  {
    throw incompatible_matrix_addends_exception();
  }
}

/*
 * Matrix subtraction
 */
template<typename T1, typename T2>
auto operator-(const Matrix<T1> &a, const Matrix<T2> &b) -> Matrix<decltype(T1{} - T2{})>
{
  /*
   * add b scalar multipled by -1
   */
  return (a + (-1 * b));
}

#endif
