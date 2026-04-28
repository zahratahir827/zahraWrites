#include <iostream>
#include <cstring>
using namespace std;

class Book {
private:
    int id;
    char title[30];
    char author[30];
    bool isIssued;

public:
    // Constructor
    Book() {
        id = 0;
        strcpy(title, "Not Set");
        strcpy(author, "Not Set");
        isIssued = false;
    }

    // Add book details
    void addBook(int i, char t[], char a[]) {
        id = i;
        strcpy(title, t);
        strcpy(author, a);
        isIssued = false;
    }

    // Display book
    void display() {
        cout << "\nBook ID: " << id;
        cout << "\nTitle: " << title;
        cout << "\nAuthor: " << author;
        cout << "\nStatus: " << (isIssued ? "Issued" : "Available") << endl;
    }

    int getId() {
        return id;
    }

    // Issue book
    void issueBook() {
        if (!isIssued) {
            isIssued = true;
            cout << "Book Issued Successfully!\n";
        } else {
            cout << "Book already issued!\n";
        }
    }

    // Return book
    void returnBook() {
        if (isIssued) {
            isIssued = false;
            cout << "Book Returned Successfully!\n";
        } else {
            cout << "Book was not issued!\n";
        }
    }
};

// ---------------- MAIN FUNCTION ----------------
int main() {

    Book library[10];   // DSA: array of objects
    int count = 0;
    int choice;

    do {
        cout << "\n===== LIBRARY MENU =====";
        cout << "\n1. Add Book";
        cout << "\n2. Display Books";
        cout << "\n3. Search Book";
        cout << "\n4. Issue Book";
        cout << "\n5. Return Book";
        cout << "\n6. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        // ---------------- ADD BOOK ----------------
        if (choice == 1) {
            int id;
            char title[30], author[30];

            cout << "Enter Book ID: ";
            cin >> id;

            cout << "Enter Title: ";
            cin >> title;

            cout << "Enter Author: ";
            cin >> author;

            library[count].addBook(id, title, author);
            count++;

            cout << "Book Added Successfully!\n";
        }

        // ---------------- DISPLAY BOOKS ----------------
        else if (choice == 2) {
            for (int i = 0; i < count; i++) {
                library[i].display();
            }
        }

        // ---------------- SEARCH BOOK ----------------
        else if (choice == 3) {
            int id;
            cout << "Enter Book ID to search: ";
            cin >> id;

            bool found = false;

            for (int i = 0; i < count; i++) {
                if (library[i].getId() == id) {
                    library[i].display();
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "Book not found!\n";
            }
        }

        // ---------------- ISSUE BOOK ----------------
        else if (choice == 4) {
            int id;
            cout << "Enter Book ID to issue: ";
            cin >> id;

            for (int i = 0; i < count; i++) {
                if (library[i].getId() == id) {
                    library[i].issueBook();
                    break;
                }
            }
        }

        // ---------------- RETURN BOOK ----------------
        else if (choice == 5) {
            int id;
            cout << "Enter Book ID to return: ";
            cin >> id;

            for (int i = 0; i < count; i++) {
                if (library[i].getId() == id) {
                    library[i].returnBook();
                    break;
                }
            }
        }

    } while (choice != 6);

    return 0;
}
