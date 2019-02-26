#include <iostream>
#include <string>
#include "Armor.h"

int main() {
   
   std::cout << "Welcome to Fallout Finder!" << std::endl;

   auto a = std::make_unique<Armor>("Environment Suit", 100, 5, "000c09d4" , 2, 2);

   Armor a1("YaBoi");

   std::cout << a->GetWeight() << std::endl;
   //std::cout << a1.GetDR() << std::endl;


   std::cin.get();
   
   return 0;
}