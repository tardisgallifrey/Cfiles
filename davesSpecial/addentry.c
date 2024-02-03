//
// Created by tardis1 on 2/3/24.
//
#include <stdio.h>
#include "app.h"

void addEntry(){

   struct Record newRecord;
   char response;
   int success;

   printf("\nEnter first data item: ");
   scanf(" %s", newRecord.data1);
   printf("\nEnter second data item: ");
   scanf(" %s", newRecord.data2);

   printf("\nFirst data item is: %s", newRecord.data1);
   printf("\nSecond data item is: %s", newRecord.data2);

   printf("\nDo you want to save this record? ");
   scanf(" %c", &response);

   if(response == 'Y' || response == 'y'){
       success = saveRecord(newRecord);
       if(success){
          printf("\nRecord saved successfully.");
       }
   }else{
      printf("\nRecord not saved.");
   }
}