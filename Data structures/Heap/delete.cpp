#include <iostream>
#include <bits/stdc++.h> // swap fxn
using namespace std;

class heap{
    public:
        int A[8] = {0 , 10 , 20 , 30 , 25 , 5 , 40 , 35};
        int* getheap(){return A ;}
        void insertInheap(int A[] , int n);
        void createHeap();
        int deletefromheap(int A[] , int n);
        void displayheap();
};

void heap::insertInheap(int A[] , int n){
    int temp , i = n;

    temp = A[i];

    while (i>1 && temp > A[i/2])
    {
        A[i]=A[i/2];
        i=i/2;
    }
    A[i] = temp;
}

void heap::createHeap(){

    //int A[] = {0,10 , 20 , 30 ,25 , 5 , 40 , 35};

    for (int i = 2; i <= 7; i++)
    {
        insertInheap(A , i);
    }
    
}

void heap::displayheap(){

    for (int i = 1; i <= 7; i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;
}

int heap::deletefromheap(int A[] , int n){
    int x , i , j , val;
    val = A[1];
    x = A[n];
    A[1]=A[n];
    A[n] = val;
    i = 1 ;
    j = 2*i;

    while (j <= n-1)
    {
        if ( j< n-1 && A[j+1] > A[j])
        {
            j=j+1;
        }
        if (A[i] < A[j])
        {
            swap(A[i], A[j]);
            i=j;
            j=2*j;
        }
        else
            break;
        return val;
    }
}

int main() {
    heap h;

    h.createHeap();
    h.displayheap();

    for(int i = 7 ; i>1 ; i--)
    h.deletefromheap(h.getheap(), i);
    
    h.displayheap();
    
    return 0;
}