// delete duplicate elements from ll

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

    void duplicate(node *p){

        node *q ;
        q= p->next;

        while (q!= NULL)
        {
            if (p->data != q->data)
            {
                p=q;
                q=q->next;
            }
            else
            {
                p->next=q->next;
                delete q;
                q=p->next;
            }   
        }
        
    }
};

int main() {
    int A[]={1,1,2,2,3,3};
    linkedlist l;
    l.create(A , 5);
    l.display(l.first);
    l.duplicate(l.first);
    l.display(l.first);
    
    return 0;
}