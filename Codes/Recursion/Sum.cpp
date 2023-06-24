#include<iostream>
using namespace std;

int recursion(int n){  // O(n) time but makes stack so takes a lot of space
    if (n==0){
        return 0;
    }
    else{
        return (recursion(n-1)+n);
    }
}

int loop(int n){  // O(n) time ans space is just the 3 variables it makes
int s =0;
for (int i = 0; i <= n; i++)
{
    s = s+i; 
}
return s;
}

int formula(int n){  // best O(1) time and takes just 2 variables
    int sum = 0;

    sum = n*(n+1)/2;

    return sum;
}

int main(){
    cout<<recursion(10)<<endl;
    cout<<loop(10)<<endl;
    cout<<formula(10)<<endl;
    return 0;
}