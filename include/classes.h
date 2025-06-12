#ifndef CLASSES_H
#define CLASSES_H

#include <string>
#include <vector>

namespace finance {

class BankAccount {
 public:
  explicit BankAccount(const std::string& holder, double initialBalance = 0.0);
  void deposit(double amount);
  void print() const;
  int getGamePoints() const { return gamePoints; }
  virtual void applyInterest(); // Made virtual to allow overriding

 protected:
  std::string accountHolder;
  double balance;
  int gamePoints;
  std::vector<std::pair<std::string, double>> transactionHistory;
};

class SavingsAccount : public BankAccount {
 public:
  explicit SavingsAccount(const std::string& holder, double initialBalance, double rate);
  void applyInterest() override;
 private:
  double interestRate;
};

class Transaction {
 public:
  virtual void process(double& balance, int& points) const = 0;
  virtual ~Transaction() = default;
};

class Deposit : public Transaction {
 public:
  explicit Deposit(double amt);
  void process(double& balance, int& points) const override;
 private:
  double amount;
};

class Withdrawal : public Transaction {
 public:
  explicit Withdrawal(double amt);
  void process(double& balance, int& points) const override;
 private:
  double amount;
};

class FinancialInstrument {
 public:
  virtual double calculateValue() const = 0;
  virtual void print() const = 0;
  virtual ~FinancialInstrument() = default;
};

class Stock : public FinancialInstrument {
 public:
  explicit Stock(const std::string& sym, double p, int s);
  double calculateValue() const override;
  void print() const override;
 private:
  std::string symbol;
  double price;
  int shares;
};

class Bond : public FinancialInstrument {
 public:
  explicit Bond(double fv, double cr);
  double calculateValue() const override;
  void print() const override;
 private:
  double faceValue;
  double couponRate;
};

std::string formatCurrency(double amount);
std::string getRewardTier(int points);
void classes();

} // namespace finance

#endif // CLASSES_H