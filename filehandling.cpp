#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

ofstream outfile;   // global file object

class String {
private:
    char txt[20];

public:
    // default constructor
    String() {
        strcpy(txt, "");
    }

    // friend functions for stream operators
    friend istream& operator >> (istream &input, String &s);
    friend ostream& operator << (ostream &output, const String &s);

    // + operator overloading for concatenation
    String operator + (const String &s1) {

        outfile.open("Sample.txt", ios::app);

        String temp;

        strcpy(temp.txt, txt);
        strcat(temp.txt, s1.txt);

        outfile << temp.txt << endl;

        outfile.close();

        return temp;
    }
};

// ---------------- extraction operator >> ----------------
istream& operator >> (istream &in, String &s) {

    outfile.open("Sample.txt", ios::app);

    in.getline(s.txt, 20);

    outfile << s.txt << endl;

    outfile.close();

    return in;
}

// ---------------- insertion operator << ----------------
ostream& operator << (ostream &out, const String &s) {

    out << s.txt;
    return out;
}

// ---------------- MAIN FUNCTION ----------------
int main() {

    String s1, s2, s3;

    cout << "Enter First Name: ";
    cin >> s1;

    cout << "Enter Last Name: ";
    cin >> s2;

    s3 = s1 + s2;

    cout << "\nFull Name: " << s3 << endl;

    return 0;
}
