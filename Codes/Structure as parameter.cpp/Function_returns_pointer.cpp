//This code demonstrates how a function can retuen a pointer
//an object is defined in heap and then it is accessed by the main function using the function that returns this pointer


#include<iostream>
using namespace std;

struct rectangle
{
    int length;
    int breadth;
};

struct rectangle * fun(){  // this function has a return type of a structure pointer

    struct rectangle *p;
    p = new rectangle;

    p->length=10;
    p->breadth=3;

    return p;
}


int main(){

    rectangle *ptr;

    ptr = fun();

    cout<<ptr->breadth<<endl<<ptr->length<<endl;
    
    return 0;
}