// this code solves the sum problem using a hash table

#include<iostream>
using namespace std;

class sumfind
{
private:
    int *A;
    int lengthA;
    int sizeA;

    int *H;
    int lengthH;
    int sizeH;
public:
    sumfind(int sz);
    void create();
    void display();
    int max();
    void findpair(int s);
    ~sumfind();
};

sumfind::sumfind(int sz)
{
    sizeA = sz;
    A = new int [sz];
}

void sumfind::create(){

    cout<<"Enter lengthA"<<endl;
    cin>>lengthA;
    cout<<"enter Array"<<endl;
    for (int i = 0; i < lengthA; i++)
    {
        cin>>A[i];
    }  
}

void sumfind::display(){

    cout<<"latest array is..."<<endl;
    for (int i = 0; i < lengthA; i++)
    {
        cout<<A[i]<<endl;
    } 
}

int sumfind::max(){
    
        int max=A[0];
        for (int i = 1; i < lengthA; i++)
        {
            if (A[i]>max)
            {
                max=A[i];
            }
            
        }
    return max;
}

void sumfind::findpair(int s){

    H = new int[50]; 
    lengthH=max()+1;

    for (int i = 0; i < lengthH; i++)
    {
        H[i]=0;
    }
    int sum =s;
    
    for (int i = 0; i < lengthA; i++)
    {
        if (H[sum-A[i]]!=0)
        {
            cout<<A[i]<<"+"<<sum-A[i]<<"="<<sum<<endl;
        }
        H[A[i]]++;
        
    }
}

sumfind::~sumfind()
{
    delete[]A;
}


int main(){

    sumfind arr(20);
    arr.create();
    arr.display();
    arr.findpair(10);
    
    return 0;
}