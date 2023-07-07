// insert in a sorted array

#include<iostream>
using namespace std;

class sortedarray
{
private:
    int *A;
    int size;
    int length;
public:
    sortedarray(int sze);
    void create();
    void display();
    void insert(int x);
    ~sortedarray();
};

sortedarray::sortedarray(int sze)
{
    size = sze;
    A = new int[sze];
}

void sortedarray::create(){

    cout<<"Enter length"<<endl;
    cin>>length;
    cout<<"enter Array"<<endl;
    for (int i = 0; i < length; i++)
    {
        cin>>A[i];
    }  
}

void sortedarray::display(){

    cout<<"latest array is..."<<endl;
    for (int i = 0; i < length; i++)
    {
        cout<<A[i]<<endl;
    } 
}

void sortedarray::insert(int x){

    cout<<"inserting . . ."<<endl;
    int i = length-1;
    while (A[i]>x)
    {
        A[i+1]=A[i];
        i--;
    }
    A[i+1]=x;
    length++;
}


sortedarray::~sortedarray()
{
    delete []A;
    cout<<"Destruction whoshh!!!!! "<<endl;
}


int main(){

    sortedarray ele(10);
    ele.create();
    ele.display();
    ele.insert(4);
    ele.display();
    
    return 0;
}