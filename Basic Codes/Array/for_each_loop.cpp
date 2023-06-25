#include<iostream>
using namespace std;

int main(){

    int v[3]={1,2,3};
    int i=0;
    for (int x : v)
    {
       cout<<x<<endl; 
    }
    
    return 0;
}