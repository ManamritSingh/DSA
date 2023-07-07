// this program rearranges an array's positive and negative elements on their respective sides

// insert in a sorted array

#include<iostream>
using namespace std;

class mergearray
{
private:
    int *A;
    int*B;
    int *c;
    int sizeA;
    int lengthA;
    int sizeB;
    int lengthB;
    int lengthc;
public:
    mergearray(int sze , int sz);
    void create();
    void display();
    void displayarray();
    void merge();
    ~mergearray();
};

mergearray::mergearray(int sze , int sz)
{
    sizeA = sze;
    A = new int[sze];

    sizeB = sz;
    B = new int[sz];

    c = new int[100];
}

void mergearray::create(){

    cout<<"Enter length of A"<<endl;
    cin>>lengthA;
    cout<<"enter Array A"<<endl;
    for (int i = 0; i < lengthA; i++)
    {
        cin>>A[i];
    } 

    cout<<"Enter length of B"<<endl;
    cin>>lengthB;
    cout<<"enter Array B"<<endl;
    for (int i = 0; i < lengthB; i++)
    {
        cin>>B[i];
    }   
}

void mergearray::display(){

    cout<<"latest array A is..."<<endl;
    for (int i = 0; i < lengthA; i++)
    {
        cout<<A[i]<<endl;
    } 

    cout<<"latest array B is..."<<endl;
    for (int i = 0; i < lengthB; i++)
    {
        cout<<B[i]<<endl;
    } 
}

void mergearray::merge(){
    int i =0 , j=0 , k=0;

    while (i<lengthA && j<lengthB)
    {
        if (A[i]<B[j]) // it took me an hour to get this sign right *inserts crying emoji ;)*
        {
            c[k++]=A[i++];
        }
        else{
            c[k++]=B[j++];
        }
    }
    for (; i < lengthA; i++)
    {
        c[k++]=A[i];
    }
    for (; j < lengthB; j++)
    {
        c[k++]=B[j];
    }
    lengthc=lengthA+lengthB;
}

void mergearray:: displayarray(){
    cout<<"merged array is..."<<endl;
    for (int i = 0; i < lengthc; i++)
    {
        cout<<c[i]<<endl;
    } 
}


mergearray::~mergearray()
{
    delete []A;
    cout<<"Destruction whoshh!!!!! "<<endl;
}


int main(){

    mergearray ele(10,10);
    ele.create();
    ele.display();
    ele.merge();
    ele.displayarray();
    
    return 0;
}