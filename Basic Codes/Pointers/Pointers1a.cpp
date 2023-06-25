#include<iostream>
using namespace std;

int main(){
    int a = 10;
    int *p;
    p=&a;
    cout<<"The pointer points to the address :"<<p<<endl;
    cout<<"The address stores : "<<*p<<endl;
    cout<<"The address can also be found using &a "<<&a<<endl;
    return 0;
}