#include <iostream>
using namespace std;

int main() {

    int age = 0;
    int totalAge = 0;
    int averageAge = 0;

    // input ages of 10 students
    for (int i = 1; i <= 10; i++) {
        cout << "Please enter age of student " << i << ": ";
        cin >> age;

        totalAge = totalAge + age;
    }

    // calculate average
    averageAge = totalAge / 10;

    // display result
    cout << "\nAverage age of students is: " << averageAge << endl;

    return 0;
}
