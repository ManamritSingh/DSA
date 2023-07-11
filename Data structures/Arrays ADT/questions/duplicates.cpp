// finding duplicate elemnts

#include<iostream>
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
    A = new int [sz];
}

void duplicates::create(){

    cout<<"Enter length"<<endl;
    cin>>length;
    cout<<"enter Array"<<endl;
    for (int i = 0; i < length; i++)
    {
        cin>>A[i];
    }  
}

void duplicates::display(){

    cout<<"latest array is..."<<endl;
    for (int i = 0; i < length; i++)
    {
        cout<<A[i]<<endl;
    } 
}

void duplicates::finduplicate(){

    int currentDupli =0;

    for (int i = 0; i < length-1; i++)
    {
        if (A[i]==A[i+1])
        {
            currentDupli = A[i];
            int j = i+1;
            while (A[j]==A[i])
            {
                j++;
            }
            cout<<A[i]<<" is occuring "<<j-i<<" times"<<endl;
        }
        
    }
    

}

duplicates::~duplicates()
{
    delete[]A;
}


int main(){

    duplicates arr(10);
    arr.create();
    arr.display();
    arr.finduplicate();
    
    return 0;
}