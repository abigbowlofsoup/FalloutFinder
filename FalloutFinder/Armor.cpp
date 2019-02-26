#include <iostream>
#include <string>
#include "Armor.h"

std::string Armor::GetName() {
   return name;
}

int Armor::GetValue() {
   return value;
}

int Armor::GetWeight() {
   return weight;
}

int Armor::GetBaseId() {
   return baseid;
}