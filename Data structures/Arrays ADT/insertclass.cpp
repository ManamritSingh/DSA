#include<iostream>
using namespace std;
//code for insert operation
class arraADT{
private:

    int *A;
    int size;
    int length;

public:

    arraADT(int sz);
    void create();
    void display();
    void append(int x);
    void insert(int index , int x);

};

arraADT::arraADT(int sz){
    sz = size;
    A = new int[sz];
}

void arraADT::create(){
    cout<<"Enter length"<<endl;
    cin>>length;
    if (size > length) {
        cout<<"enter elements"<<endl;
        for (int i = 0; i < length; i++)
        {
            cin>>A[i];
        }
}
}
void arraADT::display(){
    cout<<"Array is ..."<<endl;

    for(int i=0 ; i<length;i++){
        cout<<A[i]<<endl;
    }
}
void arraADT::append(int x){
    // code to add element at the end of array
    A[length]=x;
    length++;
}

void arraADT::insert(int index , int x){

    cout<<"inserting..."<<endl;
    for (int i = length; i < index; i--)
    {
        A[i]=A[i-1];
    }
    A[index]=x; 
}
int main(){
    arraADT arr(10);
    arr.create();
    arr.display(); 
    arr.append(34);
    arr.display();
    arr.insert(5,6);
    arr.display();
    return 0;
}