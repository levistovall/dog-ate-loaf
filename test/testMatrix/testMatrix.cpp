#include "testMatrix.h"

#define FLOATING_POINT_EQ_TOL_ 1e-10

MatrixTest::MatrixTest()
{}

MatrixTest::~MatrixTest()
{}

void MatrixTest::SetUp()
{}

void MatrixTest::TearDown()
{}

TEST_F(MatrixTest, testGetNumberOfRowsAndGetNumberOfRows)
{
  Matrix<int> mat(2,2);
  int numRows = mat.getNumberOfRows();
  EXPECT_EQ(2, numRows);
  int numCols = mat.getNumberOfColumns();
  EXPECT_EQ(2, numCols);
}

TEST_F(MatrixTest, testContentGetters)
{
  Matrix<int> intMat(2,2);
  Matrix<double> doubleMat(2,2);
  Matrix<float> floatMat(2,2);
  Matrix<Rational> ratMat(2,2);
  for(int i = 0; i < intMat.getNumberOfRows(); i++)
  {
    for(int j = 0; j < intMat.getNumberOfColumns(); j++)
    {
      intMat.at(i,j) = (i+1) * (j+1);
      doubleMat.at(i,j) = (i+1) * (j+1) + 0.0005;
      floatMat.at(i,j) = (i+1) * (j+1) + 0.0005;
      ratMat.at(i,j) = Rational((i+1) * (j+1), 7);
      std::cout << "i,j : " << intMat.at(i,j) << std::endl;
    }
  }

  for(int i = 0; i < intMat.getNumberOfRows(); i++)
  {
    for(int j = 0; j < intMat.getNumberOfColumns(); j++)
    {
      ASSERT_EQ(intMat.at(i,j), (i+1) * (j+1));
      ASSERT_TRUE(abs(doubleMat.at(i,j) - ((i+1) * (j+1) + 0.0005)) < FLOATING_POINT_EQ_TOL_);
      ASSERT_TRUE(abs(floatMat.at(i,j) - ((i+1) * (j+1) + 0.0005)) < FLOATING_POINT_EQ_TOL_);
      ASSERT_EQ(ratMat.at(i,j), Rational((i+1) * (j+1), 7));
    }
  }
}

TEST_F(MatrixTest, testScalarMultiplication)
{
  const int intScalar = 3;
  const double doubleScalar = 3.02;
  const float floatScalar = 3.2;
  const Rational rationalScalar(3,7);

  Matrix<int> intMat(3,2);
  Matrix<double> doubleMat(3,2);
  Matrix<float> floatMat(3,2);
  Matrix<Rational> ratMat(3,2);
  for(int i = 0; i < intMat.getNumberOfRows(); i++)
  {
    for(int j = 0; j < intMat.getNumberOfColumns(); j++)
    {
      intMat.at(i,j) = (i+1) * (j+1);
      doubleMat.at(i,j) = (i+1) * (j+1) + 0.0005;
      floatMat.at(i,j) = (i+1) * (j+1) + 0.0005;
      ratMat.at(i,j) = Rational((i+1) * (j+1), 7);
    }
  }

  std::cout << intMat;
  std::cout << doubleMat;
  std::cout << floatMat;
  std::cout << ratMat;

  intMat = intMat * intScalar;
  doubleMat = doubleMat * doubleScalar;
  floatMat = floatMat * floatScalar;
  ratMat = ratMat * rationalScalar;

  std::cout << intMat;
  std::cout << doubleMat;
  std::cout << floatMat;
  std::cout << ratMat;

  for(int i = 0; i < intMat.getNumberOfRows(); i++)
  {
    for(int j = 0; j < intMat.getNumberOfColumns(); j++)
    {
      ASSERT_EQ(intMat.at(i,j), intScalar * ((i+1) * (j+1)));
      ASSERT_TRUE(abs(doubleMat.at(i,j) - (doubleScalar * (i+1) * (j+1) + 0.0005)) < FLOATING_POINT_EQ_TOL_);
      ASSERT_TRUE(abs(floatMat.at(i,j) - (floatScalar * (i+1) * (j+1) + 0.0005)) < FLOATING_POINT_EQ_TOL_);
      ASSERT_EQ(ratMat.at(i,j), rationalScalar * Rational((i+1) * (j+1), 7));
    }
  }
}

TEST_F(MatrixTest, testMatrixMultiplication)
{
  Matrix<int> intLMatrix(2,2);
  Matrix<double> doubleLMatrix(2,2);
  Matrix<float> floatLMatrix(2,2);
  Matrix<Rational> rationalLMatrix(2,2);

  Matrix<int> intRMatrix(2,2);
  Matrix<double> doubleRMatrix(2,2);
  Matrix<float> floatRMatrix(2,2);
  Matrix<Rational> rationalRMatrix(2,2);

  for(int i = 0; i < intLMatrix.getNumberOfRows(); i++)
  {
    for(int j = 0; j < intLMatrix.getNumberOfColumns(); j++)
    {
      intLMatrix.at(i,j) = (((i+1) * (j+1)) * 3) % 7;
      intRMatrix.at(i,j) = (((i+1) * (j+1)) * 3) % 7;

      doubleLMatrix.at(i,j) = ((i+1.1) * (j+1.1)) * 3;
      doubleRMatrix.at(i,j) = ((i+1.1) * (j+1.1)) * 3;

      floatLMatrix.at(i,j) = ((i+1.1) * (j+1.1)) * 3;
      floatRMatrix.at(i,j) = ((i+1.1) * (j+1.1)) * 3;

      rationalLMatrix.at(i,j) = Rational(i+j+1,7);
      rationalRMatrix.at(i,j) = Rational(i+j+1,7);
    }
  }
  std::cout << intLMatrix;
  Matrix<int> intMatrixProduct = intLMatrix * intRMatrix;
  std::cout << intMatrixProduct;
  ASSERT_EQ(intMatrixProduct.at(0,0), 45);
  ASSERT_EQ(intMatrixProduct.at(0,1), 48);
  ASSERT_EQ(intMatrixProduct.at(1,0), 48);
  ASSERT_EQ(intMatrixProduct.at(1,1), 61);

  std::cout << doubleLMatrix;
  Matrix<double> doubleMatrixProduct = doubleLMatrix * doubleRMatrix;
  std::cout << doubleMatrixProduct;
  /*ASSERT_EQ(doubleMatrixProduct[0][0], 45);
  ASSERT_EQ(doubleMatrixProduct[0][1], 48);
  ASSERT_EQ(doubleMatrixProduct[1][0], 48);
  ASSERT_EQ(doubleMatrixProduct[1][1], 61);*/

  std::cout << floatLMatrix;
  Matrix<float> floatMatrixProduct = floatLMatrix * floatRMatrix;
  std::cout << floatMatrixProduct;
  /*ASSERT_EQ(floatMatrixProduct[0][0], 45);
  ASSERT_EQ(floatMatrixProduct[0][1], 48);
  ASSERT_EQ(floatMatrixProduct[1][0], 48);
  ASSERT_EQ(floatMatrixProduct[1][1], 61);*/

  std::cout << rationalLMatrix;
  Matrix<Rational> rationalMatrixProduct = rationalLMatrix * rationalRMatrix;
  std::cout << rationalMatrixProduct;
  ASSERT_EQ(rationalMatrixProduct.at(0,0), Rational(5,49));
  ASSERT_EQ(rationalMatrixProduct.at(0,1), Rational(8,49));
  ASSERT_EQ(rationalMatrixProduct.at(1,0), Rational(8,49));
  ASSERT_EQ(rationalMatrixProduct.at(1,1), Rational(13,49));
}

TEST_F(MatrixTest, testMatrixAddition)
{
  Matrix<int> intLMatrix(2,2);
  Matrix<double> doubleLMatrix(2,2);
  Matrix<float> floatLMatrix(2,2);
  Matrix<Rational> rationalLMatrix(2,2);

  Matrix<int> intRMatrix(2,2);
  Matrix<double> doubleRMatrix(2,2);
  Matrix<float> floatRMatrix(2,2);
  Matrix<Rational> rationalRMatrix(2,2);

  for(int i = 0; i < intLMatrix.getNumberOfRows(); i++)
  {
    for(int j = 0; j < intLMatrix.getNumberOfColumns(); j++)
    {
      intLMatrix.at(i,j) = (((i+1) * (j+1)) * 3) % 7;
      intRMatrix.at(i,j) = (((i+1) * (j+1)) * 3) % 7;

      doubleLMatrix.at(i,j) = ((i+1.1) * (j+1.1)) * 3;
      doubleRMatrix.at(i,j) = ((i+1.1) * (j+1.1)) * 3;

      floatLMatrix.at(i,j) = ((i+1.1) * (j+1.1)) * 3;
      floatRMatrix.at(i,j) = ((i+1.1) * (j+1.1)) * 3;

      rationalLMatrix.at(i,j) = Rational(i+j+1,7);
      rationalRMatrix.at(i,j) = Rational(i+j+1,7);
    }
  }
  std::cout << intLMatrix;
  Matrix<int> intMatrixSum = intLMatrix + intRMatrix;
  std::cout << intMatrixSum;

  std::cout << doubleLMatrix;
  Matrix<double> doubleMatrixSum = doubleLMatrix + doubleRMatrix;
  std::cout << doubleMatrixSum;

  std::cout << floatLMatrix;
  Matrix<float> floatMatrixSum = floatLMatrix + floatRMatrix;
  std::cout << floatMatrixSum;

  std::cout << rationalLMatrix;
  Matrix<Rational> rationalMatrixSum = rationalLMatrix + rationalRMatrix;
  std::cout << rationalMatrixSum;

  for(int i = 0; i < intLMatrix.getNumberOfRows(); i++)
  {
    for(int j = 0; j < intLMatrix.getNumberOfColumns(); j++)
    {
      ASSERT_EQ(intMatrixSum.at(i,j), 2 * ((((i+1) * (j+1)) * 3) % 7));

      ASSERT_TRUE(abs(doubleMatrixSum.at(i,j) - (2 * (((i+1.1) * (j+1.1)) * 3))) < FLOATING_POINT_EQ_TOL_);

      ASSERT_TRUE(abs(floatMatrixSum.at(i,j) - (2 * (((i+1.1) * (j+1.1)) * 3))) < FLOATING_POINT_EQ_TOL_);

      ASSERT_EQ(rationalMatrixSum.at(i,j), 2 * (Rational(i+j+1,7)));
    }
  }
}

TEST_F(MatrixTest, testMatrixSubtraction)
{
  Matrix<int> intLMatrix(2,2);
  Matrix<double> doubleLMatrix(2,2);
  Matrix<float> floatLMatrix(2,2);
  Matrix<Rational> rationalLMatrix(2,2);

  Matrix<int> intRMatrix(2,2);
  Matrix<double> doubleRMatrix(2,2);
  Matrix<float> floatRMatrix(2,2);
  Matrix<Rational> rationalRMatrix(2,2);

  for(int i = 0; i < intLMatrix.getNumberOfRows(); i++)
  {
    for(int j = 0; j < intLMatrix.getNumberOfColumns(); j++)
    {
      intLMatrix.at(i,j) = 3 * ((((i+1) * (j+1)) * 3) % 7);
      intRMatrix.at(i,j) = (((i+1) * (j+1)) * 3) % 7;

      doubleLMatrix.at(i,j) = 3 * (((i+1.1) * (j+1.1)) * 3);
      doubleRMatrix.at(i,j) = ((i+1.1) * (j+1.1)) * 3;

      floatLMatrix.at(i,j) = 3 * (((i+1.1) * (j+1.1)) * 3);
      floatRMatrix.at(i,j) = ((i+1.1) * (j+1.1)) * 3;

      rationalLMatrix.at(i,j) = 3 * Rational(i+j+1,7);
      rationalRMatrix.at(i,j) = Rational(i+j+1,7);
    }
  }
  std::cout << intLMatrix;
  Matrix<int> intMatrixDifference = intLMatrix - intRMatrix;
  std::cout << intMatrixDifference;

  std::cout << doubleLMatrix;
  Matrix<double> doubleMatrixDifference = doubleLMatrix - doubleRMatrix;
  std::cout << doubleMatrixDifference;

  std::cout << floatLMatrix;
  Matrix<float> floatMatrixDifference = floatLMatrix - floatRMatrix;
  std::cout << floatMatrixDifference;

  std::cout << rationalLMatrix;
  Matrix<Rational> rationalMatrixDifference = rationalLMatrix - rationalRMatrix;
  std::cout << rationalMatrixDifference;

  for(int i = 0; i < intLMatrix.getNumberOfRows(); i++)
  {
    for(int j = 0; j < intLMatrix.getNumberOfColumns(); j++)
    {
      ASSERT_EQ(intMatrixDifference.at(i,j), 2 * ((((i+1) * (j+1)) * 3) % 7));

      ASSERT_TRUE(abs(doubleMatrixDifference.at(i,j) - (2 * (((i+1.1) * (j+1.1)) * 3))) < FLOATING_POINT_EQ_TOL_);

      ASSERT_TRUE(abs(floatMatrixDifference.at(i,j) - (2 * (((i+1.1) * (j+1.1)) * 3))) < FLOATING_POINT_EQ_TOL_);

      ASSERT_EQ(rationalMatrixDifference.at(i,j), 2 * (Rational(i+j+1,7)));
    }
  }
}

TEST_F(MatrixTest, testGetSubMatrix)
{
  Matrix<int> intMatrix(3, 3);
  for(int i = 0; i < intMatrix.getNumberOfRows(); i++)
  {
    for(int j = 0; j < intMatrix.getNumberOfColumns(); j++)
    {
      intMatrix.at(i,j) = (i*3) + j + 1;
    }
  }
  std::cout << intMatrix;
  Matrix<int> subMatrix = intMatrix.getSubMatrixExcludingSpecifiedRowAndColumn(1, 1);
  std::cout << subMatrix;
  ASSERT_EQ(subMatrix.at(0,0), intMatrix.at(0,0));
  ASSERT_EQ(subMatrix.at(0,1), intMatrix.at(0,2));
  ASSERT_EQ(subMatrix.at(1,0), intMatrix.at(2,0));
  ASSERT_EQ(subMatrix.at(1,1), intMatrix.at(2,2));
}

TEST_F(MatrixTest, testGetDeterminant)
{
  SquareMatrix<int> intMatrix(2);
  SquareMatrix<int> intMatrix2(2);
  for(int i = 0; i < intMatrix.getNumberOfRows(); i++)
  {
    for(int j = 0; j < intMatrix.getNumberOfColumns(); j++)
    {
      intMatrix.at(i,j) = (i*intMatrix.getNumberOfRows()) + j + 1;
      intMatrix2.at(i,j) = (i*intMatrix.getNumberOfRows()) + j + 1;
    }
  }
  SquareMatrix<int> intMatrixSum = intMatrix + intMatrix2;
  std::cout << "Determinant of " << intMatrixSum << " is " << intMatrixSum.getDeterminant() << std::endl;
  int intDeterminant = intMatrix.getDeterminant();
  std::cout << "Determinant of " << intMatrix << " is " << intDeterminant << std::endl;
  ASSERT_EQ(intDeterminant, -2);

  SquareMatrix<Rational> rationalMatrix(3);
  for(int i = 0; i < rationalMatrix.getNumberOfRows(); i++)
  {
    for(int j = 0; j < rationalMatrix.getNumberOfColumns(); j++)
    {
      rationalMatrix.at(i,j) = Rational((i*rationalMatrix.getNumberOfRows()) + j + 1, 10);
    }
  }
  Rational rationalDeterminant = rationalMatrix.getDeterminant();
  std::cout << "Determinant of " << rationalMatrix << " is " << rationalDeterminant << std::endl;
  ASSERT_EQ(rationalDeterminant, 0);
}

TEST_F(MatrixTest, testGetInverse)
{
  SquareMatrix<Rational> rationalMatrix(3);
  for(int i = 0; i < rationalMatrix.getNumberOfRows(); i++)
  {
    for(int j = 0; j < rationalMatrix.getNumberOfColumns(); j++)
    {
      rationalMatrix.at(i,j) = Rational((i*rationalMatrix.getNumberOfRows()) + j + 1, 10);
    }
  }
  rationalMatrix.at(1, 1) = 1;
  Rational rationalDeterminant = rationalMatrix.getDeterminant();
  std::cout << "Determinant of " << rationalMatrix << " is " << rationalDeterminant << std::endl;
  ASSERT_EQ(rationalDeterminant, Rational(-3, 50));

  SquareMatrix<Rational> rationalInverse = rationalMatrix.getInverse();
  std::cout << "Inverse of " << rationalMatrix << " is " << rationalInverse << std::endl;
  SquareMatrix<Rational> productOfRationalMatrixAndInverse = rationalMatrix * rationalInverse;

  std::cout << "product: " << productOfRationalMatrixAndInverse << std::endl;
  for(int i = 0; i < productOfRationalMatrixAndInverse.getNumberOfRows(); i++)
  {
    for(int j = 0; j < productOfRationalMatrixAndInverse.getNumberOfColumns(); j++)
    {
      if(i == j)
      {
        ASSERT_EQ(1, productOfRationalMatrixAndInverse.at(i, j));
      }
      else
      {
        ASSERT_EQ(0, productOfRationalMatrixAndInverse.at(i, j));
      }
    }
  }

  SquareMatrix<double> nonInvertible(2);
  nonInvertible.at(0, 0) = 1;
  nonInvertible.at(0, 1) = 1;
  nonInvertible.at(1, 0) = 1;
  nonInvertible.at(1, 1) = 1;
  std::cout << nonInvertible.getInverse() << std::endl;
}

TEST_F(MatrixTest, testGetCharacteristicPolynomial)
{
  SquareMatrix<Rational> rationalMatrix(3);
  rationalMatrix.at(0, 0) = 2;
  rationalMatrix.at(0, 1) = 1;
  rationalMatrix.at(0, 2) = 5;
  rationalMatrix.at(1, 0) = 1;
  rationalMatrix.at(1, 1) = 3;
  rationalMatrix.at(1, 2) = 4;
  rationalMatrix.at(2, 0) = 7;
  rationalMatrix.at(2, 1) = 4;
  rationalMatrix.at(2, 2) = 9;
  std::cout << "Characteristic polynomial of " << rationalMatrix << " is " << rationalMatrix.getCharacteristicPolynomial() << std::endl;
  std::cout << "and determinant " << rationalMatrix.getDeterminant() << std::endl;
  Polynomial<double> p =
      {
          {{}, -3},
          {{{"x", 1}}, 4}
      };
  std::cout << p << std::endl;
  Polynomial<double> q =
      {
          {{}, 2},
          {{{"x", 1}}, 2}
      };
  std::cout << q << std::endl;
  std::cout << p * q << std::endl;
  std::cout << q * p << std::endl;
  std::cout << p + q << std::endl;
  ASSERT_TRUE(true);
}
