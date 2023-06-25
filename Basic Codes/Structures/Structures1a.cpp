#include<iostream>
using namespace std;

struct Rectangle
{
    int length;
    int bredth;
    //char x;
};


int main(){
    struct Rectangle r1 = {2,4};

    cout<<sizeof(Rectangle)<<endl;

    cout<<r1.bredth<<endl;
    cout<<r1.length<<endl;

    r1.length = 5;
    r1.bredth = 12;

    cout<<r1.bredth<<endl;
    cout<<r1.length<<endl;

    
    return 0;
}