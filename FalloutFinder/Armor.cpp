#include <iostream>
#include <string>
#include <vector>
#include "Armor.h"

Armor::Armor(const std::vector<std::string> &entity) 
{
   name = entity[0];
   value = std::stoi(entity[1]);
   weight = std::stoi(entity[2]);
   baseid = entity[3];
   item_hp = std::stoi(entity[4]);
   dmg_r = std::stoi(entity[5]);
}

string Armor::GetName() const
{
   return name;
}

int Armor::GetValue() const 
{
   return value;
}

int Armor::GetWeight() const 
{
   return weight;
}

string Armor::GetBaseId() const 
{
   return baseid;
}

void Armor::PrintAll() const {
   std::cout << "Name: " << name << std::endl
      << "Damge Rating: " << dmg_r << std::endl
      << "Item HP: " << item_hp << std::endl
      << "Weight: " << weight << std::endl
      << "Value: " << value << std::endl
      << "BaseID: " << baseid << std::endl;
}

void Armor::PrintName() const 
{
   std::cout << "Name: " << name << std::endl;
}

int Armor::GetDR() const 
{
   return dmg_r;
}

int Armor::GetItemHP() const
{
   return item_hp;
}

bool Armor::operator>(const Armor& other) 
{
   for (int i = 0; i < name.size(); ++i) 
   {
      if (name[i] > other.name[i]) 
      {
         return true;
      }
      else if (name[i] < other.name[i]) 
      {
         return false;
      }
   }
   return false;
}