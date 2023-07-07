#include<iostream>
using namespace std;

class shiftrotate
{
private:
    int *A;
    int size;
    int length;
public:
    shiftrotate(int sze);
    void create();
    void display();
    void shl();
    void shr();
    void rol();
    void ror();
    ~shiftrotate();
};

shiftrotate::shiftrotate(int sze)
{
    size = sze;
    A = new int[sze];
}

void shiftrotate::create(){

    cout<<"Enter length"<<endl;
    cin>>length;
    cout<<"enter Array"<<endl;
    for (int i = 0; i < length; i++)
    {
        cin>>A[i];
    }  
}

void shiftrotate::display(){

    cout<<"latest array is..."<<endl;
    for (int i = 0; i < length; i++)
    {
        cout<<A[i]<<" ";
    } 
    cout<<endl;
}

void shiftrotate::rol(){

    cout<<"left rotate"<<endl;

    int x=0;
    x=A[0];
    for (int i = 0; i < length; i++)
    {
        A[i]=A[i+1];
    }
    A[length-1]=x;
    
}

void shiftrotate::ror(){

    cout<<"right rotate"<<endl;

    int x=0;
    x=A[length-1];
    for (int i = length-1; i >=0; i--)
    {
        A[i]=A[i-1];
    }
    A[0]=x;
    
}

void shiftrotate::shr(){

    cout<<"right shift"<<endl;

    int x=0;
    for (int i = length-1; i >= 0; i--)
    {
        A[i]=A[i-1];
    }
    A[0]=x;
    
}

void shiftrotate::shl(){

    cout<<"left shift"<<endl;

    int x=0;
    for (int i = 0; i < length; i++)
    {
        A[i]=A[i+1];
    }
    A[length-1]=x;
    
}


shiftrotate::~shiftrotate()
{
    delete []A;
    cout<<"Destruction whoshh!!!!! "<<endl;
}


int main(){

    shiftrotate ele(10);
    ele.create();
    ele.display();
    ele.shl();
    ele.display();
    ele.rol();
    ele.display();
    ele.ror();
    ele.display();
    ele.shr();
    ele.display();
    
    return 0;
}