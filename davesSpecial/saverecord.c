//
// Created by tardis1 on 2/3/24.
//

#include <stdio.h>
#include <stdlib.h>
#include "app.h"

int saveRecord(struct Record saveRecord){
   FILE* infile;
   FILE* outfile;
   struct Record tempRecord;
   unsigned long flag = 0;
   int idEmpty;

   // open file for writing
   infile = fopen("person.bin", "rb");

   //open file and read first record
   if (infile == NULL) {
      fprintf(stderr, "\nError opened file\n");
      exit(1);
   }else{
      flag = fread(&tempRecord, sizeof(struct Record), 1, infile);
      idEmpty = tempRecord.id;
      fclose(infile);
   }

   //file has id == 0, open for write and save first record
   if(flag && idEmpty == 0){
      outfile = fopen("person.bin", "wb");
      if(outfile == NULL){
         fprintf(stderr, "\nError opened file\n");
         exit(1);
      }else{
         flag = fwrite(&saveRecord, sizeof(struct Record), 1, outfile);
         fclose(infile);
      }
   }

   //file does not have id == 0, open for append
   if(flag && idEmpty){
      outfile = fopen("person.bin", "ab");
      if(outfile == NULL){
         fprintf(stderr, "\nError opened file\n");
         exit(1);
      }else{
         flag = fwrite(&saveRecord, sizeof(struct Record), 1, outfile);
         fclose(infile);
      }
   }

   return (int) flag;

}
