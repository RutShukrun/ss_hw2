#include <stdio.h>
#include "myBank.h"

void open(struct account[50], double amount, int number);
void close(struct account[50], int number);
int status(struct account[50], int number);
double getAmount(struct account[50], int number);
void deposit(struct account[50], int number, double deposit);
void withdraw(struct account[50], int number, double withdraw);
void rate(struct account[50], int number, int rate);

int main()
{
    struct account data[50];
    int num=0, check=2, temp=0, rateToAdd=0;
    char type='A';
    double amount=0;
    
    for (int i=0; i<50; i++) //close all accounts and change the balance to 0 - init to all
    {
        close(data, i); //number==account position
    }

    while (type!='E')
    {
        printf("Transaction type?: ");
        scanf(" %c", &type);
        if (type=='O') //open new account
        {
            for (int i=0; i<50; i++) //check if it is possible to open an account
            {
                check=status(data, i);
                if (check==0) //account is closed
                {
                    printf("Initial deposit?: ");
                    scanf("%lf", &amount);
                    open(data, amount, i); //open an account and put amount
                    break;
                }    
                else //account is open, check==1
                {
                if (i!=49)
                    {
                        continue;
                    }
                else //i==49
                    {
                        printf("It is not possible to open an account right now.\n");
                    }
                        
            }
            }
        
        }
        else if (type=='B') //check the amount in the account
        {
            printf("Account number?: ");
            scanf("%d", &num);
            if (num<901 || num>950)
            {
               printf("Account number is invalid.\n"); 
            }
            else
            {
                temp=num-901;
                check=status(data, temp);
                if (check==0) //account is closed
                {
                    printf("The account is closed.\n");
                }
                else //account is open
                {
                    amount=getAmount(data, temp);
                    printf("The amount of account number %d is %0.2lf.\n", num, amount);
                }
    
            }
        }
        else if (type=='D') //deposit money to the account
        {
            printf("Account number?: ");
            scanf("%d", &num);
            if (num<901 || num>950)
            {
               printf("Account number is invalid.\n"); 
            }
            else
            {
                temp=num-901;
                check=status(data, temp);
                if (check==0) //account is closed
                {
                    printf("The account is closed.\n");
                }
                else //account is open
                {
                    printf("Amount?: ");
                    scanf("%lf", &amount);
                    deposit(data, temp, amount); 
                    amount=getAmount(data, temp);
                    printf("The new amount of account number %d is %0.2lf.\n", num, amount);
                }
            }
        }
        else if (type=='W') //withdraw money from the account
        {
            printf("Account number?: ");
            scanf("%d", &num);
            if (num<901 || num>950)
            {
               printf("Account number is invalid.\n"); 
            }
            else
            {
                temp=num-901;
                check=status(data, temp);
                if (check==0) //account is closed
                {
                    printf("The account is closed.\n");
                }
                else //account is open
                {
                    printf("Amount?: ");
                    scanf("%lf", &amount);
                    double j=getAmount(data, temp);
                    if (j>amount)
                    {
                        withdraw(data, temp, amount); 
                        amount=getAmount(data, temp);
                        printf("The new amount of account number %d is %0.2lf.\n", num, amount);   
                    }
                    else //there is not enough money to withdraw
                    {
                        printf("There is not enough money to withdraw in the account.\n");   
                    }
                }
            }
        }
        else if (type=='C') //close the account and change the balance to 0
        {
            printf("Account number?: ");
            scanf("%d", &num);
            if (num<901 || num>950)
            {
               printf("Account number is invalid.\n"); 
            }
            else
            {
                temp=num-901;
                check=status(data, temp);
                if (check==0) //account is closed
                {
                    printf("The account is closed.\n");
                }
                else //account is open
                {
                    close(data, temp);
                }
            }
        }
        else if (type=='I') //add rate to all open accounts
        {
            printf("Interest rate?: ");
            scanf("%d", &rateToAdd);
            for (int i=0; i<50; i++)
            {
                check=status(data, i);
                if (check==1) //account is closed
                {
                    rate(data, i, rateToAdd); 
                }
                else
                {
                    continue;
                }
            }
        }
       else if (type=='P') //print amounts of all open accounts
        {
            for (int i=0; i<50; i++)
            {
                check=status(data, i);
                if (check==1) //account is closed
                {
                    amount=getAmount(data, i);
                    num=i+901;
                    printf("The new amount of account number %d is %0.2lf.\n", num, amount); 
                }
            }
        }
    }
    
    for (int i=0; i<50; i++) //close all accounts and change the balance to 0
    {
        int check=status(data, i);
        if (check==1) //open
        {
            close(data, i); //number==account position
        }
    }
    return 0;
}
