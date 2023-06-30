#include<iostream>
using namespace std;

class Darray
{
private:
    int length;
    int size;
    int *A;
public:
    //array(int size);
    //void create();
    //void display();
    //~array();


//Darray::
Darray(int size)
{
    this->size= size;
    A = new int[size];
}

//void Darray::
void create(){
    cout<<"Enter length of elements"<<endl;
    cin>>length;

    cout<<"Enter Array"<<endl;
    for(int i = 0 ; i<length;i++){
        cin>>A[i];
    }
}

//void Darray::
void display(){

    cout<<"displaying the array"<<endl;
    for (int i = 0; i < length; i++)
    {
        cout<<A[i]<<" ";
    }
    
}

//Darray::
~Darray()
{
    delete []A;
}
};

int main(){
    Darray arr(10);
    arr.create();
    arr.display();
    
    return 0;
}