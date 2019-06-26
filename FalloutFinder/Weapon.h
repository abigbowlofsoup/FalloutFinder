#ifndef WEAPON_H
#define WEAPON_H

#include <vector>
#include <string>
#include "Item.h"

using std::string;
using std::vector;


class Weapon : public Item {
private:
   string name;
   int value;
   int weight;
   string baseid;
   int item_hp;
   int dmg_r;

public:
   // Default Constructor
   Weapon();
   // Constructor with parameters
   Weapon(string n, int v, int w, string bid, int dr, int ih)
      :name(n), value(v), weight(w), baseid(bid), item_hp(ih), dmg_r(dr) {};
   // Constructor with vector
   Weapon(const vector<string> &entity);

   string GetName() const override;
   int GetWeight() const override;
   int GetValue() const override;
   string GetBaseId() const override;

   void PrintAll() const override;
   void PrintName() const override;
};

#endif // !WEAPON_H

