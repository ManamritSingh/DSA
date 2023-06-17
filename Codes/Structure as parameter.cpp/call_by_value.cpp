#include<iostream>
using namespace std;

struct rectangle{
    int length;
    int breadth;
};

void fun(struct rectangle r1){
    r1.length=20;
    cout<<r1.length<<endl<<r1.breadth<<endl; //the value does chnage here and will reflect in the output too
}
int main(){
    rectangle r = {10,5}; // but it wint have any effect over here as can be seen in the results
    fun(r);
    
    cout<<r.length<<endl<<r.breadth<<endl;
    return 0;
}