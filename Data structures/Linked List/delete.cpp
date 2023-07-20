// deleting a node from a ll

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

    int deletenode (node *p , int pos){
        node *q=NULL;
        int x = -1 , i;

        if (pos == 1)
        {
            x = first->data;
            p=first;
            first=first->next;
            delete p;
        }
        else
        {
            for (i = 0; i < pos - 1 && p ; i++)
            {
                q=p;
                p=p->next;
            }
            if (p!= NULL)
            {
                q->next = p->next;
                x = p->data;
                delete p;
            }
        }
        return x;
    }
};

int main() {
    int A[]={1,2,3,5,6};
    linkedlist l;
    l.create(A , 5);
    l.display(l.first);
    l.deletenode(l.first , 5);
    l.display(l.first);
    
    return 0;
}