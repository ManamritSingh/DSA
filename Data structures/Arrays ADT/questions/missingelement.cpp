// this is the code for finding the missing element in a sorted continous array

// of course we can use good old n(n+1)/2 and subtract the sum from it but we have another better method that will be handy at any index

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
        if (A[i]-i==diff)
        {
            i++;
        }
        else{
            cout<<"missing element is "<<(i-1)+diff<<endl;
            break;
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