#include<iostream>
using namespace std;

double e(int x , int n){

    double num = 1 , den = 1;
    int i;
    double s=1;
    for (int i = 1; i <= n; i++)
    {
        num*=x;
        den*=i;
        s = s+ num/den;

    }
    return s;
}

int main(){
    cout<<e(1,10);
    return 0;
}