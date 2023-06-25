//This works only with c++ and is not advisable to use with more complex functions which include loops or logic basically
// it is actually a monolithic program only but the source code is procedural

#include<iostream>
using namespace std;

void swap(int &x , int &y){
    int temp;
    temp =x;
    x=y;
    y=temp;
}

int main(){
    int a =10;
    int b= 20;

    swap(a , b);

    cout<<"a "<<a<<endl;
    cout<<"b "<<b<<endl;
    return 0;
}