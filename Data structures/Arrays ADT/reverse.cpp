#include<iostream>
using namespace std;

class reversearr
{
private:
    int *A;
    int size;
    int length;
public:
    reversearr(int sze);
    void create();
    void display();
    void reverse();
    ~reversearr();
};

reversearr::reversearr(int sze)
{
    size = sze;
    A = new int[sze];
}

void reversearr::create(){

    cout<<"Enter length"<<endl;
    cin>>length;
    cout<<"enter Array"<<endl;
    for (int i = 0; i < length; i++)
    {
        cin>>A[i];
    }  
}

void reversearr::display(){

    cout<<"latest array is..."<<endl;
    for (int i = 0; i < length; i++)
    {
        cout<<A[i]<<endl;
    } 
}

void reversearr::reverse(){

    int *B;
    B = new int[size];
    int i , j;

    for(i=0,j=length-1;j>=0;i++,j--){
        B[i]=A[j];
    }
    for (int k=0 ; k<length;k++){
        A[k]=B[k];
    }
    
}


reversearr::~reversearr()
{
    delete []A;
    cout<<"Destruction whoshh!!!!! "<<endl;
}


int main(){

    reversearr ele(10);
    ele.create();
    ele.display();
    ele.reverse();
    ele.display();
    
    return 0;
}