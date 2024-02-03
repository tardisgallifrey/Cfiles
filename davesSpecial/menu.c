//
// Created by tardis1 on 2/3/24.
//
#include <stdio.h>


int menu(){

   int charChoice;

   printf("\n1. Add Entry");
   printf("\n2. ");
   printf("\n3. ");
   printf("\n9. Exit program");
   printf("\n\nEnter the number of your choice: ");

   scanf(" %c", &charChoice);

   return charChoice - '0';
}