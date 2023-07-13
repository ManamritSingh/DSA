#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
};



int main(){

    // initialised nodes
    node* head;
    node* one = NULL;
    node* two = NULL;
    node* three = NULL;

    // allocating nodes in heap
    one = new node();
    two = new node();
    three = new node();

    // assign data values
    one->data=1;
    two->data=2;
    three->data=3;

    // now connect the nodes
    one->next=two;
    two->next=three;
    three->next=NULL;

    //now print LL values

    head=one;
    while (head != NULL)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
    
    return 0;
}