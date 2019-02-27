#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "Armor.h"

#define container std::vector< std::vector<std::string> > 

void SkipBOM(std::ifstream &in);
container ProcessFile(std::ifstream &in, int i_type);

int main() {
   
   // Opening a .csv file for information
   std::ifstream input("../Armor.csv");
   if (!input) std::cerr << "Could not open the file!" << std::endl;

   std::cout << "Welcome to Fallout Finder!" << std::endl;

   ProcessFile(input, 0);

   /*auto a = std::make_unique<Armor>("Environment Suit", 100, 5, "000c09d4" , 2, 2);

   a->PrintAll();*/
   //std::cout << a1.GetDR() << std::endl;

   input.close();
   std::cin.get();
   
   return 0;
}

void SkipBOM(std::ifstream &in) {
   char test[3] = { 0 };
   in.read(test, 3);
   if ((unsigned char)test[0] == 0xEF &&
      (unsigned char)test[1] == 0xBB &&
      (unsigned char)test[2] == 0xBF)
   {
      return;
   }
   in.seekg(0);
}


// 0 = Armor, 1 = Weapon
container ProcessFile(std::ifstream &in, int i_type) {
   SkipBOM(in);
   container v_obj;
   // Standard variables in every Item
   std::string _name, _value, _weight, _baseid, _itemhp;
      
   while (!in.eof()) {
      std::vector<std::string> v_row;

      // Add all items to our 1d vector v_row for later
      std::getline(in, _name, ',');
      v_row.push_back(_name);
      std::getline(in, _value, ',');
      v_row.push_back(_value);
      std::getline(in, _weight, ',');
      v_row.push_back(_weight);
      std::getline(in, _baseid, ',');
      v_row.push_back(_baseid);
      std::getline(in, _itemhp, ',');
      v_row.push_back(_itemhp);
      
      // If it is armor we add the damage rating variable
      if(i_type == 0){ 
         std::string _dmg_r;
         std::getline(in, _dmg_r, '\n'); 
         v_row.push_back(_dmg_r);
      }

      // If it is a weapon we add multiple variables
      if (i_type == 1) {
         std::string _dmg_att;
         std::getline(in, _dmg_att, ',');
         std::string _dmg_proj;
         std::getline(in, _dmg_proj, ',');
         std::string _att_sec;
         std::getline(in, _att_sec, ',');
         std::string _crit_dmg;
         std::getline(in, _crit_dmg, '\n');
      }
      
      // Push vector in our 2d vector
      v_obj.push_back(v_row);

   }

   for(int r = 0; r < v_obj.size(); ++r){
      std::cout << "----------------" << std::endl;
      for (int c = 0; c < v_obj[r].size(); ++c) {
         std::cout << v_obj[r][c] << std::endl;
      }
   }

   return v_obj;
}