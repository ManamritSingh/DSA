#include<iostream>
using namespace std;

class arraADT{
private:

    int *A;
    int size;
    int length;

public:

    arraADT(int sz);
    void create();
    void display();
    void deleteElement(int index);

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

void arraADT::deleteElement(int index){

    int x=A[index];
    cout<<"deleting element"<<endl;

    for (int i = index; i < length-1; i++)
    {
        A[i]=A[i+1];
    }
    length--;
    
}

int main(){

    arraADT arr(10);
    arr.create();
    arr.display();
    arr.deleteElement(3);
    arr.display();
    
    return 0;
}