// code for find multiple missing elements in a sorted array

#include<iostream>
using namespace std;

class missingelement
{
private:
    int *A;
    int length;
    int size;
public:
    missingelement(int sz);
    void create();
    void display();
    void findele();
    ~missingelement();
};

missingelement::missingelement(int sz)
{
    size = sz;
    A = new int [sz];
}

void missingelement::create(){

    cout<<"Enter length"<<endl;
    cin>>length;
    cout<<"enter Array"<<endl;
    for (int i = 0; i < length; i++)
    {
        cin>>A[i];
    }  
}

void missingelement::display(){

    cout<<"latest array is..."<<endl;
    for (int i = 0; i < length; i++)
    {
        cout<<A[i]<<endl;
    } 
}

void missingelement::findele(){

    int diff = A[0]-0;

    for (int i = 0; i < length; i++)
    {
        if (A[i]-i!=diff)
        {
            while (diff<A[i]-i)
            {
                cout<<"missing : "<<i+diff<<endl;
                diff++;
            }
            
        }
        
    }

}

missingelement::~missingelement()
{
    delete[]A;
}


int main(){

    missingelement arr(10);
    arr.create();
    arr.display();
    arr.findele();
    
    return 0;
}