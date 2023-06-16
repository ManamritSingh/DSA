#include<iostream>
using namespace std;

int main(){
    int a = 10;
    int &r = a;
    // reference does not consume memory

    cout<<a<<endl;
    cout<<r<<endl;
    r++;
    cout<<a<<endl;

    int b = 25;
    r=b;

    cout<<a<<endl;
    return 0;
}