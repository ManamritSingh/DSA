#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

int main(){
    int *p;
    int *q;
    p = (int *)malloc(5*sizeof(int));
    // or
    q = new int[5];

    p[0] =1;
    p[1] =2;
    p[2] =3;
    p[3] =4;
    p[4] =5;

    q[0] =1;
    q[1] =2;
    q[2] =3;
    q[3] =4;
    q[4] =5;

    for (int i = 0; i < 5; i++)
    {
        cout<<p[i]<<endl;
    }
    
    for (int i = 0; i < 5; i++)
    {
        cout<<q[i]<<endl;
    }

    // dynamic allocation

    free(p); // c
    delete [] q; //cpp

    return 0;
}