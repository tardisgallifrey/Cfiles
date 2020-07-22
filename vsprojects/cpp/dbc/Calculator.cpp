#include <iostream>

class Calculator
{
    public:

        //Declare a static method in our class
        //static methods & values, but not static classes.
        //Add method
        static double Add(double x, double y)
        {

            return x + y;

        }

        //Subtract method
        static double Subtract(double x, double y)
        {

            return x - y;

        }

        static double Multiply( double x, double y )
        {

            return x * y;

        }

        static double Divide( double x, double y )
        {

            return x / y;

        }


};  //class closures require semicolon