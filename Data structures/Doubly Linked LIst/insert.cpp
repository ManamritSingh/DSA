// insert a node 

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
    void insert(int index, int x);
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
    while (p != nullptr)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
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

void doublyLL::insert(int index, int x){

    node *p , *t;
    p = head;

    if (index == 0){

        t = new node;
        t->prev=nullptr;
        t->data = x;
    
        if (head == nullptr)
        {
            head=t;
            head->next=nullptr;
        }
        else
        {
            t->next=head;
            head = t;  
        }
    }
    else
    {
        t = new node;
        for (int i = 0; i < index-1 ; i++)
        {
            p=p->next;
        }
        t->data=x;
        t->prev=p;
        t->next=p->next;
        p->next=t;

        if (p->next)
        {
            p->next->prev=t;
        }
    }
}


int main() {

    int A[]={1,2,3,4,5};
    doublyLL c(A,5);
    c.Display();
    c.insert(1,6);
    c.Display();
    return 0;
}