// code to count vowels and consonants in a string

#include<iostream>
using namespace std;

int main(){
    char A[20]="How are you?";
    int vowel=0;
    int consonant =0;

    for (int i = 0; A[i]!='\0'; i++)
    {
        if (A[i]=='A' ||
        A[i]=='E' ||
        A[i]=='I' ||
        A[i]=='O' ||
        A[i]=='U' ||
        A[i]=='a' ||
        A[i]=='e' ||
        A[i]=='i' ||
        A[i]=='o' ||
        A[i]=='u' )
        {
            vowel++;
        }
        else if ((A[i]>65 && A[i]<90) || (A[i]>97 && A[i]<122))
        {
            consonant++;
        }
    }
    cout<<"Number of vowels are :"<<vowel<<endl;
    cout<<"Number of consonants are :"<<consonant<<endl;
    return 0;
}