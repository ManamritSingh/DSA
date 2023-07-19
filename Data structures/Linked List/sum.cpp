// code for sum of elements in a LL

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
    int sumloop(Node *p)
    {
        int sum =0;
        while (p != NULL)
        {
            sum+= p->data;
            p = p->next;
        }
        return sum;
    }

    int sum()
    {
        sum(first);
    }

    int sum(Node *p)
    {
        if (p != NULL)
        {
           return p->data + sum(p->next);
        }
        else{
            return 0;
        }
    }
};

int main()
{
    LinkedList L;
    int A[] = {3, 5, 7, 10, 25, 8, 32, 2};
    L.create(A, 8);

    cout<<"sum of elements are "<<L.sum()<<endl;

    cout<<"sum using loop "<<L.sumloop(L.first)<<endl;

    return 0;
}