#include<iostream>
using namespace std;
// void fun(int *A , int n) also a valid way to initialise the array pointer
void fun(int A[] , int n){
    for (int i = 0; i < n; i++)
    {
        cout<<A[i]<<endl;
    }


    //for(int x:A){
    //    cout<<x<<endl;
    //}

    // for each loop doent work with pointers A[] is a pointer
}

int main(){
    int A[5]={1,2,3,4,5};
    int n = 5;

    for(int x:A){
        cout<<x<<endl;
    }

    fun(A,n);
    return 0;

}