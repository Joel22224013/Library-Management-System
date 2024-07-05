
#pragma once
#include "Book.h"
#include <vector>
#include <unordered_map>
using namespace std;

class Library {
private:
    vector<Book*> books;
    unordered_map<string, bool> borrowedBooks;
public:
    ~Library() {
        for (auto book : books) {
            delete book;
        }
    }
    void addBook(Book* book) {
        books.push_back(book);
        borrowedBooks[book->getIsbn()] = false;
    }
    vector<Book*> findBooksByAuthor(string author) {
        vector<Book*> result;
        for (const auto& book : books) {
            if (book->getAuthor() == author) {
                result.push_back(book);
            }
        }
        return result;
    }
    bool isBookAvailable(string isbn) {
        return borrowedBooks.find(isbn) != borrowedBooks.end() && !borrowedBooks[isbn];
    }
    void borrowBook(string isbn) {
        if (isBookAvailable(isbn)) {
            borrowedBooks[isbn] = true;
            cout << "Book with ISBN " << isbn << " has been borrowed." << endl;
        } else {
            cout << "Book with ISBN " << isbn << " is not available." << endl;
        }
    }
    void returnBook(string isbn) {
        if (borrowedBooks.find(isbn) != borrowedBooks.end() && borrowedBooks[isbn]) {
            borrowedBooks[isbn] = false;
            cout << "Book with ISBN " << isbn << " has been returned." << endl;
        } else {
            cout << "Book with ISBN " << isbn << " was not borrowed." << endl;
        }
    }
    void displayAllBooks() const {
        for (const auto& book : books) {
            book->display();
        }
    }
};