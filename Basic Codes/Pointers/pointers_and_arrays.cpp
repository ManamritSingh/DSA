#include<iostream>
using namespace std;

int main(){
    int A[5]={1,2,3,4,5}; // all arrays by default are created in stack memory
    int *p;
    int *q;
    p=A;
    q=&A[0];

    for (int i = 0; i < 5; i++)
    {
        cout<<p[i]<<endl;
        cout<<q[i]<<endl;
    }
    
    return 0;
}