#include<iostream>
using namespace std;
// linear search 

class binarysearch{
private:

int *A;

int length;
int size;

public:

binarysearch(int sz);
void create();
void display();
void swap(int *a , int *b);
int search(int key);
};

binarysearch::binarysearch(int sz){
    sz = size;
    A = new int[sz];
}

void binarysearch::create(){

    cout<<"Enter length"<<endl;
    cin>>length;
    cout<<"enter Array"<<endl;
    for (int i = 0; i < length; i++)
    {
        cin>>A[i];
    }  
}

void binarysearch::display(){

    cout<<"Entered array is..."<<endl;
    for (int i = 0; i < length; i++)
    {
        cout<<A[i]<<endl;
    } 
}

void binarysearch::swap(int *a , int *b){

    int temp =0;
    temp = *a;
    *a=*b;
    *b=temp;
}

int binarysearch::search(int key ){
    int l =0;
    int h = length-1;
    int mid=0;
    while (l<=h)
    {
        mid = (l+h)/2;
        if (key==A[mid])
        {
            swap(&A[mid],&A[0]);
            return mid;
        }
        else if(key>A[mid]){
            l==mid+1;
        }
        else{
            h=mid-1;
        }    
    }
    return -1;
    
}

int main(){

    binarysearch element(10);
    element.create();
    element.display();
    cout<<"index is "<<element.search(3)<<endl;
    element.display();
    
    return 0;
}