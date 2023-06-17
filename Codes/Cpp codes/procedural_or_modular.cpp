#include<iostream>
using namespace std;

int area(int length , int breadth){
    return length*breadth;
}

int perimeter(int length , int breadth){
    return 2*(length+breadth);
}
int main(){
    int length , breadth , arr , per;

    cout<<"Enter the Length and Breadth :"<<endl;

    cin>>length>>breadth;

    arr = area(length,breadth);
    per = perimeter(length,breadth);

    cout<<"The area is "<<arr<<endl;
    cout<<"The perimeter is "<<per;
    
    return 0;
}