#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void selectionSort(int A[] , int n){
    int i , j , k;

    for ( i = 0; i < n-1; i++)
    {
        for ( j = k= i ; j <n; j++)
        {
            if (A[j] < A[k])
            {
                k=j;
            }
        }
        swap(A[i], A[k]);
    }
    
}

int main() {
    int A[]={13 , 12 , 10 , 4 , 5, 7 , 9};
    int n = 7;

    selectionSort(A , n);

    for (int i = 0; i < n; i++)
    {
        cout<<A[i]<<" ";
    }
    
    return 0;
}