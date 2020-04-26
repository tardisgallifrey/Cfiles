#include <cstdlib>
#include <iostream>
#include <string>
#include "hash.h"

using namespace std;

//Main loop, where everything happens
int main( int argc, char** argv){

   //size of Hash table
   int tableSize = 10;

   //create myhash object
   myhash hashObj;


   //declare hash table variable and initialize to empty values
   myhash::item* hashTable=hashObj.initialize(tableSize);

   //cout << "Your index is: " << hashObj.Hash_index(argv[1]) << endl;

   hashObj.AddItem( hashTable, "Dave", "Coke Zero" );

   hashObj.AddItem( hashTable, "Janice", "Dr Pepper");

   //call PrintTable method to print out hash table
   hashObj.PrintTable( hashTable, tableSize );


return 0;
}




