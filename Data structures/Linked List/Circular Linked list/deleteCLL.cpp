// delete from a circular linked list

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
    int deleteLL(int pos );
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

int CircularLL::deleteLL(int pos){
    node *p , *q;
    int i , x;
    if (pos<0 || pos> length())
    {
        return -1;
    }
    if (pos==1)
    {
        p = head;
        while (p->next != head)
        {
            p=p->next;
        }
        x = p->data;
        if (p==head)
        {
            delete head;
            head = NULL;
        }
        else{
            p->next=head->next;
            delete head;
            head=p->next;
        }
    }
    else
    {
        for ( i = 0; i < pos-2; i++)
        {
            p=p->next;
        }
        q=p->next;
        x = q->data;
        p->next=q->next;
        delete q;
    }
    return x;
}

int main() {

    int A[]={1,2,3,4,5};
    CircularLL c(A,5);
    c.Display();
    c.deleteLL(5);
    c.Display();

    return 0;
}