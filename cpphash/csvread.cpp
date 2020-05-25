#include <iostream>
#include <fstream>

int main(){

std::ifstream my_handle;
std::string name;
std::string drink;

my_handle.open("drinks.csv");

while(my_handle.good()){

   getline(my_handle, name, ',');

   if(name == ""){

      exit(0);

   }else{

      getline(my_handle, drink);

      std::cout << name << ", " << drink << std::endl;

   }

}

my_handle.close();


return 0;
}
