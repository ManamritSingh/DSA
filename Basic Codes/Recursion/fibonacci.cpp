#include<iostream>
using namespace std;

int fib(int n){

    int i = 0 , s=0;
    int t0 = 0;
    int t1 =1;
     if (n<=1){
        return n;
     }
     else{
        for (i = 2; i <=n; i++)
        {
            s = t0+t1;
            t0=t1;
            t1=s;
        }
        
     }
     return s;
}

int rfib(int n){
    if(n<=1){
        return n;
    }
    else{
        return rfib(n-1)+ rfib(n-2);
        }
}

int A[10];

int mfib(int n){
    if(n<=1){
        return n;
        A[n]= mfib(n);
    }
    else if(A[n-1]== -1){
        A[n-1]=mfib(n-1);
        
    }
    else if(A[n-2]== -1){
        A[n-2]=mfib(n-2);
        
    }
    return mfib(n-1)+mfib(n-2);
}

int main(){

    for(int i = 0 ; i < 10; i++){
        A[i]=-1;
    }
    cout<<fib(6)<<endl;
    cout<<rfib(6)<<endl;
    cout<<mfib(6)<<endl;
    return 0;
}