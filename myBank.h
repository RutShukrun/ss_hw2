struct account
{
    int accNum;
    double balance;
    int status;
};

void open(struct account[50], double amount, int number);
void close(struct account[50], int number);
int status(struct account[50], int number);
double getAmount(struct account[50], int number);
void deposit(struct account[50], int number, double deposit);
void withdraw(struct account[50], int number, double withdraw);
void rate(struct account[50], int number, int rate);

