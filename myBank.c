struct account
{
    int accNum;
    double balance;
    int status;
};

void open(struct account data[50], double amount, int number)
{
    data[number].status=1;
    data[number].balance=amount;
}

void close(struct account data[50], int number)
{
    data[number].status=0;
    data[number].balance=0;
}

int status(struct account data[50], int number)
{
    if (data[number].status==0)
    {
       // printf("The status of account %d is 0=close\n", number);
        return 0; //close
    }
    else
    {
       // printf("The status of account %d is 1=open\n", number);
        return 1; //open
    }
}

double getAmount(struct account data[50], int number)
{
    return data[number].balance;
}

void deposit(struct account data[50], int number, double deposit)
{
    data[number].balance+=deposit;
}

void withdraw(struct account data[50], int number, double withdraw)
{
    data[number].balance-=withdraw;
}

void rate(struct account data[50], int number, int rate)
{
    double add=(data[number].balance)/100*rate;
    data[number].balance+=add;
}

