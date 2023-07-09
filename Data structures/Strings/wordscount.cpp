#include<iostream>
using namespace std;

int main(){
    
    char A[20]="how are you?";

    int word=1;

    for (int i = 0; A[i]!='\0'; i++)
    {
        if (A[i]==' ' && A[i-1]!=' ')
        {
            word++;
        }
        
    }
    cout<<"No of words in this string is : "<<word<<endl;
    
    return 0;
}