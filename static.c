//Effective C book

#include <stdio.h>

//objects (things with values) have lifetimes
//Used to, objects with lifetime storage duration
//were globals declared outside of all functions, even main
//Those are frowned upon. So, we have static keyword
//static creates a lifetime duration wherever it is placed

//A non-static integer assignment would result in
//an output of 1 1 1 1 1 because counter would be set to zero
//upon each entry to the function
//Static integer assignment holds the lifetime value of 
//counter (more or less, doesn't reset to zero each time entered)
unsigned int increment(void)
{
    //statics must start assigned
    static unsigned int counter = 0;
    counter++;

    //Original example had a printf here
    //Exercise said to create a retrieve function,
    //but to make a function, one has to pass in the counter
    //Its scope is only here.
    //So, it's easier to just return counter value.
    return counter;

}

int main(void)
{
    for(int i = 0; i < 6; i++){
        unsigned int a = increment();
        printf("%d ", a);
    }
    printf("\n");
    return 0;
}