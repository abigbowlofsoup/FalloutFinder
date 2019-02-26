#ifndef ITEM_H
#define ITEM_H
#include <string>

class Item {
private:
   std::string name;
   int value;
   int weight;
   std::string baseid;

public:
   virtual std::string const GetName() = 0;
   virtual int const GetWeight() = 0;
   virtual int const GetValue() = 0;
   virtual std::string const GetBaseId() = 0;
};

#endif 

