#include <iostream>
#include <iomanip>
#include <limits>
#include <sstream>
#include "classes.h"
using namespace std;

namespace finance {

// Helper function to format currency with commas
string formatCurrency(double amount) {
  stringstream ss;
  ss << fixed << setprecision(2) << amount;
  string str = ss.str();
  int decimalPos = str.find('.');
  int len = decimalPos; // Length of integer part
  string result;
  int commaPos = len % 3 == 0 ? 3 : len % 3;
  for (int i = 0; i < len; ++i) {
    if (i == commaPos && i != 0) {
      result += ',';
      commaPos += 3;
    }
    result += str[i];
  }
  result += str.substr(decimalPos); // Add decimal part
  return "$" + result;
}

// Helper function for reward tier
string getRewardTier(int points) {
  if (points >= 5000) return "Gold";
  if (points >= 1000) return "Silver";
  return "Bronze";
}

// BankAccount implementation
BankAccount::BankAccount(const string& holder, double initialBalance)
    : accountHolder(holder), balance(initialBalance >= 0 ? initialBalance : 0), gamePoints(0) {}

void BankAccount::deposit(double amount) {
  if (amount > 0) {
    balance += amount;
    gamePoints += static_cast<int>(amount / 10);
    transactionHistory.emplace_back("Deposit", amount);
    cout << "   Deposited: " << formatCurrency(amount) << "\n"
         << "   New balance: " << formatCurrency(balance) << "\n"
         << "   Points: " << gamePoints << " (" << getRewardTier(gamePoints) << " tier)\n";
  } else {
    cout << "   Invalid deposit.\n\n";
  }
}

void BankAccount::print() const {
  cout << "   Account Holder: " << accountHolder << "\n"
       << "   Balance: " << formatCurrency(balance) << "\n"
       << "   Game Points: " << gamePoints << " (" << getRewardTier(gamePoints) << " tier)\n"
       << "   Transaction History:\n";
  if (transactionHistory.empty()) {
    cout << "     No transactions.\n";
  } else {
    for (const auto& [type, amount] : transactionHistory) {
      cout << "     " << type << ": " << formatCurrency(amount) << "\n";
    }
  }
}

void BankAccount::applyInterest() {
  cout << "   No interest.\n\n";
}

// SavingsAccount implementation
SavingsAccount::SavingsAccount(const string& holder, double initialBalance, double rate)
    : BankAccount(holder, initialBalance), interestRate(rate >= 0 ? rate : 0) {}

void SavingsAccount::applyInterest() {
  double interest = balance * interestRate / 100;
  balance += interest;
  cout << "   Applied: " << interestRate << "% interest\n"
       << "   Interest earned: " << formatCurrency(interest) << "\n"
       << "   New balance: " << formatCurrency(balance) << "\n";
}

// Deposit implementation
Deposit::Deposit(double amt) : amount(amt >= 0 ? amt : 0) {}

void Deposit::process(double& balance, int& points) const {
  if (amount > 0) {
    balance += amount;
    points += static_cast<int>(amount / 10);
    cout << "   Deposited: " << formatCurrency(amount) << "\n"
         << "   New balance: " << formatCurrency(balance) << "\n"
         << "   Points: " << points << " (" << getRewardTier(points) << " tier)\n";
  } else {
    cout << "   Invalid deposit.\n\n";
  }
}

// Withdrawal implementation
Withdrawal::Withdrawal(double amt) : amount(amt >= 0 ? amt : 0) {}

void Withdrawal::process(double& balance, int& points) const {
  if (amount > 0 && amount <= balance) {
    balance -= amount;
    points += static_cast<int>(amount / 20);
    cout << "   Withdrawn: " << formatCurrency(amount) << "\n"
         << "   New balance: " << formatCurrency(balance) << "\n"
         << "   Points: " << points << " (" << getRewardTier(points) << " tier)\n";
  } else {
    cout << "   Invalid withdrawal.\n\n";
  }
}

// FinancialInstrument implementations
Stock::Stock(const string& sym, double p, int s)
    : symbol(sym), price(p >= 0 ? p : 0), shares(s >= 0 ? s : 0) {}

double Stock::calculateValue() const {
  return price * shares;
}

void Stock::print() const {
  cout << "   Stock: " << symbol << ", Shares: " << shares
       << ", Price: " << formatCurrency(price)
       << ", Value: " << formatCurrency(calculateValue()) << "\n";
}

Bond::Bond(double fv, double cr)
    : faceValue(fv >= 0 ? fv : 0), couponRate(cr >= 0 ? cr : 0) {}

double Bond::calculateValue() const {
  return faceValue;
}

void Bond::print() const {
  cout << "   Bond: Face Value: " << formatCurrency(faceValue)
       << ", Coupon Rate: " << couponRate << "%, Value: " << formatCurrency(calculateValue()) << "\n";
}

// Menu function
void classes() {
  while (true) {
    cout << "\nExploring Classes in Finance - Choose an option (1-4, 0 to exit):\n"
         << "1. Basic Class (Bank Account)\n"
         << "2. Inheritance (Savings Account)\n"
         << "3. Polymorphism (Transactions)\n"
         << "4. Abstract Class (Financial Instruments)\n"
         << "Enter choice: ";
    int choice;
    if (!(cin >> choice)) {
      cout << "Invalid input. Please enter a number.\n\n";
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      continue;
    }
    if (choice == 0) {
      cout << "Exiting.\n";
      break;
    }
    switch (choice) {
      case 1: {
        cout << "\n1. Basic Class: BankAccount to manage balance and transactions.\n";
        cout << "   Enter account holder name: ";
        string name;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, name);
        cout << "   Enter initial balance: $";
        double balance;
        if (!(cin >> balance) || balance < 0) {
          cout << "   Invalid input. Using default $0.\n\n";
          cin.clear();
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
          balance = 0;
        }
        BankAccount account(name, balance);
        cout << "   Enter deposit amount: $";
        double deposit;
        if (!(cin >> deposit)) {
          cout << "   Invalid input. No deposit made.\n\n";
          cin.clear();
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
          deposit = 0;
        }
        account.deposit(deposit);
        cout << fixed << setprecision(2);
        account.print();
        break;
      }
      case 2: {
        cout << "\n2. Inheritance: SavingsAccount inherits from BankAccount.\n";
        cout << "   Enter account holder name: ";
        string name;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, name);
        cout << "   Enter initial balance: $";
        double balance;
        if (!(cin >> balance) || balance < 0) {
          cout << "   Invalid input. Using default $0.\n\n";
          cin.clear();
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
          balance = 0;
        }
        SavingsAccount account(name, balance, 2.5);
        account.applyInterest();
        account.print();
        break;
      }
      case 3: {
        cout << "\n3. Polymorphism: Different transaction types.\n";
        double balance = 1000.0;
        int points = 0;
        cout << "   Starting balance: " << formatCurrency(balance) << ", Points: " << points
             << " (" << getRewardTier(points) << " tier)\n";
        Transaction* transactions[] = {new Deposit(500.0), new Withdrawal(200.0)};
        for (int i = 0; i < 2; ++i) {
          transactions[i]->process(balance, points);
          delete transactions[i];
        }
        break;
      }
      case 4: {
        cout << "\n4. Abstract Class: Financial instruments like stocks or bonds.\n";
        FinancialInstrument* portfolio[] = {new Stock("AAPL", 150.0, 10), new Bond(1000.0, 5.0)};
        for (int i = 0; i < 2; ++i) {
          portfolio[i]->print();
          delete portfolio[i];
        }
        break;
      }
      default:
        cout << "Invalid choice. Choose 1-4 or 0 to exit.\n\n";
        break;
    }
  }
}

} // namespace finance