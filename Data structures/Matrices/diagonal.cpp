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
    
}

diagonal::~diagonal()
{
    delete []A;
}

int main(){
    diagonal ele(3);
    ele.create();
    ele.display();
    
    return 0;
}