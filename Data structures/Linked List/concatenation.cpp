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
     node *second;

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

    int countloop(node *p)
    {
        int count =0;
        while (p != NULL)
        {
            count++;
            p = p->next;
        }
        return count;
    }

    void concat(node *p , node *q){

        p=first;
        while (p->next != NULL)
        {
            p=p->next;
        }
        p->next=second;
        second=NULL;
    }
};

int main() {
    int A[]={1,1,2,2,3};
    int B[]={1,2,3,4};
    linkedlist l;
    l.create(A , 5); 
    l.create2(B, 4);
    l.display(l.first);
    l.display(l.second);
    l.concat(l.first,l.second);
    l.display(l.first);
    
    return 0;
}