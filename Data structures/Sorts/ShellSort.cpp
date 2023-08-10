#include <iostream>
using namespace std;

void shellSort(int A[] , int n){
    for(int gap = n/2 ; gap >=1 ; gap/=2){
        for (int j = gap; j < n; j++)
        {
            int temp = A[j];
            int i = j-gap;
            while (i>= 0 && A[i] > temp)
            {
                A[i+gap]=A[i];
                i-=gap;
            }
            A[i+gap]=temp;
        }
        
    }
}

int main() {
    int A[] = {11, 13, 7, 12, 16, 9, 24, 5, 10, 3};
    int n = sizeof(A)/sizeof(A[0]);

    shellSort(A , n);

    for (int i = 0; i < n; i++)
    {
        cout<<A[i]<<" ";
    }
    
    
    return 0;
}


// basic idea is to use the close to best case scanario of insertion sort
// uses less number of swaps to sort the array