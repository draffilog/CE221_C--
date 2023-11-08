#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "person.h"

using namespace std;

Person* authenticateUser(string name, string password) {
    ifstream file("users.txt");
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string token;
        getline(ss, token, ',');
        if (token == name) {
            getline(ss, token, ',');
            int age = stoi(token);
            getline(ss, token, ',');
            string placeOfBirth = token;
            getline(ss, token, ',');
            if (token == password) {
                getline(ss, token, ',');
                double balance = stod(token);
                vector<string> transactions;
                while (getline(ss, token, ',')) {
                    transactions.push_back(token);
                }
                return new Person(name, age, placeOfBirth, password, balance, transactions);
            }
        }
    }
    return nullptr;
}

void registerUser(Person* person) {
    ofstream file("users.txt", ios::app);
    file << person->getName() << "," << person->getAge() << "," << person->getPlaceOfBirth() << "," << person->getPassword() << "," << person->getBalance();
    for (string transaction : person->getTransactions()) {
        file << "," << transaction;
    }
    file << "\n";
}

void makeTransaction(Person* person, string transaction) {
    person->addTransaction(transaction);
    registerUser(person);
}

void printUser(Person* person) {
    cout << "Welcome " << person->getName() << "!\n";
    cout << "Your age is " << person->getAge() << "\n";
    cout << "You were born in " << person->getPlaceOfBirth() << ".\n";
    cout << "Your balance is £" << person->getBalance() << ".\n";
    cout << "Your recent transactions are\n";
    for (string transaction : person->getTransactions()) {
        cout << "- " << transaction << "\n";
    }
}

int main() {
    while (true) {
        cout << "Please select a number for the option of:\n";
        cout << "1- Login\n";
        cout << "2- Register\n";
        cout << "3- Make a transaction\n";
        cout << "4- Exit\n";
        cout << "Option: ";
        int option;
        cin >> option;
        if (option == 1) {
            cout << "Enter name: ";
            string name;
            cin >> name;
            cout << "Enter password: ";
            string password;
            cin >> password;
            Person* person = authenticateUser(name, password);
            if (person != nullptr) {
                printUser(person);
            } else {
                cout << "Invalid name or password.\n";
            }
        } else if (option == 2) {
            cout << "Enter name: ";
            string name;
            cin >> name;
            cout << "Enter age: ";
            int age;
            cin >> age;
            cout << "Enter place of birth: ";
            string placeOfBirth;
            cin >> placeOfBirth;
            cout << "Enter password: ";
            string password;
            cin >> password;
            cout << "Enter initial balance: ";
            double balance;
            cin >> balance;
            cout << "Enter number of initial transactions: ";
            int numTransactions;
            cin >> numTransactions;
            vector<string> transactions;
            for (int i = 0; i < numTransactions; i++) {
                cout << "Enter transaction " << i + 1 << ": ";
                string transaction;
                cin >> transaction;
                transactions.push_back(transaction);
            }
            Person* person = new Person(name, age, placeOfBirth, password, balance, transactions);
            registerUser(person);
        } else if (option == 3) {
            cout << "Enter name: ";
            string name;
            cin >> name;
            cout << "Enter password: ";
            string password;
            cin >> password;
            Person* person = authenticateUser(name, password);
            if (person != nullptr) {
                cout << "Enter transaction: ";
                string transaction;
                cin >> transaction;
                makeTransaction(person, transaction);
            } else {
                cout << "Invalid name or password.\n";
            }
        } else if (option == 4) {
            break;
        }
    }
    return 0;
}
