#ifndef ARMOR_H
#define ARMOR_H

#include <vector>
#include <string>
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
   : name(n), value(v), weight(w), baseid(bid), item_hp(ih), dmg_r(dr)
   {}

   Armor(std::vector<std::string> const &entity);

   std::string const GetName() override;
   int const GetValue() override;
   int const GetWeight() override;
   std::string const GetBaseId() override;

   int const GetDR();
   int const GetItemHP();

   void PrintAll();

};
#endif

