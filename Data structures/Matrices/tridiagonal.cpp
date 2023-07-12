// code for tridiagonal matrix
// 3 diagonals basically
// 3n-2 elements
// i==j , |i-j|<1 necesary conditions
// to find element formulas are
// i-j =1 ---   i-1
// i==j --- n-1 + i-1
// i-j=-1 ---- 2n-1 + i-1

// chatgpt changes

#include <iostream>
using namespace std;

class tridiagonal
{
private:
    int *A;
    int n;

public:
    tridiagonal(int n);
    void create();
    void get(int i, int j);
    void set(int i, int j, int x);
    void display();
    ~tridiagonal();
};

tridiagonal::tridiagonal(int n)
{
    this->n = n;
    A = new int[3 * n - 2];
}

void tridiagonal::create()
{
    cout << "Enter elements for the upper diagonal, mid diagonal, and lower diagonal:" << endl;
    int x;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (abs(i - j) <= 1)
            {
                cin >> x;
                if (i - j == 1)
                {
                    A[i - 2] = x;
                }
                else if (i == j)
                {
                    A[n - 1 + i - 1] = x;
                }
                else if (i - j == -1)
                {
                    A[2 * n - 1 + i - 1] = x;
                }
            }
        }
    }
}

void tridiagonal::display()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (abs(i - j) <= 1)
            {
                if (i - j == 1)
                {
                    cout << A[i - 2] << " ";
                }
                else if (i == j)
                {
                    cout << A[n - 1 + i - 1] << " ";
                }
                else if (i - j == -1)
                {
                    cout << A[2 * n - 1 + i - 1] << " ";
                }
            }
            else
            {
                cout << "0 ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

void tridiagonal::set(int i, int j, int x)
{
    if (i - j == 1)
    {
        A[i - 2] = x;
    }
    else if (i == j)
    {
        A[n - 1 + i - 1] = x;
    }
    else if (i - j == -1)
    {
        A[2 * n - 1 + i - 1] = x;
    }
}

void tridiagonal::get(int i, int j)
{
    if (abs(i - j) <= 1)
    {
        if (i - j == 1)
        {
            cout << "The retrieved element is: " << A[i - 2] << endl;
        }
        else if (i == j)
        {
            cout << "The retrieved element is: " << A[n - 1 + i - 1] << endl;
        }
        else if (i - j == -1)
        {
            cout << "The retrieved element is: " << A[2 * n - 1 + i - 1] << endl;
        }
    }
    else
    {
        cout << "The retrieved element is: 0" << endl;
    }
}

tridiagonal::~tridiagonal()
{
    delete[] A;
}

int main()
{
    tridiagonal ele(5);
    ele.create();
    ele.display();
    ele.set(1, 2, 9);
    ele.display();
    ele.get(2, 3);

    return 0;
}
