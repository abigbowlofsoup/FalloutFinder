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

   Armor(const std::vector<std::string> &entity);

   std::string GetName() const override;
   int GetValue() const override;
   int GetWeight() const override;
   std::string GetBaseId() const override;

   int GetDR() const;
   int GetItemHP() const;

   void PrintAll();
   void PrintName();

   bool operator>(const Armor& other);
};
#endif

