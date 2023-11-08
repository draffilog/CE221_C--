#include <string>
#include <vector>

class Person {
private:
    std::string name;
    int age;
    std::string placeOfBirth;
    std::string password;
    double balance;
    std::vector<std::string> transactions;

public:
    Person(std::string name, int age, std::string placeOfBirth, std::string password, double balance, std::vector<std::string> transactions);
    std::string getName();
    int getAge();
    std::string getPlaceOfBirth();
    std::string getPassword();
    double getBalance();
    std::vector<std::string> getTransactions();
    void setName(std::string name);
    void setAge(int age);
    void setPlaceOfBirth(std::string placeOfBirth);
    void setPassword(std::string password);
    void setBalance(double balance);
    void setTransactions(std::vector<std::string> transactions);
    void addTransaction(std::string transaction);
};
