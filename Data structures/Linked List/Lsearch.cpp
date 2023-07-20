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
Node* lsearchloop(Node* p, int key) {
    while (p != NULL) {
        if (p->data == key) {
            return p;
        }
        p = p->next;
    }
    return NULL; // Return NULL if the key is not found in the linked list
}

    Node * Rsearch(Node *p , int key)
    {
        if(p==NULL){
            return NULL;
        }
        if (key==p->data)
        {
            return p;
        }
        Rsearch(p->next,key);
    }
};

int main()
{
    LinkedList L;
    Node *temp;
    int A[] = {3, 5, 7, 10, 25, 8, 32, 2};
    L.create(A, 8);

    temp = L.Rsearch(L.first , 15);

    if (temp)
    {
        cout<<"key found "<<temp->data<<endl;
    }
    else{
        cout<<"Key not found"<<endl;
    }

    return 0;
}