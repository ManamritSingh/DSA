#include<iostream>
using namespace std;

int main(){
    char a[]="decimal";
    char b[]="medical";
    int H[26],i;
    for (i = 0; i < 26; i++)
    {
        H[i]=0;
    }
    for (i = 0; a[i]!='\0'; i++)
    {
        H[a[i]-97]++;
    }
    for (i = 0; b[i]!='\0'; i++)
    {
        H[b[i]-97]--;

        if (H[b[i]-27]<0)
        {
            cout<<"not anagram";
            break;
        }
        
    }
    if (b[i]=='\0')
    {
        cout<<"anagram";
    }
    
    return 0;
}