// normal code to create a ll using inserts


#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};
class LinkedList
{
public:
    Node *first;

    LinkedList()
    {
        first = NULL;
    }
    void create(int A[], int n)
    {
        int i;
        Node *t, *last;
        first = new Node;
        first->data = A[0];
        first->next = NULL;
        last = first;

        for (i = 1; i < n; i++)
        {
            t = new Node;
            t->data = A[i];
            t->next = NULL;
            last->next = t;
            last = t;
        }
    }

    void display(Node *p){

        while (p!= NULL)
        {
            cout<<p->data<<" ";
            p=p->next;
        }
        cout<<endl;
    }

    int countloop(Node *p)
    {
        int count =0;
        while (p != NULL)
        {
            count++;
            p = p->next;
        }
        return count;
    }

    void insert(Node *p , int index , int n){

        Node *t = new Node;

        if (index<0 || index> countloop(p))
        {
            return;
        }
        t->data=n;

        if (index==0)
        {
            t->next=first;
            first=t;
        }
        else{
            for (int i = 0; i < index-1; i++)
            {
                p=p->next;
            }
            t->next=p->next;
            p->next=t;
        }
        
        
    }
};

int main()
{
    LinkedList L;

    L.insert(L.first , 0 , 12); // in this case make sure to insert at index 0 to start
    L.insert(L.first , 1 , 2);
    L.insert(L.first , 2 , 24);
    L.insert(L.first , 3 , 32);

    L.display(L.first);
    return 0;
}