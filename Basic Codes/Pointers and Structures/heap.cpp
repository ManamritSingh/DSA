// create an object of structure rectangle in heap memory

#include<iostream>
using namespace std;

struct rectangle{
    int length;
    int breadth;
};

int main(){
    struct rectangle *p;
    // initialize pointer of structure

    p = new rectangle; //cpp
    p = (struct rectangle *)malloc(sizeof(struct rectangle)); // c

    p->length = 10;
    p->breadth = 15;

    cout<<p->length<<endl<<
    p->breadth<<endl;
    return 0;
}