// this code compares 2 strings and tells which one is the bigger one

#include<iostream>
using namespace std;

int main(){
    
    char A[]="painter";
    char B[]="Painting";

    int i , j;

    for (i = 0; A[i]!='\0'; i++)
    {
        if (A[i]>65 && A[i]<90)
        {
            A[i]+=32;
        } 
    }

    for ( i = 0 , j=0 ; A[i]!='\0',B[j]!='\0'; i++,j++)
    {
       if (A[i]!=B[j])
       {
        break;
       }

    }
    if (A[i]==B[j])
    {
        cout<<"equal";
    }
    else if (A[i]>B[j])
    {
        cout<<"1 greater";
    }
    else{
        cout<<"2 greater";
    }
    
    
    
    return 0;
}

// by greater i mean it occurs first in the dictionary