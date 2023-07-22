// student challenge to find the middle element of a ll

// there are two ways but we will use the one which incorporates only 1 scan

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

    int count()
    {
        count(first);
    }

    int count(Node *p)
    {
        if (p != NULL)
        {
           return 1 + count(p->next);
        }
        else{
            return 0;
        }
    }

    void middle(Node *p){

        Node *q = first;
        while (p!=nullptr)
        {
            p=p->next;
            if (p!=nullptr)
            {
                p=p->next;           
            }
            if (p!=nullptr)
            {
                q=q->next;           
            }
        }
        cout<<"Middle element is : "<<q->data<<endl;
        

    }
};

int main()
{
    LinkedList L;
    int A[] = {3, 5, 7, 10, 25, 8, 32, 2};
    L.create(A, 8);
    L.middle(L.first);

    return 0;
}