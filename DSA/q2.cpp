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


#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

struct SavingsAccount {
    string name;
    int accountNumber;
    double balance;
    static double interestRate; 

    SavingsAccount(const string& accountHolder, int accNumber, double initialBalance)
        : name(accountHolder), accountNumber(accNumber), balance(initialBalance) {}

    void deposit(double amount) {
        balance += amount;
    }

    bool withdraw(double amount) {
        if (balance - amount >= 1000) {
            balance -= amount;
            return true;
        }
        return false;
    }

    void addInterest() {
        double interest = balance * interestRate;
        deposit(interest);
    }
};


double SavingsAccount::interestRate = 0.04; 

void createAccounts(vector<SavingsAccount>& accounts) {
    srand(time(0));
    for (int i = 0; i < 100; ++i) {
        string name = "AccountHolder" + to_string(i + 1);
        double initialBalance = 1000 + (rand() % 99001); 
        accounts.push_back(SavingsAccount(name, i + 1, initialBalance));
    }
}

void calculateInterest(vector<SavingsAccount>& accounts) {
    double totalInterest = 0.0;
    for (auto& account : accounts) {
        double interest = account.balance * SavingsAccount::interestRate;
        totalInterest += interest;
        account.addInterest();
    }
    cout << "Total interest paid to all accounts in one year: Rs. " << totalInterest << endl;
}

int main() {
    vector<SavingsAccount> accounts;
    createAccounts(accounts);


    cout << "Initial Account Balances:" << endl;
    for (const auto& account : accounts) {
        cout << "Account Number: " << account.accountNumber
             << ", Name: " << account.name
             << ", Balance: Rs. " << account.balance << endl;
    }


    calculateInterest(accounts);


    cout << "\nUpdated Account Balances after adding interest:" << endl;
    for (const auto& account : accounts) {
        cout << "Account Number: " << account.accountNumber
             << ", Name: " << account.name
             << ", Balance: Rs. " << account.balance << endl;
    }

    return 0;
}
