// this program helps you change the case of a string

#include<iostream>
using namespace std;

int main(){
    char A[10]="wElcOme";

    cout<<A<<endl;

    for (int i = 0; A[i]!='\0'; i++)
    {
        if (A[i]>65 && A[i]<90)
        {
            A[i]+=32;
        }
        else if (A[i]>'a' && A[i]<'122') // u can use both 'char' and the ascii value to represent
        {
            A[i]-=32;
        }  
    }
    cout<<A<<endl;
    return 0;
}