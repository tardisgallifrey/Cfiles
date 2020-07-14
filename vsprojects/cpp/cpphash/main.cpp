#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include "hash.h"

using namespace std;

//Main loop, where everything happens
int main( int argc, char** argv){

ifstream my_handle;
string filename;
string name;
string drink;
string person_name;
char answer;


   //size of Hash table
   int tableSize = 10;
   int myindex;

   //create myhash object
   myhash hashObj;


   //declare hash table variable and initialize to empty values
   myhash::item* hashTable=hashObj.initialize(tableSize);

   cout << "Enter CSV filename containing items to hash: ";
   cin >> filename;

   my_handle.open(filename);

   if(my_handle.is_open()){

      while(my_handle.good()){

         getline(my_handle, name, ',');

         if(name == ""){

            break;

         }else{

            getline(my_handle, drink);

            hashObj.AddItem( hashTable, name, drink );

         }
       }

   }else{

      cout << "Error: File could not be opened or doesn't exist." << endl;
      exit(1);

   }


   //call PrintTable method to print out hash table
   hashObj.PrintTable( hashTable, tableSize );

   cout << "Select an index to count: ";
   cin >> myindex;


   //actual index is one less than displayed, hence myindex - 1
   cout << hashObj.NumberItemsAtIndex( hashTable, myindex - 1 ) << endl;

while( answer != 'n'){

   //Section to search for a particular name
   cout << endl << "Enter a name you wish to search for info: ";
   cin >> person_name;

   hashObj.FindItem( hashTable, person_name );

   cout << "Do you wish to find another name's info?  ";
   cin >> answer;

}

return 0;
}




