#include <iostream>
#include <bits/stdc++.h> // swap fxn
using namespace std;

class heap{
    public:
        int A[10] = {45, 35, 15, 30, 10, 12, 6, 5, 20, 50};
        int* getheap(){return A ;}
        void insertInheap(int A[] , int n);
        void createHeap();
        int deletefromheap(int A[]);
        void displayheap();
};

void heap::insertInheap(int A[] , int n){
    int temp , i = n;

    temp = A[n];

    while (i>=1 && temp > A[i/2])
    {
        A[i]=A[i/2];
        i=i/2;
    }
    A[i] = temp;
}

void heap::createHeap(){

    int A[] = {45, 35, 15, 30, 10, 12, 6, 5, 20, 50};

    for (int i = 1; i < 10; i++)
    {
        insertInheap(A , i);
    }
    
}

void heap::displayheap(){

    for (int i = 0; i < 10; i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;
}

int heap::deletefromheap(int A[]){
    int x , i , j;
    int val = A[1];
    int n = 10;
    x = A[n];
    A[1]=A[n];

    i = 1 ;
    j = 2*i;

    while (j < n-1)
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
    //h.deletefromheap(h.getheap());
    //h.displayheap();
    
    return 0;
}