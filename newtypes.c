//Effective C book
#include <stdio.h>
#include <stdbool.h> //for boolean types

int main(void)
{
    bool flag1 = true;
    bool flag2 = false;

    //There is no specifier for bools, but StackOverflow
    //showed that a conditional statement with string specifiers works.
    printf("Boolean flags: flag1( %s ), flag2( %s )\n", flag1 ? "true" : "false", flag2 ? "true" : "false");

    //enum types (DO NOT use an equals sign)
    enum day { sunday, monday, tuesday, wednesday, thursday, friday, saturday };
    //sunday = 0

    enum cardinals { north = 0, east = 90, south = 180, west = 270 };

    enum months { january = 1, february, march, april, may, june, july, august, september, october, november, december };
    //january equals 1 instead of 0, others don't need assignment

    //enum values are only integers, not their names
    //this prints 0 through 6, not sunday through saturday
    //but the test is against saturday ( value of 6 ) and it works
    for(int i = 0; i <= saturday; i++)
    {
        printf("%d ", i);
    }

    printf("\n");
}
