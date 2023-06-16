#include<iostream>
using namespace std;

int main(){
    int A[5] ={1,2,3,4,5}; 
    int i;
    for (int i = 0; i < 5; i++)
    {
        cout<<A[i]<<'\n';
    }
    
    cout<<sizeof(A);

    return 0;
}