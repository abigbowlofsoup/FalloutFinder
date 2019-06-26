#ifndef ARMOR_H
#define ARMOR_H

#include <vector>
#include <string>
#include "Item.h"

using std::string;
using std::vector;

class Armor : public Item {
private:
   string name;
   int value;
   int weight;
   string baseid;
   int item_hp;
   int dmg_r;

public:
   Armor(string n, int v, int w, string bid, int dr, int ih)
   :name(n), value(v), weight(w), baseid(bid), item_hp(ih), dmg_r(dr)
   {}

   Armor(const vector<string> &entity);

   string GetName() const override;
   int GetValue() const override;
   int GetWeight() const override;
   string GetBaseId() const override;
   void PrintAll() const override;
   void PrintName() const override;

   int GetDR() const;
   int GetItemHP() const;

  

   bool operator>(const Armor& other);
};
#endif

