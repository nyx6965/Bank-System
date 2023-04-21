#include <random>
#include <string>
#if !defined(ACCOUNT_H)
#define ACCOUNT_H
#include "SQL.h"
#include <iostream>
#include <sqlite3.h>

class Account {
private:
  std::string pin;
  double balance;
  std::string name;
  std::string account_number;

public:
  SQL operation;
  void account_create(sqlite3 *db);
  void account_search(sqlite3 *db);
  void account_show_all(sqlite3 *db);
  void account_delete(sqlite3 *db);
};

void Account::account_create(sqlite3 *db) {

  std::cout << "Name: ";
  std::getline(std::cin >> std::ws, this->name);

  std::cout << "Pin: ";
  std::getline(std::cin >> std::ws, this->pin);

  std::cout << "Balance: ";
  std::cin >> this->balance;

  this->operation.sql_account_insert(db, this->name, this->balance, this->pin);
};

void Account::account_search(sqlite3 *db) {

  int id;
  std::cout << "Enter a ID number: ";
  std::cin >> id;

  this->operation.sql_account_search(db, "Amr", id);
}

void Account::account_show_all(sqlite3 *db) {
  this->operation.sql_account_show_all(db);
}

void Account::account_delete(sqlite3 *db) {

  int id;
  std::cout << "Enter a ID number: ";
  std::cin >> id;
  this->operation.sql_account_delete(db, id);
}

#endif
