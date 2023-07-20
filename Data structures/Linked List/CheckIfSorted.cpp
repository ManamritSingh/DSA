// code to check if a ll is sorted or not

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

    int checksort(node *p){

        int x = INT32_MIN;

        while (p != NULL)
        {
            if (p->data < x)
            {
                cout<<"Not sorted";
                return false;
            }
            else
            {
                x = p->data;
                p=p->next;
            }
        }
        cout<<"sorted";
        return true;
        
    }
};

int main() {
    int A[]={1,2,3,52,6};
    linkedlist l;
    l.create(A , 5);
    l.display(l.first);
    l.checksort(l.first);
    
    return 0;
}