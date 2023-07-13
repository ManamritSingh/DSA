// single code for polynomial representation, evaluation and addition

#include<iostream>
using namespace std;

class term{
public:
int coeff;
int expn;
};

class poly
{
private:
    int n;
    class term *t;
public:
    poly(int n);
    ~poly();

    void read();
    void display();
    friend istream& operator>>(istream &is , poly &pl);
    friend ostream& operator <<(ostream &os , poly &pl);

    poly operator+(poly &p);
};

poly::poly(int n)
{
    this->n=n;
    t = new term[this->n];
}

poly::~poly()
{
    delete[] t;
}

istream& operator>>(istream &is , poly &pl){
    cout<<"Enter the coefficients followed by exponents in the decreasing order of degree"<<endl;
    for (int i = 0; i < pl.n; i++)
    {
        cin>>pl.t[i].coeff;
        cin>>pl.t[i].expn;
    }
    return is;
}

ostream& operator <<(ostream &os , poly &pl){

    for (int i = 0; i < pl.n; i++)
    {
        cout<<pl.t[i].coeff<<"x^"<<pl.t[i].expn<<"+ ";
    }
    return os;
}

poly poly::operator+(poly &p){

    int i , j , k;

    poly *sum = new poly(n + p.n);

    i = j = k = 0;

    while(i<n && j< p.n){

        if (t[i].expn<p.t[j].expn)
        {
            sum->t[k++]=p.t[j++];
        }
        else if (t[i].expn>p.t[j].expn)
        {
            sum->t[k++]=t[i];
        }
        else{
            // both same
            sum->t[k].expn=t[i].expn;
            sum->t[k++].coeff= t[i++].coeff + p.t[j++].coeff;
        }
    }
    for (; i < n; i++)
    {
        sum->t[k++]=t[i];
    }
    for (; j < p.n; j++)
    {
        sum->t[k++]=p.t[j];
    }

    sum->n=k;
    return *sum;
}


int main(){

    poly p1(3);
    poly p2(4);

    cin>>p1;
    cin>>p2;

    poly sum = p1+p2;

    cout<<"polynomial 1 is"<<endl<<p1<<endl;
    cout<<"polynomial 2 is"<<endl<<p2<<endl;
    
    cout<<"Sum of both polynomials is :"<<endl<<sum<<endl;
    return 0;
}