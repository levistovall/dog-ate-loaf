#include <iostream>
#include <string.h>
#include <sstream>
#include "PrimeAssistant.h"
#include "Rational.h"
#include "division_by_zero_exception.h"

int main(int argc, char *argv[])
{
   /*std::vector<int> *v = new std::vector<int>;
   v->push_back(24);
   v->push_back(36);
   v->push_back(54);
   v->push_back(81);
   int gcfMulti = PrimeAssistant::getGcfOfIntegers(*v);
   int lcmMulti = PrimeAssistant::getLcmOfIntegers(*v);
   std::stringstream ss;
   ss << "The gcf of {";
   std::vector<int>::iterator it;
   for(it = v->begin(); it != v->end(); it++)
   {
      ss << " " << *it << " ";
   }
   ss << "} is " << gcfMulti << std::endl;
   std::cout << ss.str();
   ss << "The lcm of {";
   for(it = v->begin(); it != v->end(); it++)
   {
      ss << " " << *it << " ";
   }
   ss << "} is " << lcmMulti << std::endl;
   std::cout << ss.str();

   int a = 96;
   int b = 120;
   int gcf = PrimeAssistant::getGcfOfIntegerPair(a, b);
   int lcm = PrimeAssistant::getLcmOfIntegerPair(a, b);
   std::cout << "The GCF of " << a << " and " << b << " is " << gcf << std::endl;
   std::cout << "The LCM of " << a << " and " << b << " is " << lcm << std::endl;
*/
   Rational r(48, 36);
   Rational s(40, 100);
   s -= r;
   std::cout << "Here's a couple of rationals: " << r.toString() << ", " << s.toString() << std::endl;
   std::cout << " now as double: " << r.toDouble() << ", " << s.toDouble() << std::endl;
   std::cout << " now as float: " << r.toFloat() << ", " << s.toFloat() << std::endl;
   std::cout << " now as int: " << r.toInteger() << ", " << s.toInteger() << std::endl;
   std::cout << " and the sum: " << (r+s).toString() << std::endl;
   std::cout << " and the sum: " << (r+1).toString() << std::endl;
   //delete r;
//   try
//   {
      Rational *q = new Rational(48, 0);
//   }
//   catch(division_by_zero_exception& e)
//   {
//      std::cout << e.what() << std::endl;
//   }

   bool keepGoing = true;
   int n;
   PrimeAssistant pa;
   while(keepGoing)
   {
      std::cout << "Enter an integer: " << std::endl;
      std::cin >> n;
      std::cout << n << " is";
      if(!(pa.isPrimeInteger(n)))
         std::cout << " not";
      std::cout << " a prime integer." << std::endl;
      pa.getPrimeFactorization(n);
      std::string keepGoingString;
      std::cout << "Do you want to keep going? [y/n]" << std::endl;
      std::cin >> keepGoingString;
      if(keepGoingString != "y")
      {
         keepGoing = false;    
      }
   }
   return 0;
}
