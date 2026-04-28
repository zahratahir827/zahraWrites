#include <iostream>
#include <cstring>
using namespace std;

class Employee {
private:
    char name[30];
    double id;
    char gender[10];
    int age;

public:
    // ---------------- Default Constructor ----------------
    Employee() {
        strcpy(name, "Not Assigned");
        id = 0;
        strcpy(gender, "Not Set");
        age = 0;
    }

    // ---------------- Parameterized Constructor ----------------
    Employee(char n[], double i, char g[], int a) {
        strcpy(name, n);
        id = i;
        strcpy(gender, g);
        age = a;
    }

    // ---------------- Setters ----------------
    void setName(char n[]) {
        strcpy(name, n);
    }

    void setId(double i) {
        id = i;
    }

    void setGender(char g[]) {
        strcpy(gender, g);
    }

    void setAge(int a) {
        age = a;
    }

    // ---------------- Getters ----------------
    char* getName() {
        return name;
    }

    double getId() {
        return id;
    }

    char* getGender() {
        return gender;
    }

    int getAge() {
        return age;
    }

    // ---------------- Display Function ----------------
    void display() {
        cout << "\nEmployee Details:" << endl;
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Gender: " << gender << endl;
        cout << "Age: " << age << endl;
    }
};

// ---------------- MAIN FUNCTION ----------------
int main() {

    // Object using default constructor
    Employee e1;

    // Object using parameterized constructor
    char n[] = "Ali";
    char g[] = "Male";
    Employee e2(n, 101, g, 25);

    // Display default values
    cout << "Default / Initial Values:" << endl;
    e1.display();
    e2.display();

    // ---------------- Update values using setters ----------------
    char n1[] = "Insiyah";
    char g1[] = "Female";

    e1.setName(n1);
    e1.setId(202);
    e1.setGender(g1);
    e1.setAge(30);

    e2.setName("Ahmed");
    e2.setId(303);
    e2.setGender("Male");
    e2.setAge(35);

    // ---------------- Display updated values ----------------
    cout << "\nUpdated Values:" << endl;
    e1.display();
    e2.display();

    // ---------------- Using getters ----------------
    cout << "\nUsing Getters:" << endl;
    cout << "e1 Name: " << e1.getName() << endl;
    cout << "e2 Name: " << e2.getName() << endl;

    return 0;
}
