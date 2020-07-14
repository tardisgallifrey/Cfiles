/*
 *
 *
 * File: hash.cpp
 *
 * Author: Dave Vest
 *
 * Created: April 14, 2020
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include "hash.h"


//Initialize function
myhash::item* myhash::initialize(int size){

        //declare a pointer to an array of structs of type item
        item *hTable = (item*)malloc(size * sizeof(item));

        //initialize Hashtable
        for(int x=0; x < size; x++){

                hTable[x].name = "empty";
                hTable[x].drink = "empty";
                hTable[x].next = NULL;

        }
        return hTable;


}

//Hash Index function
int myhash::Hash_index( std::string key ){

int sum = 0, index = 0;

   for( int i = 0; i < key.length(); i++){

      sum = sum + (int)key[i];

   }

   //The division by 10 is temporary until
   //I get finished and ready to go to tableSize 100
   index = ( sum % 100 ) / 10;

return index;
}


//Print Table function
void myhash::PrintTable( myhash::item* hTable, int size ){

   for(int y=0; y < size; y++){

      std::cout<<"----------------------------\n";
      std::cout<< "Name @ record "<< y + 1 << ":" << hTable[y].name << std::endl;
      std::cout<< "Drink @ record "<< y + 1 << ":" << hTable[y].drink << std::endl;
      std::cout<< "Next " << hTable[y].next << std::endl;
      std::cout<<"----------------------------\n";
      }



}



//Add item into table function
void myhash::AddItem( myhash::item* hTable, std::string name, std::string drink ){

int index=myhash::Hash_index(name);


     if( hTable[index].name == "empty" ){

        hTable[index].name = name;
        hTable[index].drink = drink;

     }else{

        myhash::item* Ptr = &hTable[index];
        myhash::item* n = new myhash::item;
        n->name = name;
        n->drink = drink;
        n->next = NULL;

        //now get Ptr to boint to end of hTable[index]
        while( Ptr->next != NULL){

            Ptr = Ptr->next;

       }

       // Now, point the end to the new item n
       Ptr->next = n;

     }

}


//Number of Items at a requested index into the Table
int myhash::NumberItemsAtIndex(myhash::item* hTable, int index){

   int count = 0;

   if(hTable[index].name == "empty"){

     return count;

   }else{

      count++;
      myhash::item* Ptr = &hTable[index];
      while(Ptr->next != NULL){

         count++;
         Ptr = Ptr->next;

      }

   }
   return count;


}



//Find an item in the hash table
void myhash::FindItem(myhash::item* hTable, std::string name){

int index;

index = myhash::Hash_index(name);
bool foundName = false;
std::string itemfound;

myhash::item* Ptr = &hTable[index];

while(Ptr != NULL){

   if(Ptr->name == name){

      foundName = true;
      itemfound = Ptr->drink;

   }
   Ptr = Ptr->next;
}

if(foundName == true){

   std::cout << "Favorite drink of " << name << " is: " << itemfound << "." << std::endl;

}else{

   std::cout << std::endl << name << "'s info was not found in the Hash Table." << std::endl;
}

}
