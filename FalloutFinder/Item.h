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
   virtual std::string GetName() const  = 0;
   virtual int GetWeight() const  = 0;
   virtual int GetValue() const  = 0;
   virtual std::string GetBaseId() const  = 0;
};

#endif 

