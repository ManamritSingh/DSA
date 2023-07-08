// although not recommended method but still

#include <iostream>
using namespace std;

class duplicates
{
private:
    int *A;
    int length;
    int size;

public:
    duplicates(int sz);
    void create();
    void display();
    void finduplicate();
    ~duplicates();
};

duplicates::duplicates(int sz)
{
    size = sz;
    A = new int[sz];
}

void duplicates::create()
{

    cout << "Enter length" << endl;
    cin >> length;
    cout << "enter Array" << endl;
    for (int i = 0; i < length; i++)
    {
        cin >> A[i];
    }
}

void duplicates::display()
{

    cout << "latest array is..." << endl;
    for (int i = 0; i < length; i++)
    {
        cout << A[i] << endl;
    }
}

void duplicates::finduplicate()
{

    for (int i = 0; i < length - 2; i++)
    {
        int count = 1;
        if (A[i] != -1)
        {
            for (int j = i + 1; j < length; j++)
            {
                if (A[i] == A[j])
                {
                    count++;
                    A[j] = -1;
                }
            }
            if (count > 1)
            {
                cout << A[i] << " has " << count << " duplicates" << endl;
            }
        }
    }
}

duplicates::~duplicates()
{
    delete[] A;
}

int main()
{

    duplicates arr(20);
    arr.create();
    arr.display();
    arr.finduplicate();

    return 0;
}