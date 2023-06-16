#include<iostream>
using namespace std;

int add(int a , int b){
    int c;
    c=a+b;
    return(c);
}

int main(){
    int x = 12;
    int y = 5;
    int z;
    z = add(x,y);
    cout<<z;
    return 0;
}