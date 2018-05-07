#include "testRational.h"

RationalTest::RationalTest()
{}

RationalTest::~RationalTest()
{}

void RationalTest::SetUp()
{}

void RationalTest::TearDown()
{}

TEST_F(RationalTest, testConstructor)
{
  bool caughtException = false;
  try
  {
    Rational r(1, 0);
  }
  catch(const division_by_zero_exception &e)
  {
    caughtException = true;
    std::cout << e.what() << std::endl;
  }
  ASSERT_TRUE(caughtException);

  Rational q(0, 50);
  ASSERT_TRUE(q.getDenominator() == 1);

  Rational s(4, 16);
  ASSERT_EQ(1, s.getNumerator());
  ASSERT_EQ(4, s.getDenominator());
}

TEST_F(RationalTest, testGetNumerator) 
{
  Rational r(5,8);
  int n = r.getNumerator();
  EXPECT_EQ(5, n);
}

TEST_F(RationalTest, testGetDenominator) 
{
  Rational r(5,8);
  int n = r.getDenominator();
  EXPECT_EQ(8, n);
}

TEST_F(RationalTest, testGetPrimeFac) 
{
  Rational r(5,8);
  std::map<int,int> primeFac = r.getPrimeFac();
  EXPECT_EQ(1, primeFac[5]);
  EXPECT_EQ(-3, primeFac[2]);
}

TEST_F(RationalTest, testToString) 
{
  Rational r(1,2);
  std::string expectedString = "(1/2)";
  EXPECT_EQ(0, expectedString.compare(r.toString()));
}

TEST_F(RationalTest, testToDouble) 
{
  Rational r(1,2);
  double d = r.toDouble();
  EXPECT_EQ(0.5, d);
}

TEST_F(RationalTest, testToFloat) 
{
  Rational r(1,2);
  float f = r.toFloat();
  EXPECT_EQ(0.5, f);
}

TEST_F(RationalTest, testToInteger) 
{
  Rational r(109,10);
  int i = r.toInteger();
  EXPECT_EQ(10, i);
}

TEST_F(RationalTest, testAdditionAssignmentRational) 
{
  Rational r(3,2);
  Rational q(5,2);
  r += q;
  EXPECT_EQ(4, r);
}

TEST_F(RationalTest, testAdditionAssignmentInt) 
{
  Rational r(3,2);
  r += 3;
  Rational q(9,2);
  EXPECT_EQ(q, r);
}

TEST_F(RationalTest, testSubtractionAssignmentRational) 
{
  Rational r(3,2);
  Rational q(1,2);
  r -= q;
  EXPECT_EQ(1, r);
}

TEST_F(RationalTest, testSubtractionAssignmentInt) 
{
  Rational r(3,2);
  r -= 1;
  Rational q(1,2);
  EXPECT_EQ(q, r);
}

TEST_F(RationalTest, testMultiplicationAssignmentRational) 
{
  Rational r(3,2);
  Rational q(1,2);
  r *= q;
  Rational s(3,4);
  EXPECT_EQ(s, r);
}

TEST_F(RationalTest, testMultiplicationAssignmentInt) 
{
  Rational r(3,2);
  r *= 3;
  Rational q(9,2);
  EXPECT_EQ(q, r);
}

TEST_F(RationalTest, testDivisionAssignmentRational) 
{
  Rational r(3,2);
  Rational q(1,2);
  r /= q;
  Rational s(3,1);
  EXPECT_EQ(s, r);
}

TEST_F(RationalTest, testDivisionAssignmentInt) 
{
  Rational r(3,2);
  r /= 3;
  Rational q(1,2);
  EXPECT_EQ(q, r);
}

TEST_F(RationalTest, testAdditionRational)
{
  Rational r(4,7);
  Rational q(5,9);
  Rational s(71,63);
  EXPECT_EQ((r+q),s);
  EXPECT_EQ((r+q),(q+r));
}

TEST_F(RationalTest, testAdditionInteger)
{
  Rational r(4,8);
  Rational s(7,2);
  EXPECT_EQ((r+3),s);
  EXPECT_EQ((r+3),(3+r));
}

TEST_F(RationalTest, testAdditionFloat)
{
  Rational r(4,8);
  float f = 0.2;
  float g = 0.7;
  EXPECT_EQ((r+f),g);
  EXPECT_EQ((r+f),(f+r));
}

TEST_F(RationalTest, testAdditionDouble)
{
  Rational r(4,8);
  double d1 = 0.2;
  double d2 = 0.7;
  EXPECT_EQ((r+d1),d2);
  EXPECT_EQ((r+d1),(d1+r));
}

TEST_F(RationalTest, testSubtractionRational)
{
  Rational r(4,7);
  Rational q(5,9);
  Rational s(1,63);
  Rational p(-1,63);
  EXPECT_EQ((r-q),s);
  EXPECT_EQ(p,(q-r));
}

TEST_F(RationalTest, testSubtractionInteger)
{
  Rational r(4,8);
  Rational s(-5,2);
  Rational p(5,2);
  EXPECT_EQ((r-3),s);
  EXPECT_EQ(p,(3-r));
}

TEST_F(RationalTest, testSubtractionFloat)
{
  Rational r(4,8);
  float f = 0.2;
  float g = 0.3;
  float h = -0.3;
  EXPECT_EQ((r-f),g);
  EXPECT_EQ(h,(f-r));
}

TEST_F(RationalTest, testSubtractionDouble)
{
  Rational r(4,8);
  double d1 = 0.2;
  double d2 = 0.3;
  double d3 = -0.3;
  EXPECT_EQ((r-d1),d2);
  EXPECT_EQ(d3,(d1-r));
}

TEST_F(RationalTest, testMultiplicationRational) 
{
  Rational r(5,8);
  Rational q(4,7);
  Rational s(5,14);
  EXPECT_EQ((r * q), s);
  EXPECT_EQ((r * q), (r * q));
}

TEST_F(RationalTest, testMultiplicationInteger)
{
  Rational r(5,8);
  Rational q(25,8);
  EXPECT_EQ((r*5),q);
  EXPECT_EQ((r*5),(5*r));
}

TEST_F(RationalTest, testMultiplicationFloat)
{
  Rational r(4,8);
  float f = 0.2;
  float g = 0.1;
  EXPECT_EQ((r*f),g);
  EXPECT_EQ((r*f),(f*r));
}

TEST_F(RationalTest, testMultiplicationDouble)
{
  Rational r(4,8);
  double d1 = 0.2;
  double d2 = 0.1;
  EXPECT_EQ((r*d1),d2);
  EXPECT_EQ((r*d1),(d1*r));
}

TEST_F(RationalTest, testDivisionRational)
{
  Rational r(4,7);
  Rational q(5,9);
  Rational s(36,35);
  Rational p(35,36);
  Rational u(1,1);
  EXPECT_EQ((r/q),s);
  EXPECT_EQ(p,(q/r));
  EXPECT_EQ(u,(q/r)*(r/q));
}

TEST_F(RationalTest, testDivisionInteger)
{
  Rational r(4,8);
  Rational s(1,6);
  Rational p(6,1);
  Rational u(1,1);
  EXPECT_EQ((r/3),s);
  EXPECT_EQ(p,(3/r));
  EXPECT_EQ(u,(3/r)*(r/3));
}

TEST_F(RationalTest, testDivisionFloat)
{
  Rational r(4,8);
  float f = 0.2;
  float g = 2.5;
  float h = 0.4;
  EXPECT_EQ((r/f),g);
  EXPECT_EQ(h,(f/r));
}

TEST_F(RationalTest, testDivisionDouble)
{
  Rational r(4,8);
  double d1 = 0.2;
  double d2 = 2.5;
  double d3 = 0.4;
  EXPECT_EQ((r/d1),d2);
  EXPECT_EQ(d3,(d1/r));
}
