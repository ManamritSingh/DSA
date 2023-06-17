#include<iostream>
using namespace std;

int main(){
    int length =0 ;
    int breadth = 0;
    cout<<"Enter the Length and Breadth :"<<endl;

    cin>>length>>breadth;

    int area = length*breadth;
    int perimiter = 2*(length+breadth);

    cout<<"The area is "<<area<<endl;
    cout<<"The perimeter is "<<perimiter;
    return 0;
}