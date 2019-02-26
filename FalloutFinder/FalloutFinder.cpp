#include <iostream>
#include <string>
#include "Armor.h"

int main() {
   
   std::cout << "Welcome to Fallout Finder!" << std::endl;

   Armor a("Hello", 2, 2, 2);

   std::cout << a.GetName() << std::endl;

   std::cin.get();
   
   return 0;
}