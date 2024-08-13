#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <numeric>

using namespace std;
class SavingsAccount {
private:
    static int accountCounter;
     string name;
    int accountNumber;
    double balance;
    static const double interestRate;

public:
    SavingsAccount( string name, double balance) : name(name), accountNumber(++accountCounter), balance(balance) {}

    void deposit(double amount) {
        balance += amount;
    }

    void withdraw(double amount) {
        if (balance - amount >= 1000) {
            balance -= amount;
        } else {
             cout << "Cannot withdraw. Minimum balance required is 1000." <<  endl;
        }
    }

    void addInterest() {
        double interest = balance * interestRate;
        deposit(interest);
    }

    double getBalance() const {
        return balance;
    }

    static double totalInterestPaid(const  vector<SavingsAccount>& accounts) {
        return  accumulate(accounts.begin(), accounts.end(), 0.0, [](double sum, const SavingsAccount& acc) {
            return sum + acc.balance * interestRate;
        });
    }
};

int SavingsAccount::accountCounter = 0;
const double SavingsAccount::interestRate = 0.04;

int main() {
    srand(static_cast<unsigned int>(time(0)));

     vector<SavingsAccount> accounts;
    for (int i = 0; i < 100; ++i) {
        accounts.push_back(SavingsAccount("Account" +  to_string(i+1), 1000 + rand() % 100000));
    }

    for (auto& account : accounts) {
        account.addInterest();
    }

    double totalInterest = SavingsAccount::totalInterestPaid(accounts);
     cout << "Total interest paid to all accounts: " << totalInterest <<  endl;

    return 0;
}
