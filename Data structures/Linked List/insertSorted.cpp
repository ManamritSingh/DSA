// code to insert in a sorted linked list

#include <iostream>
using namespace std;

class node{
    public:

    int data;
    node *next;
};

class linkedlist{
public:
     node *first ;

    linkedlist(){

        first = NULL;
    }

    void create(int A[] , int n){
        node *t , *last;

        first = new node;
        first->data = A[0];
        first->next = NULL;
        last=first;

        for (int i = 1; i < n; i++)
        {
            t = new node;
            t->data=A[i];
            t->next=NULL;

            last->next = t;
            last=t;
        }
    }

     void display(node *p){

        while (p!= NULL)
        {
            cout<<p->data<<" ";
            p=p->next;
        }
        cout<<endl;
    }

     void sortedInsert(node *p , int n){

        node *t , *q = NULL;
        t = new node;
        t->data=n;
        t->next=NULL;
        if (first == NULL)
        {
            first=t;
        }
        else{
            while (p->data < n && p!= NULL)
            {
                q=p;
                p=p->next;
            }
            if (p==first)
            {
                t->next = first->next;
                first=t;
            }
            else
            {
                t->next=q->next;
                q->next = t;
            }    
        }
     }
};

int main() {
    int A[]={1,2,3,5,6};
    linkedlist l;
    l.create(A , 5);
    l.display(l.first);
    l.sortedInsert(l.first , 4);
    l.display(l.first);
    
    return 0;
}