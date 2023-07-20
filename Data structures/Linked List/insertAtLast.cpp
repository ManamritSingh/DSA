// in the prev inseert code we see that we need to insert at index 0 to start with
// this one uses a last pointer and takes care of inserting 
// though in this code we won't be able to insert within 2 nodes as it alwys does that at the end of the LL

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
    /*void create(int A[], int n)
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
    */
   // not required

    void display(Node *p){

        while (p!= NULL)
        {
            cout<<p->data<<" ";
            p=p->next;
        }
        cout<<endl;
    }
    Node *last = new Node; // declared outside of the func so it is a class pointer now

    void insert(Node *p ,int n){
        Node *t = new Node;

        t->data=n;
        t->next=NULL;

        if (first == NULL)
        {
            first=last=t;

        }
        else{
            last=p; // these lines mean to just move the last pointer to the end
            while(last->next)last=last->next; // these lines mean to just move the last pointer to the end
            last->next=t;
            last=t;

        }
    }
};

int main()
{
    LinkedList L;
    L.insert(L.first,1);
    L.insert(L.last,2);  // just changing to last decreases time complexity
    L.insert(L.last,3);
    L.insert(L.last,4);
    L.display(L.first);
    return 0;
}