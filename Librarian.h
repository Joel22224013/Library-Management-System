
#pragma once
#include <string>
#include <iostream>
using namespace std;

class Librarian {
private:
    string name;
    string password;
public:
    Librarian(string name, string password) : name(name), password(password) {}
    string getName() const { return name; }
    bool authenticate(string inputPassword) {
        return inputPassword == password;
    }
    static void manageBorrowing() {
        cout << "Managing borrowing of books." << endl;
    }
    static void manageReturning() {
        cout << "Managing returning of books." << endl;
    }
};