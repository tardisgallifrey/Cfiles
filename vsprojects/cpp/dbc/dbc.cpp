#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;


//Keep this number from string checker
bool isNumeric(string str) {
   for (int i = 0; i < str.length(); i++)
      if (isdigit(str[i]) == false)
         return false; //when one non numeric value is found, return false
      return true;
}

int main(int argc, char *argv[])
{

    char operators[4]={ 'a', 's', 'm', 'd' };
    int operator_case[4]={1, 2, 3, 4};
    int operator_val = 0;
    double x, y;


    if( argc != 4)
    {

        //If we don't have right number of args, print Usage statement
        cout << "Usage: dbc op num1 num2" << endl;
        cout << "       Where: op = a, s, m, or d" << endl;
        cout << "              num1 = any float number" << endl;
        cout << "              num2 = any float number" << endl;
        cout << "    spaces are important" << endl;
        exit(0);

    }

    //make an integer from operator string on command line
    //so that switch/case works
    for(int i; i < 5; i++)
    {

        //find matching operator
        //assign it correct integer
        if(argv[1][0] == operators[i])
        {

            operator_val = operator_case[i];

        }

    }

    if(operator_val > 0)
    {

        switch(argv[1][0])
        {
            case 'a':
                if( isNumeric(argv[2]) && isNumeric(argv[3]))
                {
                    x = stod(argv[2]);
                    y = stod(argv[3]);
                    cout << x + y << endl;

                }
                break;
            case 's':
                if( isNumeric(argv[2]) && isNumeric(argv[3]))
                {
                    x = stod(argv[2]);
                    y = stod(argv[3]);
                    cout << x - y << endl;

                }
                break;
            case 'm':
                if( isNumeric(argv[2]) && isNumeric(argv[3]))
                {
                    x = stod(argv[2]);
                    y = stod(argv[3]);
                    cout << x * y << endl;

                }
                break;
            case 'd':
                if( isNumeric(argv[2]) && isNumeric(argv[3]))
                {
                    x = stod(argv[2]);
                    y = stod(argv[3]);
                    cout << x / y << endl;

                }
                break;
            default:
                cout << "You did not enter a legal number." << endl;

        }

    }
    else
    {

        cout << "You did not enter a proper operator ( a , s, m, or d )" << endl;

    }
    
    return 0;
}