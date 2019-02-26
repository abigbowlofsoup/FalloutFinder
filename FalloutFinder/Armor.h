#ifndef ARMOR_H
#define ARMOR_H

#include "Item.h"


class Armor : public Item {
private:
   std::string name;
   int value;
   int weight;
   int baseid;

public:
   Armor(std::string _name, int _value, int _weight, int _baseid) {
      name = _name;
      value = _value;
      weight = _weight;
      baseid = _baseid;
   }

   std::string GetName() override;
   int GetValue() override;
   int GetWeight() override;
   int GetBaseId() override;

};


#endif

