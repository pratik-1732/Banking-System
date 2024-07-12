#include <bits/stdc++.h>
using namespace std;

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