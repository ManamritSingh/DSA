// code to reverse a string

#include<iostream>
using namespace std;

int main(){
    char str[]="rahat";
    char t;
    int i , j;

    for (i = 0; str[i]!='\0'; i++)
    {
        
    }
    i=i-1;
    for (j = 0 ; j<i;j++,i--)
    {
        t=str[j];
        str[j]=str[i];
        str[i]=t;
    }
    cout<<str;
    return 0;
}