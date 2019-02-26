#ifndef ITEM_H
#define ITEM_H
#include <string>

class Item {
private:
   std::string name;
   int value;
   int weight;
   int baseid;

public:
   virtual std::string GetName() = 0;
   virtual int GetWeight() = 0;
   virtual int GetValue() = 0;
   virtual int GetBaseId() = 0;
};

#endif 

