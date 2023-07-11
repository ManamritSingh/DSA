// code to reverse a string

#include<iostream>
using namespace std;

int main(){
    char str[]="rahat";
    char A[sizeof(str)];
    int i , j;

    for (i = 0; str[i]!='\0'; i++)
    {
        
    }
    i=i-1;
    for (j = 0; i>=0;j++,i--)
    {
        A[j]=str[i];
    }
    A[j]='\0';
    cout<<A;
    return 0;
}