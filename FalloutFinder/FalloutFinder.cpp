#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <memory>
#include "Armor.h"
#include "Weapon.h"

using std::vector;
using std::string;
using std::cout;
using std::endl;


#define container vector< vector<string> > 

//----Predefined Function----
void SkipBOM(std::ifstream &in);
container ProcessFile(std::ifstream &in, int i_type);

void UpdateArmorVec(std::unique_ptr<vector<Armor>>& v_output, container const &v_input);
void SortArray(std::unique_ptr<vector<Armor>>& v_output);
vector<Armor> FindItem(std::unique_ptr<vector<Armor>> const &v_output, string searchItem);

int main(int argc, char** argv[]) {

   vector<Weapon> weaponArr;
   vector<Armor>  armorArr;
      
   //-----------------File I/O-----------------
   // Opening a .csv file for information
   std::ifstream input("../Armor.csv");
   if (!input) 
   {
      std::cerr << "Could not open the file!" << endl;
      return 0;
   }

   // Creates a 2d vector pointer, processes the file 
   // and adds the sorted items into our vector
   // TODO: figure out what item is going to be created for the pointer
   auto v_items = std::make_unique<vector<Armor>>();
   container processed = ProcessFile(input, 0);
   UpdateArmorVec(v_items, processed);
   
   cout << endl;

   //-----------------I/O-----------------
   cout << "Welcome to Fallout Finder!" << endl;
      
   
   // From StackOverflow
   for (;;) 
   {
      cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
      cout << "[P]rint All Items, [F]ind Item, [E]xit Program\n" << ">";
      string line;
      std::getline(std::cin, line);
      
      if (line.empty()) { continue; }

      if (line.at(0) == 'F' || line.at(0) == 'f') 
      {
         string findEntry;
         cout << "Enter name of item: ";
         getline(std::cin, findEntry);
         vector<Armor> test = FindItem(v_items, findEntry);

         if (test.size() == 0) 
         {
            cout << "Not a valid item name...returning to main menu..." << endl;
            continue;
         }

         if (test.size() != 1) 
         {
            cout << "Which item would you like?" << endl << "-------------" << endl;
            for (int i = 0; i < test.size(); ++i) cout << test[i].GetName() << endl;

            cout << ">";
            getline(std::cin, findEntry);

            test = FindItem(v_items, findEntry);

            if (test.size() != 1) 
            {
               cout << "Unable to find item...returning to main menu..." << endl;
               continue;
            }
         }

         test.at(0).PrintAll();
         continue; 
      }

      if (line.at(0) == 'P' || line.at(0) == 'p') 
      {
         for (int i = 0; i < (*v_items).size(); ++i) 
         {
            (*v_items)[i].PrintName();
            cout << "---------------" << endl;
         }
         continue;
      }

      if (line[0] == 'E' || line[0] == 'e') { break; }

      cout << "Sorry, not a command." << endl;
   }

   cout << "Goodbye!\n";

   input.close();
   
   return 0;
}

// From StackOverflow
void SkipBOM(std::ifstream &in) 
{
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
container ProcessFile(std::ifstream &in, int i_type) 
{
   SkipBOM(in);
   container v_obj;
   // Standard variables in every Item
   string _name, _value, _weight, _baseid, _itemhp;

   // Get rid of column names in csv
   string dummy;
   std::getline(in, dummy);

   while (!in.eof()) 
   {
      vector<string> v_row;

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
      if(i_type == 0)
      { 
         string _dmg_r;
         std::getline(in, _dmg_r, '\n'); 
         v_row.push_back(_dmg_r);
      }

      // If it is a weapon we add multiple variables
      if (i_type == 1) 
      {
         string _dmg_att;
         std::getline(in, _dmg_att, ',');
         string _dmg_proj;
         std::getline(in, _dmg_proj, ',');
         string _att_sec;
         std::getline(in, _att_sec, ',');
         string _crit_dmg;
         std::getline(in, _crit_dmg, '\n');
      }
      
      // Push vector in our 2d vector
      v_obj.push_back(v_row);

   }

   cout << "Items Processed!" << endl;
   return v_obj;
}

// Adds our items to the Armor vector
void UpdateArmorVec(std::unique_ptr<vector<Armor>>& v_output, container const &v_input) 
{
   for (int r = 0; r < v_input.size(); ++r) 
   {
      // Create Armor instances out of 2d vector
      // and push it into vector
      Armor var(v_input[r]);
      v_output->push_back(var);
   }
   // Sort the array
   SortArray(v_output);
}

// Insertion Sort
void SortArray(std::unique_ptr<vector<Armor>>& v_array) 
{
   int i = 1;

   while (i < (*v_array).size()) 
   {
      Armor x = (*v_array)[i];
      int j = i - 1;
      while (j >= 0 && (*v_array)[j] > x) 
      {
         (*v_array)[j + 1] = (*v_array)[j];
         j = j - 1;
      }
      (*v_array)[j + 1] = x;
      ++i;
   }

   cout << "Items Sorted!" << endl;
}

vector<Armor> FindItem(std::unique_ptr<vector<Armor>> const &v_output, string searchItem) 
{
   vector<Armor> foundItems;

   for (int i = 0; i < (*v_output).size(); ++i) 
   {
      string item = (*v_output)[i].GetName();
      if (item.find(searchItem) == string::npos) 
      {
         continue;
      }

      foundItems.push_back((*v_output)[i]);
   }
   
   return foundItems;
}