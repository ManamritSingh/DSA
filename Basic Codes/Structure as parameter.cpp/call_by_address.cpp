#include<iostream>
using namespace std;

struct rectangle{
    int length;
    int breadth;
};

void fun(struct rectangle *p){
    p->length=20;
    cout<<p->length<<endl<<p->breadth<<endl; //the value does chnage here and will reflect in the output too
}
int main(){
    rectangle r = {10,5}; // and as its a pointer so even these variables will be changed
    fun(&r);
    
    cout<<r.length<<endl<<r.breadth<<endl;
    return 0;
}