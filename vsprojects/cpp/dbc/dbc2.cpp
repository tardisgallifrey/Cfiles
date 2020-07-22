#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;


//Keep this number from string checker
bool isNumeric(string str) 
{
   for (int i = 0; i < str.length(); i++)
   {
      if( str[i] == '.')
      {
          continue;
      }

      if (isdigit(str[i]) == false)
      {
         return false; //when one non numeric value is found, return false
      }
   }
      return true;
}

int main(int argc, char *argv[])
{

    double x, y;

switch(argv[1][0])
        {
            case 'a':
                if( isNumeric(argv[2]) && isNumeric(argv[3]))
                {
                    x = stod(argv[2]);
                    y = stod(argv[3]);
                    cout << x + y << endl;

                }
                else
                {
                    cout << "You didn't enter a legal number." << endl;
                }
                
                break;
            case 's':
                if( isNumeric(argv[2]) && isNumeric(argv[3]))
                {
                    x = stod(argv[2]);
                    y = stod(argv[3]);
                    cout << x - y << endl;

                }
                else
                {
                    cout << "You didn't enter a legal number." << endl;
                }
                break;
            case 'm':
                if( isNumeric(argv[2]) && isNumeric(argv[3]))
                {
                    x = stod(argv[2]);
                    y = stod(argv[3]);
                    cout << x * y << endl;

                }
                else
                {
                    cout << "You didn't enter a legal number." << endl;
                }
                break;
            case 'd':
                if( isNumeric(argv[2]) && isNumeric(argv[3]))
                {
                    x = stod(argv[2]);
                    y = stod(argv[3]);
                    cout << x / y << endl;

                }
                else
                {
                    cout << "You didn't enter a legal number." << endl;
                }
                break;
            default:
                cout << "You did not enter a legal number." << endl;

        }

}