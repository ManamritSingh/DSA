// finding max and min ina single go

#include <iostream>
using namespace std;

class maxmin
{
private:
    int *A;
    int length;
    int size;

public:
    maxmin(int sz);
    void create();
    void display();
    void findpair();
    ~maxmin();
};

maxmin::maxmin(int sz)
{
    size = sz;
    A = new int[sz];
}

void maxmin::create()
{

    cout << "Enter length" << endl;
    cin >> length;
    cout << "enter Array" << endl;
    for (int i = 0; i < length; i++)
    {
        cin >> A[i];
    }
}

void maxmin::display()
{

    cout << "latest array is..." << endl;
    for (int i = 0; i < length; i++)
    {
        cout << A[i] << endl;
    }
}

void maxmin::findpair()
{
    int max = A[0] , min = A[0];
    for (int i = 0; i < length; i++)
    {
        if (A[i]<min)
        {
            min=A[i];
        }
        else if (A[i]>max)
        {
            max=A[i];
        }   
    }
     cout<<"Min : "<<min<<endl;
     cout<<"Max : "<<max<<endl; 
}

maxmin::~maxmin()
{
    delete[] A;
}

int main()
{

    maxmin arr(20);
    arr.create();
    arr.display();
    arr.findpair();

    return 0;
}