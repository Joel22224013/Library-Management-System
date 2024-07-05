
#pragma once
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Book {
private:
    string author,title,isbn;
public:
    Book(string author, string title, string isbn) : author(author), title(title), isbn(isbn) {}
    //Constructor that initializes  the attributes

    //Public methods that return the attributes aka getters
    string getAuthor() const { return author; }
    string getTitle() const { return title; }
    string getIsbn() const { return isbn; }


    virtual void display() const {
        cout << "Book: " << title << " by " << author << ", ISBN: " << isbn << endl;
    }
};


//  This actually defines a subclass that inherits from the super class, Book.
class ReferenceBook : public Book {
public:
    ReferenceBook(const string& author, const string& title, const string& isbn) : Book(author, title, isbn) {}
    //Constructor that initializes a ReferenceBook using the Book constructor


// it can be overridden by derived class;it is called on.
    void display() const override {
        cout << "Reference Book: " << getTitle() << " by " << getAuthor() << ", ISBN: " << getIsbn() << endl;
    }
};

class FictionBook : public Book {
public:
    FictionBook(const string& author, const string& title, const string& isbn) : Book(author, title, isbn) {}
    void display() const override {
        cout << "Fiction Book: " << getTitle() << " by " << getAuthor() << ", ISBN: " << getIsbn() << endl;
    }
};

/*pragma once: This is a preprocessor directive that ensures the file is included
 * only once in a single compilation, preventing duplicate definitions.
 *include <string>: Includes the standard library for handling strings.
 The string header library helps us perform certain actions on strings
virtual ~Book() = default; constructs the compiler to generate a default destructor*/