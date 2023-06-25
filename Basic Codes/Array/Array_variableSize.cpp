#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter a number"<<endl;
    cin>>n;

    int A[n];
    cout<<"Enter your array"<<endl;
    for (int i = 0; i <n; i++)
    {
        cin>>A[i];
    }
    
    
    for (int i = 0; i < n; i++)
    {
        cout<<A[i]<<'\n';
    }

    return 0;
}