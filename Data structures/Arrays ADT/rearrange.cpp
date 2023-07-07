// this program rearranges an array's positive and negative elements on their respective sides

// insert in a sorted array

#include<iostream>
using namespace std;

class checksort
{
private:
    int *A;
    int size;
    int length;
public:
    checksort(int sze);
    void create();
    void display();
    void swap(int *a , int *b);
    int isorted();
    ~checksort();
};

checksort::checksort(int sze)
{
    size = sze;
    A = new int[sze];
}

void checksort::create(){

    cout<<"Enter length"<<endl;
    cin>>length;
    cout<<"enter Array"<<endl;
    for (int i = 0; i < length; i++)
    {
        cin>>A[i];
    }  
}

void checksort::display(){

    cout<<"latest array is..."<<endl;
    for (int i = 0; i < length; i++)
    {
        cout<<A[i]<<endl;
    } 
}

void checksort::swap(int *a , int *b){

    int temp =0;
    temp = *a;
    *a=*b;
    *b=temp;
}

int checksort::isorted(){

    cout<<"Sorting ...."<<endl;

    int i =0;
    int j = length-1;

    while(i<j){

        while(A[i]<0)i++;
        while(A[j]>=0)j--;
        if (i<j)
        {
            swap(&A[i], &A[j]);
        }
    }
    return 0;
}


checksort::~checksort()
{
    delete []A;
    cout<<"Destruction whoshh!!!!! "<<endl;
}


int main(){

    checksort ele(10);
    ele.create();
    ele.display();
    ele.isorted();
    ele.display();
    
    return 0;
}