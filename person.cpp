#include "person.h"

Person::Person(std::string name, int age, std::string placeOfBirth, std::string password, double balance, std::vector<std::string> transactions) {
    this->name = name;
    this->age = age;
    this->placeOfBirth = placeOfBirth;
    this->password = password;
    this->balance = balance;
    this->transactions = transactions;
}

std::string Person::getName() {
    return this->name;
}

int Person::getAge() {
    return this->age;
}

std::string Person::getPlaceOfBirth() {
    return this->placeOfBirth;
}

std::string Person::getPassword() {
    return this->password;
}

double Person::getBalance() {
    return this->balance;
}

std::vector<std::string> Person::getTransactions() {
    return this->transactions;
}

void Person::setName(std::string name) {
    this->name = name;
}

void Person::setAge(int age) {
    this->age = age;
}

void Person::setPlaceOfBirth(std::string placeOfBirth) {
    this->placeOfBirth = placeOfBirth;
}

void Person::setPassword(std::string password) {
    this->password = password;
}

void Person::setBalance(double balance) {
    this->balance = balance;
}

void Person::setTransactions(std::vector<std::string> transactions) {
    this->transactions = transactions;
}

void Person::addTransaction(std::string transaction) {
    this->transactions.push_back(transaction);
}
