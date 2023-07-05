#include<iostream>
using namespace std;

class linearsearch{
private:

int *A;
int length;
int size;

public:

linearsearch(int sz);
void create();
void display();
void swap(int *a , int *b);
int search(int key);
};

linearsearch::linearsearch(int sz){
    sz = size;
    A = new int[sz];
}

void linearsearch::create(){

    cout<<"Enter length"<<endl;
    cin>>length;
    cout<<"enter Array"<<endl;
    for (int i = 0; i < length; i++)
    {
        cin>>A[i];
    }  
}

void linearsearch::display(){

    cout<<"Entered array is..."<<endl;
    for (int i = 0; i < length; i++)
    {
        cout<<A[i]<<endl;
    } 
}

void linearsearch::swap(int *a , int *b){

    int temp =0;
    temp = *a;
    *a=*b;
    *b=temp;
}

int linearsearch::search(int key){
    for (int i = 0; i < length; i++)
    {
        if (key==A[i])
        {
            swap(&A[i], &A[0]);
            cout<<"index : ";
            return i;
        }
    }
    return -1;
}

int main(){

    linearsearch element(10);
    element.create();
    element.display();
    cout<<element.search(3)<<endl;
    element.display();
    
    return 0;
}