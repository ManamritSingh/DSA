// this is the code for union , intersection and set subtraction

// this program rearranges an array's positive and negative elements on their respective sides

// insert in a sorted array

#include<iostream>
using namespace std;

class setops
{
private:
    int *A;
    int *B;
    int *c;
    int sizeA;
    int lengthA;
    int sizeB;
    int lengthB;
    int lengthc;
public:
    setops(int sze , int sz);
    void create();
    void display();
    void displayarray();
    void unionop();
    void intersecop();
    void subop();
    ~setops();
};

setops::setops(int sze , int sz)
{
    sizeA = sze;
    A = new int[sze];

    sizeB = sz;
    B = new int[sz];

    c = new int[100];
}

void setops::create(){

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

void setops::display(){

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

void setops::unionop(){
    int i =0 , j=0 , k=0;

    while (i<lengthA && j<lengthB)
    {
        if (A[i]<B[j]) // it took me an hour to get this sign right *inserts crying emoji ;)*
        {
            c[k++]=A[i++];
        }
        else if(A[i]>B[j]){
            c[k++]=B[j++];
        }
        else{
            c[k++]=A[i++];
            j++;
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
    lengthc=k;
}

void setops::intersecop(){
    int i =0 , j=0 , k=0;

    while (i<lengthA && j<lengthB)
    {
        if (A[i]<B[j]) // it took me an hour to get this sign right *inserts crying emoji ;)*
        {
            i++;
        }
        else if(A[i]>B[j]){
            j++;
        }
        else if(A[i]==B[j]){
            c[k++]=A[i++];
            j++;
        }
    }
    lengthc=k;
}

void setops::subop(){
    int i =0 , j=0 , k=0;

    while (i<lengthA && j<lengthB)
    {
        if (A[i]<B[j]) // it took me an hour to get this sign right *inserts crying emoji ;)*
        {
            c[k++]=A[i++];
        }
        else if(A[i]>B[j]){
            j++;
        }
        else{
            i++;
            j++;
        }
    }
    for (; i < lengthA; i++)
    {
        c[k++]=A[i];
    }
    lengthc=k;
}

void setops:: displayarray(){
    cout<<"obtained array is..."<<endl;
    for (int i = 0; i < lengthc; i++)
    {
        cout<<c[i]<<endl;
    } 
}


setops::~setops()
{
    delete []A;
    cout<<"Destruction whoshh!!!!! "<<endl;
}


int main(){

    setops ele(10,10);
    ele.create();
    ele.display();
    ele.unionop();
    ele.displayarray();
    ele.intersecop();
    ele.displayarray();
    ele.subop();
    ele.displayarray();
    
    return 0;
}