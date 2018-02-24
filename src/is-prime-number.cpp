#include <iostream>
#include <string.h>
#include "PrimeAssistant.h"

int main(int argc, char *argv[])
{
   /*std::vector<int> *a = new std::vector<int>;
   a->push_back(2);
   a->push_back(3);
   a->push_back(5);
   a->push_back(13);
   a->push_back(53);
   a->push_back(6);
   bool coprime = PrimeAssistant::areIntegersCoprime(*a);*/

   int a = 96;
   int b = 120;
   int gcf = PrimeAssistant::getGreatestCommonFactor(a, b);
   std::cout << "The GCF of " << a << " and " << b << " is " << gcf << std::endl;

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
