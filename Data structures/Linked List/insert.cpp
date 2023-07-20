// 2 ways to insert 1. on index before the 1st node and 2. after any given node

// linear search with move to head

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
    Node *temp;
    int A[] = {3, 5, 7, 10, 25, 8, 32, 2};
    L.create(A, 8);
    L.display(L.first);
    L.insert(L.first , 3 , 12);
    L.display(L.first);
    L.insert(L.first , 0 , 1);
    L.display(L.first);
    return 0;
}