#include "testFactorUtil.h"

FactorUtilTest::FactorUtilTest()
{}

FactorUtilTest::~FactorUtilTest()
{}

void FactorUtilTest::SetUp()
{}

void FactorUtilTest::TearDown()
{}

TEST_F(FactorUtilTest, testIsPrimeInteger)
{
  EXPECT_TRUE(FactorUtil::isPrimeInteger(7));
  EXPECT_TRUE(FactorUtil::isPrimeInteger(53));
  EXPECT_TRUE(FactorUtil::isPrimeInteger(107));
  EXPECT_TRUE(FactorUtil::isPrimeInteger(127));
  EXPECT_TRUE(FactorUtil::isPrimeInteger(149));
  EXPECT_TRUE(FactorUtil::isPrimeInteger(181));
  EXPECT_TRUE(FactorUtil::isPrimeInteger(199));
  EXPECT_TRUE(FactorUtil::isPrimeInteger(2147483647));

  EXPECT_FALSE(FactorUtil::isPrimeInteger(4));
  EXPECT_FALSE(FactorUtil::isPrimeInteger(18));
  EXPECT_FALSE(FactorUtil::isPrimeInteger(100));
  EXPECT_FALSE(FactorUtil::isPrimeInteger(248));
  EXPECT_FALSE(FactorUtil::isPrimeInteger(584));
  EXPECT_FALSE(FactorUtil::isPrimeInteger(2147483646));
}

TEST_F(FactorUtilTest, testGetProductFromFactors)
{
  std::map<int,int> factors;
  factors[2]  = 3;
  factors[7]  = 2;
  factors[11] = 1;
  EXPECT_EQ(FactorUtil::getProductFromFactors(factors), 4312);
}

TEST_F(FactorUtilTest, testGetPrimeFactorization)
{
  std::map<int,int> primeFac = FactorUtil::getPrimeFactorization(243);
  EXPECT_EQ(primeFac.size(), 1);
  EXPECT_EQ(primeFac[3], 5);

  std::map<int,int> negPrimeFac = FactorUtil::getPrimeFactorization(-243);
  EXPECT_EQ(negPrimeFac.size(), 2);
  EXPECT_EQ(negPrimeFac[3], 5);
  EXPECT_EQ(negPrimeFac[-1], 1);
}

TEST_F(FactorUtilTest, testIsIntegerPairCoprime)
{
  EXPECT_TRUE(FactorUtil::isIntegerPairCoprime(2, 3));
  EXPECT_TRUE(FactorUtil::isIntegerPairCoprime(15, 98));
  EXPECT_TRUE(FactorUtil::isIntegerPairCoprime(1296, 1500625));

  EXPECT_FALSE(FactorUtil::isIntegerPairCoprime(1216, 2565));
  EXPECT_FALSE(FactorUtil::isIntegerPairCoprime(5831, 2873));
  EXPECT_FALSE(FactorUtil::isIntegerPairCoprime(116, 725));
}

TEST_F(FactorUtilTest, testAreIntegersCoprime)
{
  std::vector<int> integers;
  integers.push_back(4);
  integers.push_back(9);
  integers.push_back(25);
  integers.push_back(49);
  integers.push_back(121);
  EXPECT_TRUE(FactorUtil::areIntegersCoprime(integers));

  integers.push_back(75);
  EXPECT_FALSE(FactorUtil::areIntegersCoprime(integers));
}

TEST_F(FactorUtilTest, testGetGcfOfIntegerPair)
{
  EXPECT_EQ(FactorUtil::getGcfOfIntegerPair(100, 275), 25);
  EXPECT_EQ(FactorUtil::getGcfOfIntegerPair(162, 300), 6);
  EXPECT_EQ(FactorUtil::getGcfOfIntegerPair(1073741824, 774840978), 2);
}

TEST_F(FactorUtilTest, testGetGcfOfIntegers)
{
  std::vector<int> integers;
  integers.push_back(36);
  integers.push_back(81);
  integers.push_back(72);
  integers.push_back(27);
  integers.push_back(54);
  EXPECT_EQ(FactorUtil::getGcfOfIntegers(integers), 9);
}

TEST_F(FactorUtilTest, testGetLcmOfIntegerPair)
{
  EXPECT_EQ(FactorUtil::getLcmOfIntegerPair(36, 27), 108);
}

TEST_F(FactorUtilTest, testGetLcmOfIntegers)
{
  std::vector<int> integers;
  integers.push_back(4);
  integers.push_back(5);
  integers.push_back(50);
  integers.push_back(25);
  integers.push_back(10);
  EXPECT_EQ(FactorUtil::getLcmOfIntegers(integers), 100);
}
