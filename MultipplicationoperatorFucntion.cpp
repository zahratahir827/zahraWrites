#include<iostream>
using namespace std;

class Matrix
{
private:
    int **A;
    int x, y;

public:
    Matrix();              // default constructor
    Matrix(int, int);     // parameterized constructor
    void read();
    void input();
    void display();
    Matrix operator * (int d) const;
};

// ---------------- OPERATOR OVERLOADING ----------------
Matrix Matrix :: operator * (int d) const
{
    Matrix temp(x, y);   // create same size matrix

    // allocate memory for temp
    temp.A = new int*[x];
    for (int i = 0; i < x; i++)
        temp.A[i] = new int[y];

    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            temp.A[i][j] = A[i][j] * d;
        }
    }

    return temp;
}

// ---------------- CONSTRUCTORS ----------------
Matrix :: Matrix()
{
    x = 0;
    y = 0;
    A = NULL;
}

Matrix :: Matrix(int a, int b)
{
    x = a;
    y = b;
    A = NULL;
}

// ---------------- READ ----------------
void Matrix :: read()
{
    cout << "Enter number of rows: ";
    cin >> x;

    cout << "Enter number of columns: ";
    cin >> y;
}

// ---------------- INPUT ----------------
void Matrix :: input()
{
    A = new int *[x];

    for (int i = 0; i < x; i++)
        A[i] = new int[y];

    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> A[i][j];
        }
    }
}

// ---------------- DISPLAY ----------------
void Matrix :: display()
{
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
}

// ---------------- MAIN ----------------
int main()
{
    Matrix M1, M2;

    M1.read();
    M1.input();

    cout << "\nOriginal Matrix:\n";
    M1.display();

    M2 = M1 * 2;

    cout << "\nMatrix after multiplication by 2:\n";
    M2.display();

    return 0;
}
