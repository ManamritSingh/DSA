// creta lenk lest

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


int main() {

    int A[]={1,2,3,4,5};
    doublyLL c(A,5);
    c.Display();
    cout<<"length is "<<c.length()<<endl;
    return 0;
}