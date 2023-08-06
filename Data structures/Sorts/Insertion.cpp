#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void insertionSort(int A[] , int n){
    
    int i , j , x;

    for ( i = 1; i < n; i++)
    {
        x=A[i];
        j=i-1;

        while (j > -1 && A[j] > x)
        {
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=x;
    }
    
}

int main() {
    int A[]={13 , 12 , 10 , 4 , 5, 7 , 9};
    int n = 7;

    insertionSort(A , n);

    for (int i = 0; i < n; i++)
    {
        cout<<A[i]<<" ";
    }
    
    return 0;
}