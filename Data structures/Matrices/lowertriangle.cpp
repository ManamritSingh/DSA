// no of non zero elements n(n+1)/2
// no of zero elements n(n-1)/2 
// i>=j elements are non zero
// row major formula to access the elements i(i-1)/2  + j-1
// column major formula [(n(j-1)+(j-1)(j-2)/2)]+(i-j)

#include<iostream>
using namespace std;

class lowertriangle
{
private:
    int *A;
    int n;
public:
    lowertriangle(int n);
    void create();
    void get(int i , int j);
    void set(int i , int j , int x);
    void display();
    ~lowertriangle();
};

lowertriangle::lowertriangle(int n)
{
    this->n=n;
    A = new int[(n*(n+1))/2];
}

void lowertriangle::create(){

    cout<<"Enter elements row wise..."<<endl;
    int x;

    for (int i = 1; i <=n; i++)
    {
        for (int j = 1; j <=n; j++)
        {
            if (i>=j)
            {
                cin>>x;
                A[(i*(i-1)/2)  + (j-1)]=x;
            }  
        }   
    }
    
}

void lowertriangle::display(){

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <=n; j++)
        {
            if (i>=j)
            {
                cout<<A[(i*(i-1)/2)+(j-1)]<<" ";
            }
            else if (i<j)
            {
                cout<<"0 ";
            }
              
        }
        cout<<endl;
    }
    cout<<endl;
}

void lowertriangle::set(int i , int j , int x){
    
    if (i>=j)
    {
        A[(i*(i-1)/2)+(j-1)]=x;
    }
}

void lowertriangle::get(int i, int j) {
    if (i >= j) {
        cout << "The retrieved element is: " << A[(i * (i - 1) / 2) + (j - 1)] << endl;
    } else {
        cout << "The retrieved element is: 0" << endl;
    }
}


lowertriangle::~lowertriangle()
{
    delete []A;
}


int main(){

    lowertriangle ele(4);
    ele.create();
    ele.display();
    ele.set(2,1,9);
    ele.display();
    ele.get(4,3);
    
    return 0;
}