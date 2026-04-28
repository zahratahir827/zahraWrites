#include <iostream>
using namespace std;

// ---------------- Faculty Class ----------------
class Faculty {
public:
    string name;
    int age;
    string post;

    // Function to decide post based on age
    void setPost() {
        if (age >= 25 && age <= 35)
            post = "Lecturer";
        else if (age >= 36 && age <= 45)
            post = "Assistant Professor";
        else if (age >= 46 && age <= 60)
            post = "Professor";
        else
            post = "Not Eligible";
    }
};

// ---------------- Node Class ----------------
class Node {
public:
    Faculty data;
    Node* next;

    Node(Faculty f) {
        data = f;
        next = NULL;
    }
};

// ---------------- Linked List Class ----------------
class List {
private:
    Node* head;

public:
    List() {
        head = NULL;
    }

    // Insert at end
    void insert(Faculty f) {
        Node* newNode = new Node(f);

        if (head == NULL) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Display list
    void display() {
        Node* temp = head;

        cout << "\nFaculty List:\n";
        cout << "--------------------------\n";

        while (temp != NULL) {
            cout << "Name: " << temp->data.name << endl;
            cout << "Age: " << temp->data.age << endl;
            cout << "Post: " << temp->data.post << endl;
            cout << "--------------------------\n";
            temp = temp->next;
        }
    }
};

// ---------------- Main Function ----------------
int main() {
    List l;

    for (int i = 0; i < 5; i++) {
        Faculty f;

        cout << "Enter name of faculty " << i + 1 << ": ";
        cin >> f.name;

        cout << "Enter age: ";
        cin >> f.age;

        // Decide post
        f.setPost();

        // Insert into linked list
        l.insert(f);
    }

    // Display all data
    l.display();

    return 0;
}
