#include <iostream>

using namespace std;

int main(int argc, char** argv){

   int x = 0;

   for( x = 0; x < 10; x++ ){

       cout<< x << endl;

   }
   cin.get();

   x = 0;

   while(x<10){

      cout<< x << endl;
      x++;

   }
   cin.get();

   //no change in x this time

   do{

       cout << x << endl;
       x--;

    }while( x != 0 );
    cin.get();

return 0;
}
