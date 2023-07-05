#include<iostream>
//#include<stdio.h>
using namespace std;

struct appendArray
{
    int A[5];
    int length;
    int size;
};

void display(struct appendArray arr){
    int i;

    //if (arr->length<arr->size)
    
        for (int i = 0; i < arr.length; i++)
        {
            cout<<arr.A[i]<<endl;
        }
        
    
}

void append(struct appendArray *arr, int x){

    if(arr->length<arr->size){
        cout<<"appending..."<<endl;

        arr->A[arr->length]=x;
        //cout<<"Result0 "<<arr->A[arr->length]<<endl;
        //arr->length++;
       //arr->A[arr->length]=x;
       // //arr->length++;
       // cout<<"Result "<<arr->A[arr->length];
    }
}


int main(){

    struct appendArray dt={{1,2,3,4,5},5,10};

    display(dt);
    append(&dt , 10);
    display(dt);
    
    return 0;
}