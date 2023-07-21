// code to insert in a circular linked list

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
    void insert(int pos , int x);
    int length();


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
    cout<<endl;
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

int CircularLL::length(){
    node *p =head;
    int len=0;
    do
    {
        len++;
        p=p->next;
    } while (p!=head);
    return len;
}

void CircularLL::insert(int pos , int x){

    node *t , *p;
    int i;

    if (pos<0 || pos > length())
    {
        return;
    } 
    if (pos==0)
    {
        t = new node;
        t->data = x;

        if (head == NULL)
        {
            head=t;
            head->next=head;
        }
        else{
            p =head;
            while (p->next != head)
            {
                p=p->next;
            }
            p->next =t;
            t->next=head;
            head =t;
        }   
    }
    else{
        p=head;
        for (i = 0; i < pos-1; i++)
        {
            p=p->next;
        }
        t= new node;
        t->data=x;
        t->next=p->next;
        p->next=t;   
    }
}

int main() {

    int A[]={1,2,3,4,5};
    CircularLL c(A,5);
    c.Display();
    c.insert(5,9);
    c.Display();

    return 0;
}