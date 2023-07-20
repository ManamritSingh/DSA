// code to merge 2 linked lists

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
     node *second;
     node *third;

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

    void create2(int A[] , int n){
        node *t , *last;

        second = new node;
        second->data = A[0];
        second->next = NULL;
        last=second;

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

    void merge(node *p , node *q){
        node *last;

        if (p->data < q->data)
        {
            third=last=p;
            p=p->next;
            third->next=NULL;
        }else
        {
            third=last=q;
            q=q->next;
            third->next=NULL; // third is new ll with 1 node as of now and its next points to nothing
        }

        while (p && q)
        {
            if (p->data < q->data)  
            {
                last->next=p; // last's next was null as seen previously , now it points on this newly found node
                last=p;       // now since this is a part of 3 , lets bring last here (this is the last element now)
                p=p->next;    // move p to next node of the old LL
                last->next=NULL; // and now since this node is the last node of third , its last nodeis next is assigned null
            }
            else{
                last->next=q;
                last=q;
                q=q->next;
                last->next=NULL;
            }  
        }
        if (p!=NULL)         // one of the ll will still have elements , so just join those elements at the end 
        {                    // keep in mind they wont be checked for order after this , and entirely will be copied(wrong word but u get it) as it is
            last->next = p;
        }
        if (q!=NULL)
        {
            last->next = q;
        }
    }
};

int main() {
    int A[]={10,20,30,40,50,49};
    int B[]={15,25,35,45};
    linkedlist l;
    l.create(A , 6); 
    l.create2(B, 4);
    l.display(l.first);
    l.display(l.second);
    l.merge(l.first , l.second);
    l.display(l.third);
    return 0;
}