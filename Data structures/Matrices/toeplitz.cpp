// code for toeplitz matrix
// all elements are covered by we store only 1 row and 1 column
// total 2n-1 elements stored

// upper and lower triangular matrices made

// case 1 upper i<=j ------- j-1
// case 2 lower i>j -------- n+i-j-1

#include <iostream>
using namespace std;

class tpltz
{
private:
    int *A;
    int n;

public:
    tpltz(int n);
    void create();
    void get(int i, int j);
    void set(int i, int j, int x);
    void display();
    ~tpltz();
};

tpltz::tpltz(int n)
{
    this->n = n;
    A = new int[2 * n - 1];
}

void tpltz::create()
{
    cout << "Enter elements for top row followed by first column:" << endl;
    int x;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if(i==1 || j==1){
                cin >> x;
                if (i<=j)
                {
                    A[j-1] = x;
                }
                else if (i>j)
                {
                    A[n+i-j-1] = x;
                }
            }
        }
    }
}

void tpltz::display()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i <= j)
            {
                cout << A[j - i] << " ";
            }
            else
            {
                cout << A[n + i - j - 1] << " ";
            }
        }

        cout << endl;
    }
    cout << endl;
}

void tpltz::set(int i, int j, int x)
{
    if (i==1 || j==1)
            {
                if (i<=j)
                {
                    A[j-1] = x;
                }
                else if (i>j)
                {
                    A[n+i-j-1] = x;
                }
            }
}

void tpltz::get(int i, int j)
{
    if (i==1 || j==1)
            {
                if (i<=j)
                {
                    cout<<"element is"<<A[j-1];
                }
                else if (i>j)
                {
                    cout<<"element is"<<A[n+i-j-1];
                }
        }
}

tpltz::~tpltz()
{
    delete[] A;
}

int main()
{
    tpltz ele(5);
    ele.create();
    
    ele.display();
    ele.set(1, 2, 9); // if we change a first row or colummn element , the entire diagonal gets replaced
    ele.display();
    ele.get(2, 3);

    return 0;
}
