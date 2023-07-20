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

    // using array
    void reverse1(node *p){

        node *q=p;
        int i=0;
        int *B = new int[countloop(p)];

        while (q != NULL)
        {
            B[i]=q->data;
            q=q->next;
            i++;
        }
        q=p;
        i--;
        while (q!=NULL)
        {
            q->data=B[i];
            q= q->next;
            i--;
        }
    }

    // reversing the links

    void reverse2(node *p){

        node *q = NULL , *r = NULL;
        while (p!=NULL)
        {
            r=q;
            q=p;
            p=p->next;
            q->next=r;
        }
        q=first;
    }

    void reverse3(node *p , node *q){
        if(p){
            reverse3(p , p->next);
            p->next=q;
        }
        else{
            first=q;
        }
    }
};

int main() {
    int A[]={1,1,2,2,3};
    linkedlist l;
    l.create(A , 5); 
    l.display(l.first);
    l.reverse3(NULL,l.first);
    l.display(l.first);
    
    return 0;
}