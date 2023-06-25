#include<iostream>
using namespace std;

void fun(int A[]){
    cout<<sizeof(A)/sizeof(int)<<endl;
    // wont work because it returns the size of the pointer A[] and not the actual array
}

int main(){
    int A[5]={1,2,3,4,5};
    int n = 5;

    cout<<sizeof(A)/sizeof(int)<<endl;

    fun(A);
    return 0;

}