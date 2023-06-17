#include<iostream>
using namespace std;

struct rectangle{
    int length;
    int breadth;
};


void initialise(rectangle * r , int l , int b){
    r->length=l;
    r->breadth=b;
}

int area(rectangle r1){
    return r1.length*r1.breadth;
}

int perimeter(struct rectangle r2){
    return 2*(r2.length+r2.breadth);
}
int main(){

    rectangle r={0,0};
    int arr , per;
    int l , b;

    cout<<"Enter the Length and Breadth :"<<endl;

    cin>>l>>b;

    initialise(&r , l , b);
    arr = area(r);
    per = perimeter(r);

    cout<<"The area is "<<arr<<endl;
    cout<<"The perimeter is "<<per;
    
    return 0;
}