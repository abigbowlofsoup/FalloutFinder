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