#ifndef ARMOR_H
#define ARMOR_H

#include "Item.h"


class Armor : public Item {
private:
   std::string name;
   int value;
   int weight;
   std::string baseid;
   int dmg_r;
   int item_hp;

public:
   Armor(std::string n, int v, int w, std::string bid, int dr, int ih)
   : name(n), value(v), weight(w), baseid(bid), dmg_r(dr), item_hp(ih)
   {}

   Armor(std::string n) 
   : name(n), value(0), weight(0), baseid(""), dmg_r(0), item_hp(0)
   {}

   std::string const GetName() override;
   int const GetValue() override;
   int const GetWeight() override;
   std::string const GetBaseId() override;

   int const GetDR();
   int const GetItemHP();

};
#endif

