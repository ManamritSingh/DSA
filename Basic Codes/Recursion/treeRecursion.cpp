#include<iostream>
using namespace std;

fun(int r)
{
    if (r>0){
        cout<<r<<endl;

        fun(r-1);
        fun(r-1);

        return 0;
    }
}

int main(){
    fun(3);
    return 0;
}