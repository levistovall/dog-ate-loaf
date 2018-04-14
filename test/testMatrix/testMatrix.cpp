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
  int numCols = mat.getNumberOfColumns();
  EXPECT_EQ(2, numCols);
}

TEST_F(MatrixTest, testSetContent)
{
  Matrix<int> mat(2,2);
  std::vector<int> v;
  v.push_back(2);
  v.push_back(3);
  std::vector<int> u;
  u.push_back(4);
  u.push_back(2);
  std::vector<std::vector<int>> w;
  w.push_back(v);
  w.push_back(u);
  mat.setContent(w);
  std::cout << w[0].at(1) << std::endl;
}
