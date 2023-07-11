// checks if palindrome

#include<iostream>
using namespace std;

int main(){
    char s[]="nitin";
    int i,j;

    for ( i = 0; s[i]!='\0'; i++)
    {
    }
    i--;
    for ( j = 0; j<i; j++,i--)
    {
        if (s[j]!=s[i])
        {
            cout<<"not a palindrome";
        }
        
    }
    if (s[i]==s[j])
    {
        cout<<"palindrome";
    }
    
    
    
    
    return 0;
}