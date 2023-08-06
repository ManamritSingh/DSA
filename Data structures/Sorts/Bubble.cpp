#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void bubbleSort(int A[] , int n){
    int i , j , flag = 0;

    for (i = 0; i < n-1; i++)
    {
        flag = 0;
        for ( j = 0; j < n-i-1 ; j++)
        {
            if (A[j] > A[j+1])
            {
                swap(A[j] , A[j+1]);
            }
            flag=1;
        }
        if (flag==0)
        {
            break;
        }
    }
}

int main() {
    int A[]={13 , 12 , 10 , 4 , 5, 7 , 9};
    int n = 7;

    bubbleSort(A , n);

    for (int i = 0; i < n; i++)
    {
        cout<<A[i]<<" ";
    }
    
    return 0;
}