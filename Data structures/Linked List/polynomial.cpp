#include <iostream>
using namespace std;

class node{
    public:

    int exp;
    int coef;
    node *next;
};

class polynomial{
private:
        node *head = nullptr;    
public:
    polynomial();
    void display();
};

polynomial::polynomial(){

    //node *p =head;
    node *t , *last =nullptr;
    int num;

    cout<<"enter no of terms"<<endl;
    cin>>num;

    for (int i = 0; i < num; i++)
    {
        t = new node;
        cout<<"Enter the coeff and exp"<<endl;
        cin>>t->coef;
        cin>>t->exp;
        t->next=nullptr;
        if (head==nullptr)
        {
            head=last=t;
        }
        else{
            last->next=t;
            last=t;
        }
    }
    
}

void polynomial::display(){
    node*p =head;

    while (p)
    {
        cout<<p->coef<<"x^"<<p->exp;
        if (p->next != nullptr)
        {
            cout<<" +";
        }
        p=p->next;
        
    }
    
}

int main() {

    polynomial p;
    p.display();
    
    return 0;
}