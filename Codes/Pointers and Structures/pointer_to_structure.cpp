/* This section shows how to point to a structure using a pointer
also in the second code , we will learn to dynamically allocate memory in heap and there point to the structure
*/

#include<iostream>
using namespace std;

struct rectangle{
    int length;
    int breadth;
};

int main(){
    //struct rectangle r = {10,5};
    //struct can be skipped in cpp
    rectangle r = {10,5};
    cout<<r.length<<endl;
    cout<<r.breadth<<endl;

    rectangle *p=&r;

    cout<<p->length<<endl;
    cout<<p->breadth<<endl;

    return 0;
}