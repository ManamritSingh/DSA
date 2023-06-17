// this is how you can call an array by value using structure

#include<iostream>
using namespace std;

struct array{
    int A[5];
    int n;
};


void fun(struct array a1){
    for (int i = 0 ;i <a1.n ; ++i){
        cout<<a1.A[i]<<" ";
    }
}
int main(){
    struct array a = {{1,2,3,4,5},5};
    fun(a);
    
    return 0;
}