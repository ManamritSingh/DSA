#include<iostream>
using namespace std;

void fun1(int n); //prototype required

void fun2(int n){
    if (n>0){
        cout<<n<<endl;
        fun1(n/2);
    }
}

void fun1(int n){

    if(n>0){
        cout<<n<<endl;
        fun2(n-1);

    }
    


}

int main(){
    fun1(20);
    return 0;
}