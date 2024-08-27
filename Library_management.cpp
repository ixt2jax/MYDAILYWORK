#include<bits/stdc++.h>
#include<string>
#include <ctime>
using namespace std;


class Book {
public:
    string title;
    string author;
    string ISBN;
    bool isAvailable;


    Book(string t, string a, string i) {
        title = t;
        author = a;
        ISBN = i;
        isAvailable = true;
    }
};


class Borrower {
public:
    string name;
    string borrowerID;

    
    Borrower(string n, string id) {
        name = n;
        borrowerID = id;
    }
};


class Transaction {
public:
    string borrowerID;
    string ISBN;
    time_t checkoutTime;
    time_t returnTime;
    bool isReturned;

    Transaction(string bID, string isbn) {
        borrowerID = bID;
        ISBN = isbn;
        isReturned = false; 
        checkoutTime = time(nullptr);  
    }

    double calculateFine() {
        if (isReturned) {
            double daysOverdue = difftime(returnTime, checkoutTime) / (60 * 60 * 24);
            if (daysOverdue > 15) {  
                return (daysOverdue - 15) * 5.0;  // Fine is Rs.5 per day overdue
            }
        }
        return 0;
    }
};


class LibrarySystem {
private:
    vector<Book> books;
    vector<Borrower> borrowers;
    vector<Transaction> transactions;

public:

    void addBook(string title, string author, string ISBN) {
        books.push_back(Book(title, author, ISBN));
    }

    
    void addBorrower(string name, string borrowerID) {
        borrowers.push_back(Borrower(name, borrowerID));
    }

    
    string searchBook(string query) {
    for (auto& book : books) {
        if (book.title == query || book.author == query || book.ISBN == query) {
            return "Book Found - Title: " + book.title + ", Author: " + book.author + ", ISBN: " + book.ISBN + ", Available: " + (book.isAvailable ? "Yes" : "No") + "\n";
        }
    }
    return "Book not found!\n";
}


    void checkoutBook(string borrowerID, string ISBN) {
        for (auto& book : books) {
            if (book.ISBN == ISBN && book.isAvailable) {
                book.isAvailable = false;
                transactions.push_back(Transaction(borrowerID, ISBN));
                cout << "Book checked out successfully." << endl;
                return;
            }
        }
        cout << "Book not available for checkout." << endl;
    }

    
    void returnBook(string borrowerID, string ISBN) {
        for (auto& book : books) {
            if (book.ISBN == ISBN && !book.isAvailable) {
                book.isAvailable = true;

                
                for (auto& transaction : transactions) {
                    if (transaction.borrowerID == borrowerID && transaction.ISBN == ISBN && !transaction.isReturned) {
                        transaction.isReturned = true;
                        transaction.returnTime = time(nullptr);
                        cout << "Book returned successfully." << endl;
                        double fine = transaction.calculateFine();
                        if (fine > 0) {
                            cout << "Fine incurred: $" << fine << endl;
                        }
                        return;
                    }
                }
            }
        }
        cout << "Error in returning the book." << endl;
    }

    void displayBooks() {
        for (auto& book : books) {
            cout << "Title: " << book.title << ", Author: " << book.author << ", ISBN: " << book.ISBN << ", Available: " << (book.isAvailable ? "Yes" : "No") << endl;
        }
    }
};


int main() {
    LibrarySystem library;

    
    library.addBook("THE CATCHER IN THE RYE", "J.D.SALINGER", "123456789");
    library.addBook("TO KILL A MOCKINGBIRD", "HARPER LEE", "987654321");
    library.addBook("THE HOBBIT","J.R.R.Tolkien","11223344");
    library.addBook("WINGS OF FIRE","A.P.J.Abdul Kalam","111222333");
    library.addBook("RICH DAD POOR DAD","ROBERT KIYOSAKI","12341234");
    library.addBorrower("John ", "B001");

    int choice;
    do {
        cout << "\nLibrary Management System\n";
        cout << "1. Search Book\n";
        cout << "2. Checkout Book\n";
        cout << "3. Return Book\n";
        cout << "4. Display Books\n";
        cout << "5. Exit\n";
        cout << "Enter your choice no. : ";
        cin >> choice;

        
        string query, borrowerID, ISBN;
        switch (choice){
        case 1:
            cout << "Enter title, author, or ISBN to search: ";
            cin.ignore();  // Clear the newline character left in the input buffer
            getline(cin, query);
            transform(query.begin(), query.end(), query.begin(), ::toupper); 
            cout<<library.searchBook(query);
            break;
        case 2:
            cout << "Enter borrower ID: ";
            cin >> borrowerID;
            cout << "Enter ISBN of the book: ";
            cin >> ISBN;
            library.checkoutBook(borrowerID, ISBN);
            break;
        case 3:
            cout << "Enter borrower ID: ";
            cin >> borrowerID;
            cout << "Enter ISBN of the book: ";
            cin >> ISBN;
            library.returnBook(borrowerID, ISBN);
            break;
        case 4:
            library.displayBooks();
            break;
        case 5:
            cout << "Exiting system.\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
