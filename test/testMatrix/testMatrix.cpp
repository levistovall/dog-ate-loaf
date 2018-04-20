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
  Matrix<int> mat(2,2);
  for(int i = 0; i < mat.getNumberOfRows(); i++)
  {
    for(int j = 0; j < mat.getNumberOfColumns(); j++)
    {
      mat[i][j] = (i+1) * (j+1);
    }
  }

  for(int i = 0; i < mat.getNumberOfRows(); i++)
  {
    for(int j = 0; j < mat.getNumberOfColumns(); j++)
    {
      ASSERT_EQ(mat[i][j], (i+1) * (j+1));
    }
  }
}

TEST_F(MatrixTest, testScalarMultiplication)
{
  Matrix<int> mat1(3, 2);
  for(int i = 0; i < mat1.getNumberOfRows(); i++)
  {
    for(int j = 0; j < mat1.getNumberOfColumns(); j++)
    {
      mat1[i][j] = (i+1) * (j+1);
      std::cout << mat1[i][j] << " ";
    }
    std::cout << std::endl;
  }

  Matrix<int> mat2 = 3 * mat1;
}
