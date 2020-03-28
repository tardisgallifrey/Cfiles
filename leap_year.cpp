#include <iostream>

int main() {
  
  int year;
  
  std::cout<<"Enter a year: ";
  std::cin>>year;
  
  if(year > 999){
    if(year % 100 > 0){
      if(year % 400 == 0){
          if(year % 4 == 0){
            std::cout<<"Yes, this is a leap year.\n";
          }
    }else{
      std::cout<<"this is not a leap year.\n";
    }   
   }
  }
}
