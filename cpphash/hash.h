/*
 *
 *
 * File: hash.h
 *
 * Author: Dave Vest
 *
 * Created: April 12, 2020
 */

#include <cstdlib>
#include <iostream>
#include <string>


#ifndef HASH_H
#define HASH_H

class myhash {

public:

	struct item {

                std::string name;
                std::string drink;
                item *next;

        }; //item prototype

item* initialize(int size);

int Hash_index( std::string key );

void AddItem( item* hTable, std::string name, std::string drink );

void PrintTable( item* hTable, int size );

};



#endif /* HASH_H */
