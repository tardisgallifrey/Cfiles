#include <stdio.h>
#include <stdlib.h>
#include "app.h"


int main() {

   int menuChoice;

   //initialize
   if(init()){
      splashScreen();
   }else{
      printf("\nSomething didn't work right.\n");
      exit(0);
   }

   //menu
   do{
      menuChoice = menu();

      switch(menuChoice){
         case 1:
            addEntry();
            break;
         case 9:
            printf("\nProgram ending normally.");
            break;
         default:
            printf("\nIncorrect choice.  Return to Menu.");

      }
   }while(menuChoice != 9);


   return 0;
}
