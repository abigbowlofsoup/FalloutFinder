#include <iostream>
#include <string>
#include <vector>
#include "Armor.h"

Armor::Armor(std::vector<std::string> const &entity) {
   name = entity[0];
   value = std::stoi(entity[1]);
   weight = std::stoi(entity[2]);
   baseid = entity[3];
   item_hp = std::stoi(entity[4]);
   dmg_r = std::stoi(entity[5]);
}

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
      << "Damge Rating: " << dmg_r << std::endl
      << "Item HP: " << item_hp << std::endl
      << "Weight: " << weight << std::endl
      << "Value: " << value << std::endl
      << "BaseID: " << baseid << std::endl;
}