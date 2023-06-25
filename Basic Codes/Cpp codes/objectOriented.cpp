#include<iostream>
using namespace std;

class rectangle{
    int length;
    int breadth;

public:

rectangle( int l , int b){
    length=l;
    breadth=b;
}

int area(){
    return length*breadth;
}

int perimeter(){
    return 2*(length+breadth);
}

};
int main(){

    int arr , per;
    int l , b;

    cout<<"Enter the Length and Breadth :"<<endl;

    cin>>l>>b;

    rectangle r(l , b);
    arr = r.area();
    per = r.perimeter();

    cout<<"The area is "<<arr<<endl;
    cout<<"The perimeter is "<<per;
    
    return 0;
}