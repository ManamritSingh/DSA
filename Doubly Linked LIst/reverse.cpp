// meagre try onli
//lets see if this is how they do

#include <iostream>
using namespace std;

class node{
    public :
        node *prev;
        int data;
        node *next;
};

class doublyLL{

private:
    node *head;

public:
    doublyLL();
    doublyLL(int A[] , int n);
    //~doublyLL();
    void Display();
    int length();
    void reverseDisplay();
    void actuallyReverse();
};

doublyLL::doublyLL() {
    head = new node;
    head->prev = nullptr;
    head->data = 0;
    head->next = nullptr;
}

doublyLL::doublyLL(int A[] , int n){

    head = new node;
    head->prev=nullptr;
    head->data=A[0];
    head->next=nullptr;
    node* tail =head;

    for (int i = 1; i < n; i++)
    {
        node *t = new node;
        t->prev = tail;
        t->data = A[i];
        t->next = tail->next;
        tail->next =t;
        tail =t;
    }
    
}

void doublyLL::Display(){
    node *p = head;
    if (head)
    {
    while (p != nullptr)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
    }
    else
    {
        cout<<"Empty LL";
    }
    
}

int doublyLL::length(){
    node *p =head;
    int len =0;
    while (p!= nullptr)
    {
        len++;
        p=p->next;
    }
    return len;
}

void doublyLL::reverseDisplay(){
    
    node *p =head;
    while (p->next != nullptr)
    {
        p=p->next;
    }
    
    while (p != nullptr)
    {
        cout<<p->data<<" ";
        p=p->prev;
    }
}

void doublyLL::actuallyReverse(){
    node *temp;
    node * p = head;

    while (p)
    {
        temp = p->next;
        p->next=p->prev;
        p->prev=temp;
        
        p=p->prev;
        if (p && p->next==nullptr)
        {
            head=p;
        }
    }
}


int main() {

    int A[]={1,2,3,4,5};
    doublyLL c(A,5);
    c.Display();
    //c.reverseDisplay();
    c.actuallyReverse();
    c.Display();
    return 0;
}