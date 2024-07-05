
#pragma once
#include <string>


using namespace std;

class Member {
private:
    string name;
    int id;
public:
    Member(string name, int id) : name(name), id(id) {}

    string getName() const { return name; }
    int getId() const { return id; }

    virtual void borrowBook() = 0;
    virtual void returnBook() = 0;
};

//void because it does not have its implementation in the base class .