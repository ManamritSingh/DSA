// duplicates using hashing

// works on both sorted an unsorted arrays

#include<iostream>
using namespace std;

class duplicates
{
private:
    int *A;
    int lengthA;
    int sizeA;

    int *H;
    int lengthH;
    int sizeH;
public:
    duplicates(int sz);
    void create();
    void display();
    int max();
    void finduplicate();
    ~duplicates();
};

duplicates::duplicates(int sz)
{
    sizeA = sz;
    A = new int [sz];
}

void duplicates::create(){

    cout<<"Enter lengthA"<<endl;
    cin>>lengthA;
    cout<<"enter Array"<<endl;
    for (int i = 0; i < lengthA; i++)
    {
        cin>>A[i];
    }  
}

void duplicates::display(){

    cout<<"latest array is..."<<endl;
    for (int i = 0; i < lengthA; i++)
    {
        cout<<A[i]<<endl;
    } 
}

int duplicates::max(){
    
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

void duplicates::finduplicate(){

    H = new int[50]; 
    lengthH=max()+1;

    for (int i = 0; i < lengthH; i++)
    {
        H[i]=0;
    }

    for (int i = 0; i < lengthA; i++)
    {
        H[A[i]]++;
        
    }

    for (int i = 0; i < lengthH; i++)
    {
        if (H[i]>1)
        {
            cout<<i<<" occurs "<<H[i]<<" times."<<endl;
        }
        
    }  
}

duplicates::~duplicates()
{
    delete[]A;
}


int main(){

    duplicates arr(20);
    arr.create();
    arr.display();
    arr.finduplicate();
    
    return 0;
}