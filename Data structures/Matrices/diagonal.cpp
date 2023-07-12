// code for diagonal matrix

#include<iostream>
using namespace std;

class diagonal
{
private:
    int *A;
    int n;
public:
    diagonal(int n);
    void create();
    void display();
    // now fxns required to later access the matrix
    void set(int i , int j , int x);
    int get(int i , int j);
    ~diagonal();
};

diagonal::diagonal(int n)
{
    this->n=n;
    A = new int [n];
}

void diagonal::create(){
    int x;
    cout<<"Enter elements of the matrix:"<<endl;

    for (int i = 1; i <=n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout<<"Enter element["<<i<<"]"<<"["<<j<<"] :"<<endl;
            cin>>x;
            if (i==j)
            {
                A[i-1]=x;
            }
        }   
    }
}

void diagonal::display(){

    for (int i = 1; i <=n; i++)
    {
        for (int j = 1; j <=n; j++)
        {
            if (i!=j)
            {
                cout<<"0 ";
            }
            else if (i==j)
            {
                cout<<A[i-1]<<" ";
            } 
            
        }
        cout<<endl;
        
    }
    cout<<endl;
}

void diagonal::set(int i , int j , int x){

    if(i==j){
        A[i-1]=x;
    }
    else if (i!=j)
    {
        cout<<"are ya crazy mate ?"<<endl;
    }
    
}

int diagonal::get(int i , int j){
    if (i==j)
    {
        return A[i-1];
    }
    else{
        return 0;
    }
}

diagonal::~diagonal()
{
    delete []A;
}

int main(){
    diagonal ele(3);
    ele.create();
    ele.display();
    ele.set(3,3,9);
    ele.display();
    cout<<"element @ 2,2 is "<<ele.get(2,2);
    
    return 0;
}