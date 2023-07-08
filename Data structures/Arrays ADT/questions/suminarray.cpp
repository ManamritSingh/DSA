// find pair of elements whose sum equals k

#include <iostream>
using namespace std;

class sumpair
{
private:
    int *A;
    int length;
    int size;

public:
    sumpair(int sz);
    void create();
    void display();
    void findpair(int sum);
    ~sumpair();
};

sumpair::sumpair(int sz)
{
    size = sz;
    A = new int[sz];
}

void sumpair::create()
{

    cout << "Enter length" << endl;
    cin >> length;
    cout << "enter Array" << endl;
    for (int i = 0; i < length; i++)
    {
        cin >> A[i];
    }
}

void sumpair::display()
{

    cout << "latest array is..." << endl;
    for (int i = 0; i < length; i++)
    {
        cout << A[i] << endl;
    }
}

void sumpair::findpair(int sum)
{
    int s = sum;

    for (int i = 0; i < length-1; i++)
    {
        for (int j= i+1 ; j < length; j++)
        {
            if (A[i]+A[j]==s)
            {
                cout<<A[i]<<"+"<<A[j]<<"="<<s<<endl;
            }
            
        }
        
    }
    
}

sumpair::~sumpair()
{
    delete[] A;
}

int main()
{

    sumpair arr(20);
    arr.create();
    arr.display();
    arr.findpair(10);

    return 0;
}