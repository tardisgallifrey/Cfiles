#include <stdio.h>

/*
This is extended assembler in GCC

asm is legal as is __asm__
volatile is legal as is __volatile__

volatile after asm tells GCC not to move our code,
it must perform where it is.  Keeps GCC from trying to 
optimize it.  Use when having to be very careful, but
not normal calculations and expected things.


 asm ( assembler template 
           : output operands                  
           : input operands                  
           : list of clobbered registers      
           );

assembler template is our assembly code such as movb ax, bx.
It must be in double quotes, either per line, or in total.
If you do total, lines need to end in semi-colon.
Each line should or could also end in \n\t, GCC sends each line as 
a string.

The Three colons are optional, but useful to do anything.
First colon identifies output operands (C variables).
Second colon identifies input operands (C variables).
Third line is clobberlist of registers GCC shouldn't trust.

OUTPUT OPERANDS
"constraint"(operand) such as "=r"(count) meaning:
the output operand is the variable "count" and it is write only 
"=r" -- write only
"=c" -- operand is output in register I specify in asm

INPUT OPERANDS are similar
"r" -- read the variable
"0" -- use the same register for input and output
"c" -- variable will be placed in register I specify in asm
"m" -- variable acted upon in memory

Common register constraints
+---+--------------------+
| r |    Register(s)     | lets GCC choose
+---+--------------------+
| a |   %eax, %ax, %al   |  for these, I choose register
| b |   %ebx, %bx, %bl   |
| c |   %ecx, %cx, %cl   |
| d |   %edx, %dx, %dl   |
| S |   %esi, %si        |
| D |   %edi, %di        |
+---+--------------------+

To use the same operand for both input and output, do this:
asm ("incl %0\n\t" 
        :"=a"(var)
        :"0"(var));

The "0" in input operands means "use the 0th operand", which is in output.

As is for the constraints above make them input constraints.
Put an = in front for an output constraint.

If an operand (variable, limit of 10) is used in the assembler, use %num such as:
asm ("leal (%1,%1,4), %0"
             : "=r" (five_times_x)
             : "r" (x) 
             );
five_times_x = %0
x = %1

Last colon is for clobberlist
We do not need to enter registers in the clobberlist that GCC knows
what is going on, such as the ones we specfically use in input or output operands.
But, if we use registers that aren't listed in input/output operands, put them here.
Use cc for condition code register if it is clobbered.
Use memory if we are going to use memory in an unusual way.
*/


void myFunction(void);
void anotherFunction(void);
void stillmore(void);
void andagain(void);
void multiplyfive(void);

int main(void)
{
        myFunction();
        anotherFunction();
        stillmore();
        andagain();
        multiplyfive();
        return 0;
}


void myFunction(void){

 int foo = 10, bar = 15;
        __asm__ __volatile__("addl  %%ebx,%%eax"
                             :"=a"(foo)
                             :"a"(foo), "b"(bar)
                             );
        printf("foo+bar=%d\n", foo);

}

void anotherFunction(void){
        asm("movl $10, %ecx\n\t"
            "movl %ecx, %eax");
}

void stillmore(void){

       int a=10, b;
        asm ("movl %1, %%eax\n\t" 
             "movl %%eax, %0\n\t"
             :"=r"(b)        /* output */
             :"r"(a)         /* input */
             :"%eax"         /* clobbered register */
             );    

        printf("a = %d and b = %d\n", a, b);   
}

void andagain(void){
        int count, fill_value, dest;
        count = 1;
        fill_value = 2;
        dest = 0;

        asm ("cld\n\t"
             "rep\n\t"
             "stosl"
             : /* no output registers */
             : "r" (count), "r" (fill_value), "r" (dest)
             : "%ecx", "%edi" 
             );
             printf("count = %d  fill_value = %d dest = %d \n", count, fill_value, dest);
}

void multiplyfive(void){

        int x = 2;
        int five_times_x = 0;

        asm ("leal (%1,%1,4), %0"
             : "=r" (five_times_x)
             : "r" (x) 
             );

             printf("x = %d five_times_x = %d\n", x, five_times_x);
}