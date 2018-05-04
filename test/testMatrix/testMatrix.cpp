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
  EXPECT_EQ(numRows, mat.getContent().size());
  int numCols = mat.getNumberOfColumns();
  EXPECT_EQ(2, numCols);
  EXPECT_EQ(numCols, mat[0].size());
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
      intMat[i][j] = (i+1) * (j+1);
      doubleMat[i][j] = (i+1) * (j+1) + 0.0005;
      floatMat[i][j] = (i+1) * (j+1) + 0.0005;
      ratMat[i][j] = Rational((i+1) * (j+1), 7);
    }
  }

  for(int i = 0; i < intMat.getNumberOfRows(); i++)
  {
    for(int j = 0; j < intMat.getNumberOfColumns(); j++)
    {
      ASSERT_EQ(intMat[i][j], (i+1) * (j+1));
      ASSERT_TRUE(abs(doubleMat[i][j] - ((i+1) * (j+1) + 0.0005)) < FLOATING_POINT_EQ_TOL_);
      ASSERT_TRUE(abs(floatMat[i][j] - ((i+1) * (j+1) + 0.0005)) < FLOATING_POINT_EQ_TOL_);
      ASSERT_EQ(ratMat[i][j], Rational((i+1) * (j+1), 7));
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
      intMat[i][j] = (i+1) * (j+1);
      doubleMat[i][j] = (i+1) * (j+1) + 0.0005;
      floatMat[i][j] = (i+1) * (j+1) + 0.0005;
      ratMat[i][j] = Rational((i+1) * (j+1), 7);
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
      ASSERT_EQ(intMat[i][j], intScalar * ((i+1) * (j+1)));
      ASSERT_TRUE(abs(doubleMat[i][j] - (doubleScalar * (i+1) * (j+1) + 0.0005)) < FLOATING_POINT_EQ_TOL_);
      ASSERT_TRUE(abs(floatMat[i][j] - (floatScalar * (i+1) * (j+1) + 0.0005)) < FLOATING_POINT_EQ_TOL_);
      ASSERT_EQ(ratMat[i][j], rationalScalar * Rational((i+1) * (j+1), 7));
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
      intLMatrix[i][j] = (((i+1) * (j+1)) * 3) % 7;
      intRMatrix[i][j] = (((i+1) * (j+1)) * 3) % 7;

      doubleLMatrix[i][j] = ((i+1.1) * (j+1.1)) * 3;
      doubleRMatrix[i][j] = ((i+1.1) * (j+1.1)) * 3;

      floatLMatrix[i][j] = ((i+1.1) * (j+1.1)) * 3;
      floatRMatrix[i][j] = ((i+1.1) * (j+1.1)) * 3;

      rationalLMatrix[i][j] = Rational(i+j+1,7);
      rationalRMatrix[i][j] = Rational(i+j+1,7);
    }
  }
  std::cout << intLMatrix;
  Matrix<int> intMatrixProduct = intLMatrix * intRMatrix;
  std::cout << intMatrixProduct;
  ASSERT_EQ(intMatrixProduct[0][0], 45);
  ASSERT_EQ(intMatrixProduct[0][1], 48);
  ASSERT_EQ(intMatrixProduct[1][0], 48);
  ASSERT_EQ(intMatrixProduct[1][1], 61);

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
  ASSERT_EQ(rationalMatrixProduct[0][0], Rational(5,49));
  ASSERT_EQ(rationalMatrixProduct[0][1], Rational(8,49));
  ASSERT_EQ(rationalMatrixProduct[1][0], Rational(8,49));
  ASSERT_EQ(rationalMatrixProduct[1][1], Rational(13,49));
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
      intLMatrix[i][j] = (((i+1) * (j+1)) * 3) % 7;
      intRMatrix[i][j] = (((i+1) * (j+1)) * 3) % 7;

      doubleLMatrix[i][j] = ((i+1.1) * (j+1.1)) * 3;
      doubleRMatrix[i][j] = ((i+1.1) * (j+1.1)) * 3;

      floatLMatrix[i][j] = ((i+1.1) * (j+1.1)) * 3;
      floatRMatrix[i][j] = ((i+1.1) * (j+1.1)) * 3;

      rationalLMatrix[i][j] = Rational(i+j+1,7);
      rationalRMatrix[i][j] = Rational(i+j+1,7);
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
      ASSERT_EQ(intMatrixSum[i][j], 2 * ((((i+1) * (j+1)) * 3) % 7));

      ASSERT_TRUE(abs(doubleMatrixSum[i][j] - (2 * (((i+1.1) * (j+1.1)) * 3))) < FLOATING_POINT_EQ_TOL_);

      ASSERT_TRUE(abs(floatMatrixSum[i][j] - (2 * (((i+1.1) * (j+1.1)) * 3))) < FLOATING_POINT_EQ_TOL_);

      ASSERT_EQ(rationalMatrixSum[i][j], 2 * (Rational(i+j+1,7)));
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
      intLMatrix[i][j] = 3 * ((((i+1) * (j+1)) * 3) % 7);
      intRMatrix[i][j] = (((i+1) * (j+1)) * 3) % 7;

      doubleLMatrix[i][j] = 3 * (((i+1.1) * (j+1.1)) * 3);
      doubleRMatrix[i][j] = ((i+1.1) * (j+1.1)) * 3;

      floatLMatrix[i][j] = 3 * (((i+1.1) * (j+1.1)) * 3);
      floatRMatrix[i][j] = ((i+1.1) * (j+1.1)) * 3;

      rationalLMatrix[i][j] = 3 * Rational(i+j+1,7);
      rationalRMatrix[i][j] = Rational(i+j+1,7);
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
      ASSERT_EQ(intMatrixDifference[i][j], 2 * ((((i+1) * (j+1)) * 3) % 7));

      ASSERT_TRUE(abs(doubleMatrixDifference[i][j] - (2 * (((i+1.1) * (j+1.1)) * 3))) < FLOATING_POINT_EQ_TOL_);

      ASSERT_TRUE(abs(floatMatrixDifference[i][j] - (2 * (((i+1.1) * (j+1.1)) * 3))) < FLOATING_POINT_EQ_TOL_);

      ASSERT_EQ(rationalMatrixDifference[i][j], 2 * (Rational(i+j+1,7)));
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
      intMatrix[i][j] = (i*3) + j;
    }
  }
  std::cout << intMatrix;
  std::cout << intMatrix.getSubMatrixExcludingSpecifiedRowAndColumn(1, 1);
}
