#include <iostream>
#include <vector>
using namespace std;

// Base Class
class BankAccount {
protected:
    int accNo;
    string name;
    double balance;

public:
    BankAccount(int a, string n, double b) {
        accNo = a;
        name = n;
        balance = b;
    }

    int getAccNo() { return accNo; }

    virtual void deposit(double amt) {
        balance += amt;
        cout << "Deposited: " << amt << endl;
    }

    virtual void withdraw(double amt) {
        if (amt <= balance) {
            balance -= amt;
            cout << "Withdrawn: " << amt << endl;
        } else {
            cout << "Insufficient balance!\n";
        }
    }

    virtual void display() {
        cout << "\nAcc No: " << accNo
             << "\nName: " << name
             << "\nBalance: " << balance << endl;
    }

    virtual void calculateInterest() = 0;

    virtual ~BankAccount() {}
};

// Savings Account
class SavingsAccount : public BankAccount {
public:
    SavingsAccount(int a, string n, double b)
        : BankAccount(a, n, b) {}

    void calculateInterest() override {
        double interest = balance * 0.05;
        balance += interest;
        cout << "Interest Added: " << interest << endl;
    }
};

// Checking Account
class CheckingAccount : public BankAccount {
public:
    CheckingAccount(int a, string n, double b)
        : BankAccount(a, n, b) {}

    void withdraw(double amt) override {
        if (amt <= balance + 1000) {
            balance -= amt;
            cout << "Withdrawn (Overdraft used if needed)\n";
        } else {
            cout << "Overdraft limit exceeded!\n";
        }
    }

    void calculateInterest() override {
        cout << "No interest for Checking Account\n";
    }
};

// Fixed Deposit Account
class FixedDepositAccount : public BankAccount {
public:
    FixedDepositAccount(int a, string n, double b)
        : BankAccount(a, n, b) {}

    void withdraw(double amt) override {
        cout << "Cannot withdraw before maturity!\n";
    }

    void calculateInterest() override {
        double interest = balance * 0.1;
        cout << "FD Interest: " << interest << endl;
    }
};

// Search Function
BankAccount* findAccount(vector<BankAccount*> &accs, int accNo) {
    for (auto acc : accs) {
        if (acc->getAccNo() == accNo)
            return acc;
    }
    return NULL;
}

// Main
int main() {
    vector<BankAccount*> accounts;

    int choice, accNo, type;
    string name;
    double balance, amt;

    do {
        cout << "\n===== BANK MENU =====";
        cout << "\n1. Create Account";
        cout << "\n2. Deposit";
        cout << "\n3. Withdraw";
        cout << "\n4. Display Account";
        cout << "\n5. Calculate Interest";
        cout << "\n6. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Enter Acc No: ";
            cin >> accNo;
            cout << "Enter Name: ";
            cin >> name;
            cout << "Enter Balance: ";
            cin >> balance;

            cout << "1. Savings  2. Checking  3. Fixed Deposit\n";
            cout << "Select Account Type: ";
            cin >> type;

            if (type == 1)
                accounts.push_back(new SavingsAccount(accNo, name, balance));
            else if (type == 2)
                accounts.push_back(new CheckingAccount(accNo, name, balance));
            else if (type == 3)
                accounts.push_back(new FixedDepositAccount(accNo, name, balance));
            else
                cout << "Invalid type!\n";

            break;

        case 2:
            cout << "Enter Acc No: ";
            cin >> accNo;
            cout << "Enter Amount: ";
            cin >> amt;

            if (findAccount(accounts, accNo))
                findAccount(accounts, accNo)->deposit(amt);
            else
                cout << "Account not found!\n";

            break;

        case 3:
            cout << "Enter Acc No: ";
            cin >> accNo;
            cout << "Enter Amount: ";
            cin >> amt;

            if (findAccount(accounts, accNo))
                findAccount(accounts, accNo)->withdraw(amt);
            else
                cout << "Account not found!\n";

            break;

        case 4:
            cout << "Enter Acc No: ";
            cin >> accNo;

            if (findAccount(accounts, accNo))
                findAccount(accounts, accNo)->display();
            else
                cout << "Account not found!\n";

            break;

        case 5:
            cout << "Enter Acc No: ";
            cin >> accNo;

            if (findAccount(accounts, accNo))
                findAccount(accounts, accNo)->calculateInterest();
            else
                cout << "Account not found!\n";

            break;

        case 6:
            cout << "Thank You!\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 6);

    // Free Memory
    for (auto acc : accounts)
        delete acc;

    return 0;
}