// display and create a LL

#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node* next;
};


int main() {
    int A[] = {3, 5, 7, 10, 15};

    node* head = new node;

    node* temp ;
    node* last;

    head->data = A[0];
    head->next = nullptr;
    last = head;

    // creating rest of LL

    for (int i = 1; i < sizeof(A)/sizeof(A[0]); i++)
    {
        temp = new node;

        temp->data =A[i];
        temp->next = nullptr;
        // last's next points to temp so that in next iteration of loop things get repeated and we get a new node of our LL
        last->next=temp;
        last = temp;
    }

    // code to display the ll
    node* p =head;

    while (p != nullptr)
    {
        cout<<p->data<<" "<<flush;
        p=p->next;
    }
    return 0;
}