// code for symetric matrix

#include<iostream>
using namespace std;

class symMtx
{
private:
    int *A;
    int n;
public:
    symMtx(int n);
    void create();
    void get(int i , int j);
    void set(int i , int j , int x);
    void display();
    ~symMtx();
};

symMtx::symMtx(int n)
{
    this->n=n;
    A = new int[(n*(n+1))/2];
}

void symMtx::create(){

    cout<<"Enter elements column wise for the upper triangular matrix..."<<endl;
    int x;

    for (int i = 1; i <=n; i++)
    {
        for (int j = 1; j <=n; j++)
        {
            if (i<=j)
            {
                cin>>x;
                A[(j*(j-1)/2) + (i-1)]=x;
            }  
        }   
    }
    
}

void symMtx::display(){

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <=n; j++)
        {
            if (i<=j)
            {
                cout<<A[(j*(j-1)/2) + (i-1)]<<" ";
            }
            else if (i>j)
            {
                cout<<A[(j*(j-1)/2) + (i-1)]<<" ";
            }
              
        }
        cout<<endl;
    }
    cout<<endl;
}

void symMtx::set(int i , int j , int x){
    
    
        A[(j*(j-1)/2) + (i-1)]=x;
}

void symMtx::get(int i, int j) {

        cout << "The retrieved element is: " << A[(j*(j-1)/2) + (i-1)] << endl;
    
}


symMtx::~symMtx()
{
    delete []A;
}


int main(){

    symMtx ele(4);
    ele.create();
    ele.display();
    ele.set(1,2,9);
    ele.display();
    ele.get(2,3);
    
    return 0;
}