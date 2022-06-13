#include <stdio.h>


//Got the answer to putting a function in a struct from this guy:
//  https://stackoverflow.com/a/32964582/13972774
//Brilliant idea.


//Build the struct, the member is:
// pointer to someFunction, typecast to an int
//The typedef creates hello as the variable "type"
typedef struct hello {
    int (*someFunction)();
} hello;

typedef struct sum {
    int a;
    int b;
    int (*add2nums)(int a, int b);
} sum;

//Declare a function that returns the int for *someFunction
int foo() {
    return 0;
}

int add(int a, int b){

     return a + b;
}


//Declare a function that returns the struct type of
//our typedef'ed struct called hello
hello Hello() {
    //declare a new hello struct called aHello
    struct hello aHello;

    //Tell aHello member "pointer to someFunction"
    //to point to function foo
    aHello.someFunction = &foo;

    //now return the init-ed struct
    return aHello;
}

sum Sum(){
     struct sum mySum;
     mySum.add2nums = &add;

     return mySum;
}



int main()
{
    //create a struct and init it to Hello function
    //is Hello() now a constructor?
    struct hello aHello = Hello();
    struct sum aSum = Sum();

    //Now, when we call that someFunction member,
    //it runs the foo function and returns a 0 to printf
    printf("Print hello: %d\n", aHello.someFunction());

    aSum.a = 3;
    aSum.b = 3;

    printf("The sum is: %d\n", aSum.add2nums(aSum.a, aSum.b));


    return 0;
} 
