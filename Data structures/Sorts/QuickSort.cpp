#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int partition(int A[] , int l , int h ){
    int pivot = A[l];
    int i = l , j =h;

    do
    {
        do{i++;}while(A[i]<= pivot);
        do{j--;}while(A[j]>pivot );

        if (i<j)
        {
            swap(A[i] , A[j]);
        }
        
    } while (i<j);
    swap(A[l] , A[j]);
    return j;
}

void QuickSort(int A[] , int l , int h){
    int j ;

    if (l<h)
    {
        j =partition(A , l , h);
        QuickSort(A , l , j);
        QuickSort(A , j+1 , h);
    }
    
}

int main() {
    int A[]={13 , 12 , 10 , 4 , 5, 7 , 9 , INT32_MAX};

    QuickSort(A , 0 , 7);

    for (int i = 0; i < 7; i++)
    {
        cout<<A[i]<<" ";
    }
    
    return 0;
}