#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "chash.h"


//Declare initialize function prototype
struct item* initialize(int size);


//Hash Indexing function
int Hash_index( char* key );


//Declare table printing function prototype
void PrintTable(struct item* hTable, int size);

//Main loop, where everything happens
int main( int argc, char* argv[]){

int index, tableSize = 10;

   //declare hash table variable and initialize to empty values
   struct item* HashTable=initialize(tableSize);

   index = Hash_index("Dave");

   printf("Your index is: %d\n", index);

   PrintTable(HashTable, tableSize);

return 0;
}


//table printing function
void PrintTable(struct item* hTable, int size){

   for(int y=0; y < size; y++){

      printf("----------------------------\n");
      printf("Name @ record %d: %s\n", y + 1, hTable[y].name);
      printf("Drink @ record %d: %s\n", y + 1, hTable[y].drink);
      printf("----------------------------\n");
      }

}


//Initialize function
struct item* initialize(int size){

	//declare a pointer to an array of structs of type item
	struct item *hTable = (struct item*)malloc(size * sizeof(struct item));

	//initialize Hashtable
	for(int x=0; x < size; x++){

    		hTable[x].name = "empty";
    		hTable[x].drink = "empty";
    		hTable[x].next = NULL;

	}
	return hTable;
}

//Hash index function
int Hash_index( char* key ){

int sum = 0, index = 0;

   for( int i = 0; i < strlen(key); i++){

      sum = sum + (int)key[i];

   }

   //The division by 10 is temporary until
   //I get finished and ready to go to tableSize 100
   index = ( sum % 100 ) / 10;

return index;
}
