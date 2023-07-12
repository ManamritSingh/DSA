// no of non zero elements n(n+1)/2
// no of zero elements n(n-1)/2 
// i<=j elements are non zero
// row major formula to access the elements [(n(i-1)+(i-1)(i-2)/2)]+(j-i)
// column major formula j(j-1)/2 + (i-1)

#include<iostream>
using namespace std;

class uppertri
{
private:
    int *A;
    int n;
public:
    uppertri(int n);
    void create();
    void get(int i , int j);
    void set(int i , int j , int x);
    void display();
    ~uppertri();
};

uppertri::uppertri(int n)
{
    this->n=n;
    A = new int[(n*(n+1))/2];
}

void uppertri::create(){

    cout<<"Enter elements column wise..."<<endl;
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

void uppertri::display(){

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
                cout<<"0 ";
            }
              
        }
        cout<<endl;
    }
    cout<<endl;
}

void uppertri::set(int i , int j , int x){
    
    if (i<=j)
    {
        A[(j*(j-1)/2) + (i-1)]=x;
    }
}

void uppertri::get(int i, int j) {
    if (i <= j) {
        cout << "The retrieved element is: " << A[(j*(j-1)/2) + (i-1)] << endl;
    } else {
        cout << "The retrieved element is: 0" << endl;
    }
}


uppertri::~uppertri()
{
    delete []A;
}


int main(){

    uppertri ele(4);
    ele.create();
    ele.display();
    ele.set(1,2,9);
    ele.display();
    ele.get(2,3);
    
    return 0;
}