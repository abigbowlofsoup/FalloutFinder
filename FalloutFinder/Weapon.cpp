#include <iostream>
#include "Weapon.h"

Weapon::Weapon()
{
   name = "Test";
   value = 1;
   weight = 20;
   baseid = "FFFFFFFF";
   item_hp = 1;
   dmg_r = 1;
}

Weapon::Weapon(const std::vector<std::string> &entity) 
{
   name = entity[0];
   value = std::stoi(entity[1]);
   weight = std::stoi(entity[2]);
   baseid = entity[3];
   item_hp = std::stoi(entity[4]);
   dmg_r = std::stoi(entity[5]);
}

string Weapon::GetName() const
{
   return name;
}

int Weapon::GetWeight() const
{
   return weight;
}

int Weapon::GetValue() const 
{
   return value;
}
string Weapon::GetBaseId() const
{
   return baseid;
}

void Weapon::PrintAll() const
{
   std::cout << "Name: " << name << std::endl
      << "Damge Rating: " << dmg_r << std::endl
      << "Item HP: " << item_hp << std::endl
      << "Weight: " << weight << std::endl
      << "Value: " << value << std::endl
      << "BaseID: " << baseid << std::endl;
}
void Weapon::PrintName() const
{
   std::cout << "Name: " << name << std::endl;
}