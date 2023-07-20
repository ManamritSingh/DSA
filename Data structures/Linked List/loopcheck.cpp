// code to check a loop in a linked list

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

    int loopcheck(node* f) {
    node* p, * q;
    p = q = f;

    do {
        p = p->next;
        q = q->next;
        q=q?q->next:q;

    } while (p && q && p != q);

    if (p == q) {
        return 1;
    } else {
        return 0;
    }
}
    
};

int main() {
    struct node *t1 , *t2;
    int A[]={10,20,25,27,30};
    linkedlist l;
    l.create(A , 5); 

    t1=l.first->next->next;
    t2=l.first->next->next->next->next;

    t2->next=t1;

    cout<<l.loopcheck(l.first)<<endl;
    
    return 0;
}