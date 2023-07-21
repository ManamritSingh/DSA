// delete a node from a doubly ll

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
    int deletenode(int index);
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

int doublyLL::deletenode(int index){

    node *p =head;
    int x=-1;
    if (index <0 || index > length())
    {
        return -1;
    }
    

    if (index == 1)
    {
        x = head->data;
        if (head->next)
        {
            head=head->next;
            head->prev=nullptr;
            delete p;
        }
        else
        {
            delete p;
        }
    }
    else{
        for (int i = 0; i < index -1 ; i++)
        {
            p=p->next;
        }
        x = p->data;
        p->prev->next=p->next;
        if (p->next)
        {
            p->next->prev=p->prev;
        }
        delete p;
    }
    return x;
}


int main() {

    int A[]={1};
    doublyLL c(A,1);
    c.Display();
    cout<<c.deletenode(1)<<endl;
    c.Display();
    return 0;
}