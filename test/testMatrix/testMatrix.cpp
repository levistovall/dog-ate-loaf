#include "testMatrix.h"

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
      //ASSERT_EQ(doubleMat[i][j], (i+1) * (j+1) + 0.0005);
      //ASSERT_EQ(floatMat[i][j], (i+1) * (j+1) + 0.0005);
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
      //ASSERT_EQ(doubleMat[i][j], doubleScalar * ((i+1) * (j+1) + 0.0005));
      //ASSERT_EQ(floatMat[i][j], floatScalar * ((i+1) * (j+1) + 0.0005));
      ASSERT_EQ(ratMat[i][j], rationalScalar * Rational((i+1) * (j+1), 7));
    }
  }
}

TEST_F(MatrixTest, testMatrixMultiplication)
{
  Matrix<int> intLMatrix(2,2);

  Matrix<int> intRMatrix(2,2);

  for(int i = 0; i < intLMatrix.getNumberOfRows(); i++)
  {
    for(int j = 0; j < intLMatrix.getNumberOfColumns(); j++)
    {
      intLMatrix[i][j] = (((i+1) * (j+1)) * 3) % 7;
      intRMatrix[i][j] = (((i+1) * (j+1)) * 3) % 7;
    }
  }
  std::cout << intLMatrix;
  Matrix<int> intMatrixProduct = intLMatrix * intRMatrix;
  std::cout << intMatrixProduct;
  ASSERT_EQ(intMatrixProduct[0][0], 45);
  ASSERT_EQ(intMatrixProduct[0][1], 48);
  ASSERT_EQ(intMatrixProduct[1][0], 48);
  ASSERT_EQ(intMatrixProduct[1][1], 61);
}

