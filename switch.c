//From Effective C book
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    //Note: I did not create a CD account type
    typedef enum { Savings, Checking, MoneyMarket } AccountType;

    AccountType account;
    double interest_rate;
    double balance = 1000.00;

    //If I send an account type that 
    //doesn't exist, the switch aborts
    //enums are just integers, mostly
    account = 8;

    switch(account){
        case Savings:
            interest_rate = .01;
            break;
        case Checking:
            interest_rate = .005;
            break;
        case MoneyMarket:
            interest_rate = .02;
            break;
        default:
            abort();
    }

    printf("Your interest earnings are; %4.2f with a balance of %4.2f\n", balance * interest_rate, balance);
    return 0;
}