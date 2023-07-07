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

int checksort::isorted(){

    cout<<"checking . . ."<<endl;
    int i =0;
    while (i<length-1)
    {
        if (A[i]>A[i+1])
        {
            return false;
            break;
        }
        
        i++;
        
    }
    return true;
    
    
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
    cout<<ele.isorted()<<endl;
    
    return 0;
}