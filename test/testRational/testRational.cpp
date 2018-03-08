#include "testRational.h"

//using ::testing::Return;

RationalTest::RationalTest()
{}

RationalTest::~RationalTest()
{}

void RationalTest::SetUp()
{}

void RationalTest::TearDown()
{}

TEST_F(RationalTest, firstTestOfProj) 
{
  Rational r(5,8);
  Rational q(4,7);
  Rational s(5,14);
  EXPECT_EQ((r * q), s);
}
