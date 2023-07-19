// code to return max element from a LL

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
    int maxloop(Node *p)
    {
        int max = INT32_MIN;
        while (p != NULL)
        {
            if (p->data > max)
            {
                max = p->data;
            } 
            p= p->next; 
        }
        return max;
    }

    int Rmax()
    {
        Rmax(first);
    }

    int Rmax(Node *p)
    {
        int x =0;
        if (p != NULL)
        {
           x = Rmax(p->next);
           if (p->data > x)
           {
            return p->data;
           }
           else {
            return x ;
           }  
        }
        else{
            return INT32_MIN;
        }
        
    }
};

int main()
{
    LinkedList L;
    int A[] = {3, 5, 7, 10, 25, 8, 32, 2};
    L.create(A, 8);

    cout<<"max element "<<L.Rmax()<<endl;

    cout<<"max using loop "<<L.maxloop(L.first)<<endl;

    return 0;
}