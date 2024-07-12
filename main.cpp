#include <bits/stdc++.h>
using namespace std;

class Account
{
protected:
    string accountNumber;
    string ownerName;
    double balance;

public:
    Account(string accountNumber, string ownerName, double balance)
    {
        this->accountNumber = accountNumber;
        this->ownerName = ownerName;
        this->balance = balance;
    }

    virtual void deposit(double amount)
    {
        balance += amount;
    }

    virtual void withdraw(double amount)
    {
        if (amount <= balance)
        {
            balance -= amount;
            cout << "Now your remaining balnace is: ";
            cout << balance << endl;
        }
        else
        {
            cout << "Insufficient balance." << endl;
        }
    }

    virtual double getBalance()
    {
        return balance;
    }

    string getAccountNumber()
    {
        return accountNumber;
    }

    string getOwnerName()
    {
        return ownerName;
    }

    virtual void display()
    {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Owner Name: " << ownerName << endl;
        cout << "Balance: " << balance << " RS" << endl;
    }
};

// saving account

class SavingsAccount : public Account
{
public:
    SavingsAccount(string accountNumber, string ownerName, double balance)
        : Account(accountNumber, ownerName, balance) {}

    void display() override
    {
        cout << "Savings: ";
        Account::display();
    }
};

// checking account

class CheckingAccount : public Account
{
public:
    CheckingAccount(string accountNumber, string ownerName, double balance)
        : Account(accountNumber, ownerName, balance) {}

    void display() override
    {
        cout << "Checking: ";
        Account::display();
    }
};

// banking system

class BankingSystem
{
private:
    vector<Account *> accounts;

public:
    void openAccount(string accountType, string accountNumber, string ownerName, double initialDeposit)
    {
        Account *account = nullptr;

        if (accountType == "Savings")
        {
            account = new SavingsAccount(accountNumber, ownerName, initialDeposit);
        }
        else if (accountType == "Checking")
        {
            account = new CheckingAccount(accountNumber, ownerName, initialDeposit);
        }

        if (account)
        {
            accounts.push_back(account);
            cout << accountType << " account opened successfully!" << endl;
        }
        else
        {
            cout << "Invalid account type." << endl;
        }
    }

    void deposit(string accountNumber, double amount)
    {
        Account *account = findAccount(accountNumber);
        if (account)
        {
            account->deposit(amount);
            cout << "Deposit successful." << endl;
        }
        else
        {
            cout << "Account not found." << endl;
        }
    }

    void withdraw(string accountNumber, double amount)
    {
        Account *account = findAccount(accountNumber);
        if (account)
        {
            account->withdraw(amount);
            cout << "Withdrawal successful." << endl;
        }
        else
        {
            cout << "Account not found." << endl;
        }
    }

    void checkBalance(string accountNumber)
    {
        Account *account = findAccount(accountNumber);
        if (account)
        {
            cout << "Balance: " << account->getBalance() << " RS" << endl;
        }
        else
        {
            cout << "Account not found." << endl;
        }
    }

    void displayAccounts()
    {
        for (auto account : accounts)
        {
            account->display();
            cout << "---------------------------------" << endl;
        }
    }

private:
    Account *findAccount(string accountNumber)
    {
        for (auto account : accounts)
        {
            if (account->getAccountNumber() == accountNumber)
            {
                return account;
            }
        }
        return nullptr;
    }
};

int main()
{
    BankingSystem bank;
    string accountType, accountNumber, ownerName;
    double amount;

    int choice;
    while (true)
    {
        cout << "Banking System Menu: " << endl;
        cout << "1. Open Account " << endl;
        cout << "2. Deposit Money " << endl;
        cout << "3. Withdraw Money " << endl;
        cout << "4. Check Balance " << endl;
        cout << "5. Display All Accounts " << endl;
        cout << "6. Exit " << endl;
        cout << "Enter your choice: " << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter account type (Savings/Checking): ";
            cin >> accountType;
            cout << "Enter owner name: ";
            cin.ignore();
            getline(cin, ownerName);

            cout << "Enter account number: ";
            cin >> accountNumber;

            cout << "Enter initial deposit amount: ";
            cin >> amount;
            bank.openAccount(accountType, accountNumber, ownerName, amount);
            break;

        case 2:
            cout << "Enter account number: ";
            cin >> accountNumber;
            cout << "Enter deposit amount: ";
            cin >> amount;
            bank.deposit(accountNumber, amount);
            break;

        case 3:
            cout << "Enter account number: ";
            cin >> accountNumber;
            cout << "Enter withdrawal amount: ";
            cin >> amount;
            bank.withdraw(accountNumber, amount);
            break;

        case 4:
            cout << "Enter account number: ";
            cin >> accountNumber;
            bank.checkBalance(accountNumber);
            break;

        case 5:
            bank.displayAccounts();
            break;

        case 6:
            cout << "Exiting..." << endl;
            return 0;

        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}