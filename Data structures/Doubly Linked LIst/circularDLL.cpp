// code to create display and insert / delete 

// creta lenk lest

#include <iostream>
using namespace std;

class node{
    public :
        node *prev;
        int data;
        node *next;
};

class CDLL{ // circular doubly linked list

private:
    node *head;

public:
    CDLL();
    CDLL(int A[] , int n);
    //~CDLL();
    void Display();
    int length();
    void insert(int index , int n);
    void deleteNode(int index);
};

CDLL::CDLL() {
    head = new node;
    head->prev = nullptr;
    head->data = 0;
    head->next = nullptr;
}

CDLL::CDLL(int A[] , int n){

    head = new node;
    head->prev=head;
    head->data=A[0];
    head->next=head;
    node* tail =head;

    for (int i = 1; i < n; i++)
    {
        node *t = new node;
        t->prev = tail;
        t->data = A[i];
        t->next = head;
        tail->next =t;
        head->prev=t;
        tail =t;
    }
}

void CDLL::Display(){
    node *p = head;
    do
    {
        cout<<p->data<<" ";
        p=p->next;
    }while(p!=head);
    cout<<endl;
}

int CDLL::length(){
    node *p =head;
    int len =0;
    do
    {
        len++;
        p=p->next;
    }while(p!=head);
    return len;
}

void CDLL::insert(int index, int n) {
    if (index < 0 || index > length()) {
        return;
    }

    node* t = new node;
    t->data = n;

    if (head == nullptr) {
        head = t;
        head->next = head;
        head->prev = head;
    }
    else if (index == 0) {
        t->next = head;
        t->prev = head->prev;
        head->prev->next = t;
        head->prev = t;
        head = t;
    }
    else {
        node* p = head;
        for (int i = 0; i < index - 1; i++) {
            p = p->next;
        }
        t->next = p->next;
        t->prev = p;
        p->next->prev = t;
        p->next = t;
    }
}

void CDLL::deleteNode(int index){

    if (index<0 || index > length())
    {
        return;
    }
    node*p = head;
    int i , x;
    if (index == 1)
    {
        head = head->next;
        p->prev->next=p->next;
        p->next->prev=p->prev;
        x=p->data;
        delete p;
    }
    else
    {
        for (i = 0; i < index -1 ; i++)
        {
            p=p->next;
        }
        p->prev->next=p->next;
        p->next->prev=p->prev;
        x=p->data;
        delete p;
    }
}


int main() {

    int A[]={1,2,3,4,5};
    CDLL c(A,5);
    c.Display();
    c.deleteNode(1);
    c.Display();
    return 0;
}