
#include <iostream>

#include <string>
#include "Book.h"
#include "student.h"
#include "Library.h"
#include "Librarian.h"

using namespace std;

void displayMenu() {
    cout << "\nLibrary Management System" << endl;
    cout << "1. Display all books" << endl;
    cout << "2. Borrow a book" << endl;
    cout << "3. Return a book" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice: ";
}

int main() {
    // Create Library
    Library library;

    // Add Books
    Book* refBook = new ReferenceBook("Eugene Joel", "Lists of giants", "ISBN001");
    Book* ficBook = new FictionBook("Benny Hinn", "The angelic visitation", "ISBN002");
    library.addBook(refBook);
    library.addBook(ficBook);

    // Display all books initially
    cout << "Initial Library books:" << endl;
    library.displayAllBooks();

    // Create Librarian
    Librarian librarian("Jerry", "Christ123");


    // Librarian Authentication
    string inputPassword;
    cout << "Enter librarian password: ";
    cin >> inputPassword;
    if (!librarian.authenticate(inputPassword)) {
        cout << "Authentication failed. Exiting the system." << endl;
        return 1;
    }

    cout << "Librarian authenticated." << endl;

    // Create Student
    Student student("Collins Hooks", 22233318);
    cout<<"What is your student ID:";

    int choice;
    while (true) {
        displayMenu();
        cin >> choice;

        if (choice == 4) {
            cout << "Exiting the system." << endl;
            break;
        }

        string isbn;
        switch (choice) {
            case 1:
                cout << "\nLibrary books:" << endl;
                library.displayAllBooks();
                break;
            case 2:
                cout << "Enter ISBN of the book to borrow: ";
                cin >> isbn;
                if (library.isBookAvailable(isbn)) {
                    student.borrowBook();
                    library.borrowBook(isbn);
                } else {
                    cout << "The book is not available." << endl;
                }
                break;
            case 3:
                cout << "Enter ISBN of the book to return: ";
                cin >> isbn;
                student.returnBook();
                library.returnBook(isbn);
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}