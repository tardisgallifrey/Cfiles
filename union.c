//Effective C book
#include <stdio.h>

int main(void)
{
    //In a union, all elements occupy same memory
    //I can get the intnode or the doublenode, but not both at same time.
    union{
        struct{
            int type;
        }n;
        struct{
            int type;
            int intnode;
        }ni;
        struct{
            int type;
            double doublenode;
        }nf;
    }u;

    u.nf.type = 1;
    u.ni.intnode = 36;
    u.nf.doublenode = 3.14;

    //Even though I set u.nf.type with 1, u.n.type also has 1
    printf("type: %d\n", u.n.type);

    //To use it well, check u.n.type, then pick correct struct
    u.nf.type = 0;
    u.nf.doublenode = 3.1417;

    //With u.nf.type set to 1, this still prints doublenode
    //because u.n.type is also 1
    if(u.n.type < 1)
    {
        printf("Union value is: %d\n", u.ni.intnode);
    }
    else
    {
        printf("Union value is %f\n", u.nf.doublenode);
    }


}