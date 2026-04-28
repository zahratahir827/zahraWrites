#include <iostream>
using namespace std;

// ---------------- NODE CLASS ----------------
class Node {
private:
    int object;
    Node* nextNode;

public:
    int get() {
        return object;
    }

    void set(int object) {
        this->object = object;
    }

    Node* getNext() {
        return nextNode;
    }

    void setNext(Node* nextNode) {
        this->nextNode = nextNode;
    }
};

// ---------------- QUEUE CLASS ----------------
class Queue {
public:
    Node* front;
    Node* rear;

    Queue() {
        front = NULL;
        rear = NULL;
    }

    int isEmpty() {
        return front == NULL;
    }

    // Enqueue only EVEN numbers
    void enqueue(int x) {
        if (x % 2 != 0) {
            cout << x << " is not even, not added to queue.\n";
            return;
        }

        Node* newNode = new Node();
        newNode->set(x);
        newNode->setNext(NULL);

        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->setNext(newNode);
            rear = newNode;
        }
    }

    // Remove front element
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is Empty!\n";
            return -1;
        }

        Node* temp = front;
        int value = temp->get();

        front = front->getNext();

        if (front == NULL) {
            rear = NULL;
        }

        delete temp;
        return value;
    }

    // Display without removing
    void display() {
        if (isEmpty()) {
            cout << "Queue is Empty!\n";
            return;
        }

        cout << "\nQueue elements: ";
        Node* temp = front;

        while (temp != NULL) {
            cout << temp->get() << " ";
            temp = temp->getNext();
        }
        cout << endl;
    }
};

// ---------------- MAIN FUNCTION ----------------
int main() {

    Queue q;
    int n;

    cout << "Enter numbers for queue (-1 to stop):\n";

    while (true) {
        cin >> n;
        if (n == -1)
            break;

        q.enqueue(n);
    }

    // Display queue
    q.display();

    // Delete first even element
    cout << "\nDeleting first element...\n";
    q.dequeue();

    // Display remaining queue
    q.display();

    return 0;
}
