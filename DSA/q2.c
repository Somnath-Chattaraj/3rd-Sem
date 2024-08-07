// A simple structure SavingsAccount for savings account used in banks as follows: Each SavingsAccount
// structure variable should have three data members to store the account holder’s name, unique account
// number and balance of the account. Assume account numbers are integers and generated sequentially. Note
// that once an account number is allocated to an account, it does not change during the entire operational
// period of the account. The bank also specifies a rate of interest for all savings accounts created. Write
// relevant methods (such as withdraw, deposit etc.). The bank restricts that each account must have a
// minimum balance of Rs. 1000. Now create 100 SavingsAccount variable specifying balance at random
// ranging from Rs. 1,000 to 1,00,000. Now, calculate the interest for one year to be paid to each account and
// deposit the interest to the corresponding balance. Also find out total amount of interest to be paid to all
// accounts in one year. (Note: create at least 10 accounts for smooth operation)


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ACCOUNTS 100
#define MIN_BALANCE 1000
#define INTEREST_RATE 0.04

typedef struct {
    char name[50];
    int accountNumber;
    double balance;
} SavingsAccount;

void createAccounts(SavingsAccount* accounts) {
    srand(time(0));
    for (int i = 0; i < NUM_ACCOUNTS; ++i) {
        sprintf(accounts[i].name, "AccountHolder%d", i + 1);
        accounts[i].accountNumber = i + 1;
        accounts[i].balance = MIN_BALANCE + (rand() % 99001); // Random balance between 1000 and 100000
    }
}

void calculateInterest(SavingsAccount* accounts) {
    double totalInterest = 0.0;
    for (int i = 0; i < NUM_ACCOUNTS; ++i) {
        double interest = accounts[i].balance * INTEREST_RATE;
        totalInterest += interest;
        accounts[i].balance += interest;
    }
    printf("Total interest paid to all accounts in one year: Rs. %.2f\n", totalInterest);
}

void printAccounts(SavingsAccount* accounts) {
    for (int i = 0; i < NUM_ACCOUNTS; ++i) {
        printf("Account Number: %d, Name: %s, Balance: Rs. %.2f\n", accounts[i].accountNumber, accounts[i].name, accounts[i].balance);
    }
}

int main() {
    SavingsAccount accounts[NUM_ACCOUNTS];

    createAccounts(accounts);

    // Display initial account balances
    printf("Initial Account Balances:\n");
    printAccounts(accounts);

    // Calculate and add interest to each account
    calculateInterest(accounts);

    // Display updated account balances
    printf("\nUpdated Account Balances after adding interest:\n");
    printAccounts(accounts);

    return 0;
}
