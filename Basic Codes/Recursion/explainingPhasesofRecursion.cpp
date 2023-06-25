#include<iostream>
using namespace std;

int fun1(int a){
    cout<<"FUN 1 called"<<endl;
    
    if (a>0)
    {
        cout<<a<<endl;
        fun1(a-1);
    }
    return 0;
}

int fun2(int a){
    cout<<"FUN 2 called"<<endl;
    if (a>0)
    {
        fun2(a-1);
        cout<<a<<endl;
    }
    return 0;
}

int main(){
    int x = 3;
    cout<<"FUN 1 OUTPUT"<<endl;
    fun1(x);
    cout<<"************************************"<<endl;
    cout<<"FUN 2 OUTPUT"<<endl;
    fun2(x);
    return 0;
}