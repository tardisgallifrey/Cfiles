#include "message.h"		//look for message.h in this folder
#include <cstdlib>

using namespace std;		//So we don't have to prepend std::

int main()
{


   message m;			//declare a variable of type message
   m.printMessage();		//Use printMessage method to print m's message

   return 0;

}
