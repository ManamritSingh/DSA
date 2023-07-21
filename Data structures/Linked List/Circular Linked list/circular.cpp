// code to create and display circular LL

#include <iostream>
using namespace std;

class node{
    public :
        int data;
        node *next;
};

class CircularLL{

private:
    node *head;

public:
    CircularLL(int A[] , int n);
    //~CircularLL();
    void Display();
    void RDisplay(node *p);


    node* gethead(){
        return head;
    }
};

CircularLL::CircularLL(int A[] , int n){

    node *t , *tail; // t for new node and last to link
    int i;
    head = new node;

    head->data=A[0];
    head->next=head;
    tail=head;

    for ( i = 1; i < n; i++)
    {
        t = new node;
        t->data=A[i];
        t->next=tail->next;
        tail->next=t;
        tail=t;
    }
}

void CircularLL::Display(){
    node *p = head;

    do
    {
        cout<<p->data<<" ";
        p=p->next;
    } while (p!=head);
    
}

void CircularLL::RDisplay(node *p){

    static int flag =0;

    if (p!=head || flag == 0)
    {
        flag =1;
        cout<<p->data<<" ";
        RDisplay(p->next);
    }
    flag=0;    
}

int main() {

    int A[]={1,2,3,4,5};
    CircularLL c(A,5);
    c.Display();
    cout<<endl;
    node *h = c.gethead();
    c.RDisplay(h);
    
    return 0;
}