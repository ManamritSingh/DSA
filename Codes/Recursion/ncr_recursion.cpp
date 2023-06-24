#include<iostream>
using namespace std;

ncr(int n , int r){

    if(n==r || r==0){
        return 1;
    }
    else{
        return ncr(n-1 , r) + ncr(n-1 , r-1);
    }
}

int main(){
    cout<<ncr(5,2);
    return 0;
}