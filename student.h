
#pragma once
#include "Member.h"
#include <iostream>

class Student : public Member {
public:
    Student(string name, int id) : Member(name, id) {}
    void borrowBook() override {
        // modified version of the super class
        cout << getName() << " is borrowing a book." << endl;
    }
    void returnBook() override {
        cout << getName() << " is returning a book." << endl;
    }
};