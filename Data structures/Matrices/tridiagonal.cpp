// code for tridiagonal matrix
// 3 diagonals basically
// 3n-2 elements
// i==j , |i-j|<1 necesary conditions
// to find element formulas are
// i-j =1 ---   i-1
// i==j --- n-1 + i-1
// i-j=-1 ---- 2n-1 + i-1

#include <iostream>
using namespace std;

class tridiognal
{
private:
    int *A;
    int n;

public:
    tridiognal(int n);
    void create();
    void get(int i, int j);
    void set(int i, int j, int x);
    void display();
    ~tridiognal();
};

tridiognal::tridiognal(int n)
{
    this->n = n;
    A = new int[3 * n - 2];
}

void tridiognal::create()
{

    cout << "Enter elements for upeer diagonal followed by mid and lower" << endl;
    int x;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (abs(i - j) < 1)
            {
                cin >> x;
                if ((i - j) == 1)
                {
                    A[i - 1] = x;
                }
                else if (i == j)
                {
                    A[n - 1 + i - 1] = x;
                }
                else if ((i - j) == -1)
                {
                    A[2 * n - 1 + i - 1] = x;
                }
            }
        }
    }
}

void tridiognal::display()
{

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (abs(i - j) <= 1)
            {
                if ((i - j) == 1)
                {
                    cout << A[i - 1] << " ";
                }
                else if (i == j)
                {
                    cout << A[n - 1 + i - 1] << " ";
                }
                else if ((i - j) == -1)
                {
                    cout << A[2 * n - 1 + i - 1] << " ";
                }
            }

            else if (abs(i - j) > 1)
            {
                cout << "0 ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

void tridiognal::set(int i, int j, int x)
{

    if ((i - j) == 1)
    {
        A[i - 1] = x;
    }
    else if (i == j)
    {
        A[n - 1 + i - 1] = x;
    }
    else if ((i - j) == -1)
    {
        A[2 * n - 1 + i - 1] = x;
    }
}

void tridiognal::get(int i, int j)
{

    cout << "The retrieved element is: " << A[(j * (j - 1) / 2) + (i - 1)] << endl;

    if (abs(i - j) <= 1)
    {
        if ((i - j) == 1)
        {
            cout << "The retrieved element is: " << A[i - 1] << endl;
        }
        else if (i == j)
        {
            cout << "The retrieved element is: " << A[n - 1 + i - 1] << endl;
        }
        else if ((i - j) == -1)
        {
            cout << "The retrieved element is: " << A[2 * n - 1 + i - 1] << endl;
        }
    }
}

tridiognal::~tridiognal()
{
    delete[] A;
}

int main()
{

    tridiognal ele(5);
    ele.create();
    ele.display();
    ele.set(1, 2, 9);
    ele.display();
    ele.get(2, 3);

    return 0;
}