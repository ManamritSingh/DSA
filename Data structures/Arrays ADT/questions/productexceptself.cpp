#include<iostream>
using namespace std;

class productexceptself
{
private:
    int *A;
    int *B;
    int *C;
    int lengthA;
    int lengthB;
    int lengthC;
    int sizeA;
    int sizeB;
    int sizeC;
public:
    productexceptself(int sz);
    void create();
    void display(int *A);
    int product(int *A);
    void resultArray();
    ~productexceptself();
};

void productexceptself::create(){

    cout<<"Enter lengthA"<<endl;
    cin>>lengthA;
    cout<<"enter Array"<<endl;
    for (int i = 0; i < lengthA; i++)
    {
        cin>>A[i];
    }  
}

void productexceptself::display(int *A){

    cout<<"latest array is..."<<endl;
    for (int i = 0; i < lengthA; i++)
    {
        cout<<A[i]<<endl;
    } 
}

productexceptself::productexceptself(int sz)
{
    sizeA = sz;
    A = new int [sz];
}
int productexceptself::product(int *A){
    int P=1;

    for (int i = 0; i < lengthB; i++)
    {
        P = P*B[i];
    }
    return P;
} 


void productexceptself::resultArray(){

lengthB=lengthA;
    B = new int [lengthB];
    for (int i = 0; i < lengthA; i++)
    {
        B[i]=A[i];
    }
    lengthC=lengthA;
    C = new int [lengthC];
    int x = 0;
    
    for (int i = 0; i < lengthB; i++)
    {
        x = B[i];
        B[i]=1;
        C[i]=product(B);
        B[i]=x;
    }
    cout<<"Resultant array :";
    display(C);
}

productexceptself::~productexceptself()
{
    delete []A;
}


int main(){

    productexceptself ele(10);
    ele.create();
    ele.resultArray();
    
    return 0;
}