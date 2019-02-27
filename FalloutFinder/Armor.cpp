#include <iostream>
#include <string>
#include "Armor.h"

std::string const Armor::GetName() {
   return name;
}

int const Armor::GetValue() {
   return value;
}

int const Armor::GetWeight() {
   return weight;
}

std::string const Armor::GetBaseId() {
   return baseid;
}

int const Armor::GetDR() {
   return dmg_r;
}

int const Armor::GetItemHP() {
   return item_hp;
}

void Armor::PrintAll() {
   std::cout << "Name: " << name << std::endl
      << "Value: " << value << std::endl
      << "Weight: " << weight << std::endl
      << "BaseID: " << baseid << std::endl 
      << "Damge Rating: " << dmg_r << std::endl 
      << "Item HP: " << item_hp << std::endl;
}