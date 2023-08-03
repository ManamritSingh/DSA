#include <iostream>
using namespace std;

void insertInheap(int A[] , int n){
    int temp , i = n;

    temp = A[n];

    while (i>=1 && temp > A[i/2])
    {
        A[i]=A[i/2];
        i=i/2;
    }
    A[i] = temp;
}

void createHeap(){

    int A[] = {45, 35, 15, 30, 10, 12, 6, 5, 20, 50};

    for (int i = 1; i < (sizeof(A)/sizeof(A[0])); i++)
    {
        insertInheap(A , i);
    }

    for (int i = 0; i < (sizeof(A)/sizeof(A[0])); i++)
    {
        cout<<A[i]<<" ";
    }
    
}

int main() {

    createHeap();
    
    
    return 0;
}