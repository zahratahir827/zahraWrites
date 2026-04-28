#include <iostream>
#include <cstring>
using namespace std;

class BankAccount {
private:
    int accNo;
    char name[30];
    float balance;

public:
    // Constructor
    BankAccount() {
        accNo = 0;
        strcpy(name, "Not Set");
        balance = 0;
    }

    // Set account details
    void createAccount(int a, char n[], float b) {
        accNo = a;
        strcpy(name, n);
        balance = b;
    }

    // Deposit
    void deposit(float amount) {
        balance += amount;
        cout << "Amount Deposited Successfully!\n";
    }

    // Withdraw
    void withdraw(float amount) {
        if (amount <= balance) {
            balance -= amount;
            cout << "Withdrawal Successful!\n";
        } else {
            cout << "Insufficient Balance!\n";
        }
    }

    // Display
    void display() {
        cout << "\nAccount No: " << accNo;
        cout << "\nName: " << name;
        cout << "\nBalance: " << balance << endl;
    }

    int getAccNo() {
        return accNo;
    }
};

// ---------------- MAIN PROGRAM ----------------
int main() {

    BankAccount customers[5]; // DSA concept: array of objects

    int count = 0;
    int choice;

    do {
        cout << "\n===== BANK MENU =====";
        cout << "\n1. Create Account";
        cout << "\n2. Deposit";
        cout << "\n3. Withdraw";
        cout << "\n4. Display Account";
        cout << "\n5. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        if (choice == 1) {
            int acc;
            char name[30];
            float bal;

            cout << "Enter Account No: ";
            cin >> acc;

            cout << "Enter Name: ";
            cin >> name;

            cout << "Enter Initial Balance: ";
            cin >> bal;

            customers[count].createAccount(acc, name, bal);
            count++;

        }

        else if (choice == 2) {
            int acc;
            float amt;

            cout << "Enter Account No: ";
            cin >> acc;

            cout << "Enter Amount to Deposit: ";
            cin >> amt;

            for (int i = 0; i < count; i++) {
                if (customers[i].getAccNo() == acc) {
                    customers[i].deposit(amt);
                }
            }
        }

        else if (choice == 3) {
            int acc;
            float amt;

            cout << "Enter Account No: ";
            cin >> acc;

            cout << "Enter Amount to Withdraw: ";
            cin >> amt;

            for (int i = 0; i < count; i++) {
                if (customers[i].getAccNo() == acc) {
                    customers[i].withdraw(amt);
                }
            }
        }

        else if (choice == 4) {
            int acc;

            cout << "Enter Account No: ";
            cin >> acc;

            for (int i = 0; i < count; i++) {
                if (customers[i].getAccNo() == acc) {
                    customers[i].display();
                }
            }
        }

    } while (choice != 5);

    return 0;
}
