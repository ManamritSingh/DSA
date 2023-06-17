#include<iostream>
using namespace std;

struct rectangle{
    int length;
    int breadth;
};

void AssignValues(struct rectangle *r , int l , int b){
    r->length=l;
    r->breadth=b;
}

int FindArea(struct rectangle r1){
    int area = r1.length*r1.breadth;

    return area;
}


void ChangeLength(struct rectangle *r2 , int newl){
    r2->length = newl;
}


int main(){
    rectangle p;

    AssignValues(&p,10,2);
    int arr = FindArea(p);
    cout<<arr<<endl;
    ChangeLength(&p,20);
    int arr1 = FindArea(p);
    cout<<arr1<<endl;
    return 0;
}