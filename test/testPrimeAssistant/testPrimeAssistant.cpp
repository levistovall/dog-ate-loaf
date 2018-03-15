#include "testPrimeAssistant.h"

PrimeAssistantTest::PrimeAssistantTest()
{}

PrimeAssistantTest::~PrimeAssistantTest()
{}

void PrimeAssistantTest::SetUp()
{}

void PrimeAssistantTest::TearDown()
{}

TEST_F(PrimeAssistantTest, testIsPrimeInteger)
{
  EXPECT_TRUE(PrimeAssistant::isPrimeInteger(7));
  EXPECT_TRUE(PrimeAssistant::isPrimeInteger(53));
  EXPECT_TRUE(PrimeAssistant::isPrimeInteger(107));
  EXPECT_TRUE(PrimeAssistant::isPrimeInteger(127));
  EXPECT_TRUE(PrimeAssistant::isPrimeInteger(149));
  EXPECT_TRUE(PrimeAssistant::isPrimeInteger(181));
  EXPECT_TRUE(PrimeAssistant::isPrimeInteger(199));
  EXPECT_TRUE(PrimeAssistant::isPrimeInteger(2147483647));

  EXPECT_FALSE(PrimeAssistant::isPrimeInteger(4));
  EXPECT_FALSE(PrimeAssistant::isPrimeInteger(18));
  EXPECT_FALSE(PrimeAssistant::isPrimeInteger(100));
  EXPECT_FALSE(PrimeAssistant::isPrimeInteger(248));
  EXPECT_FALSE(PrimeAssistant::isPrimeInteger(584));
  EXPECT_FALSE(PrimeAssistant::isPrimeInteger(2147483648));
}

TEST_F(PrimeAssistantTest, testGetProductFromFactors)
{
  std::map<int,int> factors;
  factors[2]  = 3;
  factors[7]  = 2;
  factors[11] = 1;
  EXPECT_EQ(PrimeAssistant::getProductFromFactors(factors), 4312);
}

TEST_F(PrimeAssistantTest, testGetPrimeFactorization)
{
  std::map<int,int> primeFac = PrimeAssistant::getPrimeFactorization(243);
  EXPECT_EQ(primeFac.size(), 1);
  EXPECT_EQ(primeFac[3], 5);

  std::map<int,int> negPrimeFac = PrimeAssistant::getPrimeFactorization(-243);
  EXPECT_EQ(negPrimeFac.size(), 2);
  EXPECT_EQ(negPrimeFac[3], 5);
  EXPECT_EQ(negPrimeFac[-1], 1);
}

TEST_F(PrimeAssistantTest, testAddPrimeFacs)
{
  int a = 480200;
  std::map<int,int> factorsOfA = PrimeAssistant::getPrimeFactorization(a);

  int b = 810;
  std::map<int,int> factorsOfB = PrimeAssistant::getPrimeFactorization(b);

  int c = 480200 * 810;
  std::map<int,int> factorsOfC = PrimeAssistant::getPrimeFactorization(c);

  std::map<int,int> factorsOfAandB = PrimeAssistant::addPrimeFacs(factorsOfA,
                                                                  factorsOfB);

  std::map<int,int>::iterator it;
  for(it = factorsOfC.begin(); it != factorsOfC.end(); it++)
  {
    EXPECT_EQ(it->second, factorsOfAandB[it->first]);
  }
  EXPECT_EQ(factorsOfC.size(), factorsOfAandB.size());
  EXPECT_EQ(480200 * 810, PrimeAssistant::getProductFromFactors(factorsOfAandB));
}

TEST_F(PrimeAssistantTest, testSubtractPrimeFacs)
{
  int a = 10000;
  std::map<int,int> factorsOfA = PrimeAssistant::getPrimeFactorization(a);

  int b = 25;
  std::map<int,int> factorsOfB = PrimeAssistant::getPrimeFactorization(b);

  int c = 400;
  std::map<int,int> factorsOfC = PrimeAssistant::getPrimeFactorization(c);

  std::map<int,int> factorsOfAminusFactorsOfB =
      PrimeAssistant::subtractPrimeFacs(factorsOfA, factorsOfB);

  std::map<int,int>::iterator it;
  for(it = factorsOfC.begin(); it != factorsOfC.end(); it++)
  {
    EXPECT_EQ(it->second, factorsOfAminusFactorsOfB[it->first]);
  }
  EXPECT_EQ(factorsOfC.size(), factorsOfAminusFactorsOfB.size());
  EXPECT_EQ(400, PrimeAssistant::getProductFromFactors(factorsOfAminusFactorsOfB));
}

TEST_F(PrimeAssistantTest, testIsIntegerPairCoprime)
{
  EXPECT_TRUE(PrimeAssistant::isIntegerPairCoprime(2, 3));
  EXPECT_TRUE(PrimeAssistant::isIntegerPairCoprime(15, 98));
  EXPECT_TRUE(PrimeAssistant::isIntegerPairCoprime(1296, 1500625));

  EXPECT_FALSE(PrimeAssistant::isIntegerPairCoprime(1216, 2565));
  EXPECT_FALSE(PrimeAssistant::isIntegerPairCoprime(5831, 2873));
  EXPECT_FALSE(PrimeAssistant::isIntegerPairCoprime(116, 725));
}

TEST_F(PrimeAssistantTest, testAreIntegersCoprime)
{
  std::vector<int> integers;
  integers.push_back(4);
  integers.push_back(9);
  integers.push_back(25);
  integers.push_back(49);
  integers.push_back(121);
  EXPECT_TRUE(PrimeAssistant::areIntegersCoprime(integers));

  integers.push_back(75);
  EXPECT_FALSE(PrimeAssistant::areIntegersCoprime(integers));
}

TEST_F(PrimeAssistantTest, testGetGcfOfIntegerPair)
{
  EXPECT_EQ(PrimeAssistant::getGcfOfIntegerPair(100, 275), 25);
  EXPECT_EQ(PrimeAssistant::getGcfOfIntegerPair(162, 300), 6);
}

TEST_F(PrimeAssistantTest, testGetGcfOfIntegers)
{
  std::vector<int> integers;
  integers.push_back(36);
  integers.push_back(81);
  integers.push_back(72);
  integers.push_back(27);
  integers.push_back(54);
  EXPECT_EQ(PrimeAssistant::getGcfOfIntegers(integers), 9);
}

TEST_F(PrimeAssistantTest, testGetLcmOfIntegerPair)
{
  EXPECT_EQ(PrimeAssistant::getLcmOfIntegerPair(36, 27), 108);
}

TEST_F(PrimeAssistantTest, testGetLcmOfIntegers)
{
  std::vector<int> integers;
  integers.push_back(4);
  integers.push_back(5);
  integers.push_back(50);
  integers.push_back(25);
  integers.push_back(10);
  EXPECT_EQ(PrimeAssistant::getLcmOfIntegers(integers), 100);
}
