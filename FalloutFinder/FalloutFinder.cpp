#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Armor.h"

#define container std::vector< std::vector<std::string> > 

void SkipBOM(std::ifstream &in);
container ProcessFile(std::ifstream &in, int i_type);

void UpdateArmorVec(std::vector<Armor> &v_output, container const &v_input);

int main() {
   
   //-----------------File I/O-----------------
   // Opening a .csv file for information
   std::ifstream input("../Armor.csv");
   if (!input) {
      std::cerr << "Could not open the file!" << std::endl;
      return 0;
   }

   // Creates a 2d vector of info from our file
   // and creates an Armor vector with our items
   container processed = ProcessFile(input, 0);
   std::vector<Armor> v_armor;
   UpdateArmorVec(v_armor, processed);

   //-----------------I/O-----------------
   std::cout << "Welcome to Fallout Finder!\n"
      << "--------------------------" << std::endl << ">";
   
   // From StackOverflow
   for (std::string line; std::getline(std::cin, line); ) {
      
      if (line.empty()) { continue; }


      if (line == "A" || line == "a") { 
         continue; 
      }

      if (line == "R" || line == "r") {
         continue;
      }

      if (line[0] == 'E' || line[0] == 'e') { break; }

      std::cout << "Sorry, I did not understand.\n>";
   }

   std::cout << "Goodbye!\n";
   

   

   /*for (int i = 0; i < v_armor.size(); ++i) {
      v_armor[i].PrintAll();
      std::cout << "---------------" << std::endl;
   }*/

   input.close();
   std::cin.get();
   
   return 0;
}

// From StackOverflow
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

   // Get rid of column names in csv
   std::string dummy;
   std::getline(in, dummy);

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
   return v_obj;
}

// Adds our items to the Armor vector
void UpdateArmorVec(std::vector<Armor> &v_output, container const &v_input) {
   for (int r = 0; r < v_input.size(); ++r) {
      // Create Armor instances out of 2d vector
      // and push it into vector
      Armor var(v_input[r]);
      v_output.push_back(var);
   }
}