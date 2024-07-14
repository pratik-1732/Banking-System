# Banking System

## Overview

The Banking System is a C++ application designed to simulate a simple banking system where users can open accounts, deposit and withdraw money, check account balances, and perform basic transactions. The program utilizes classes and inheritance to model different account types such as savings and checking accounts.

## Features

- **Open Accounts:** Users can create new accounts specifying account type (savings or checking).
- **Deposit and Withdraw:** Perform transactions to deposit or withdraw money from accounts.
- **Check Account Balances:** View current balances of accounts.
- **Transaction History:** Maintain a transaction history for each account.
- **Interest Calculation:** Implement interest calculation for savings accounts.

## Account Types

### 1. Savings Account
- Allows deposit and withdrawal transactions.
- Earns interest based on a specified interest rate.

### 2. Checking Account
- Allows deposit and withdrawal transactions.
- May have overdraft protection or limits.

## Installation and Usage

1. **Clone the Repository:**
   ```bash
   git clone https://github.com/pratik-1732/Banking-System.git
   ```

2. **Navigate to the Project Directory:**
   ```bash
   cd banking-system
   ```

3. **Compile the Program:**
   Ensure you have a C++ compiler installed that supports C++11 or higher.
   ```bash
   g++ -o banking_system main.cpp
   ```

4. **Run the Program:**
   ```bash
   ./banking_system
   ```

5. **Follow On-Screen Instructions:**
   - Choose options to open accounts, deposit, withdraw, check balances, and view transaction history.
   - Specify account type (savings or checking) and enter necessary details.


## Contribution

Contributions are welcome! Here are some ideas for contributions:

- Implement additional account types (e.g., fixed deposit, money market).
- Enhance error handling and input validation.
- Improve interest calculation logic.
- Add support for multi-currency accounts.

If you'd like to contribute, please fork the repository and create a pull request. Feel free to open an issue to discuss any new features or improvements.
