#include <iostream>
using namespace std;

int Findmax(int A[] , int n){
    int max = INT32_MIN;
    for (int i = 0; i < n; i++)
    {
        if (A[i] > max)
        {
            max= A[i];
        }
    }
    return max;
}

void countsort(int A[] , int n){
    int max = Findmax(A , n);

    int *c = new int[max+1];

    for (int i = 0; i < max+1; i++)
    {
        c[i]=0;
    }

    for (int i = 0; i < n; i++)
    {
        c[A[i]]++;
    }
    
    int i =0, j =0;

    while (j< max+1)
    {
        if (c[j]>0)
        {
            A[i++]=j;
            c[j]--;
        }
        else{
            j++;
        }
    }
    
    
}
int main() {

    int A[]={7 , 9 , 5 , 4 , 10 , 12 , 11};
    int n = sizeof(A)/sizeof(A[0]);    

    countsort(A , n);

    for (int i = 0; i < n; i++)
    {
        cout<<A[i]<<" ";
    }
    
    return 0;
}