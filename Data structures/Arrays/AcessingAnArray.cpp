#include<iostream>
using namespace std;

int main(){
    int A[]={1,2,3,4,5};

    for (int i = 0; i < 5; i++)
    {
        cout<<A[i]<<endl;
    }
    for (int i = 0; i < 5; i++) // addresses in hex
    {
        cout<<&A[i]<<endl;
    }

    cout<<A[3]<<endl;
    cout<<3[A]<<endl;
    cout<<*(A+3)<<endl;
    return 0;
}