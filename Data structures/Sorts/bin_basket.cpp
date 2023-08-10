// bin or basket sort

#include <iostream>
using namespace std;

class node{
    public:
        int data;
        node* next;
};

int Findmax(int A[] , int n){
    int max = INT32_MIN;
    for (int i = 0; i < n; i++)
    {
        if (A[i] > max)
        {
            max= A[i];
        }
    }
    return max;
}

void insert(node** binptrs , int index){
    node * temp = new node;
    temp->data= index;
    temp->next = nullptr;

    if (binptrs[index] == nullptr)  // head condition
    {
        binptrs[index]=temp ;
    }
    else{
        node* p = binptrs[index];  // for subsequent nodes
        while (p->next != nullptr)
        {
            p=p->next;
        }
        p->next=temp;
    }
}

int deletenode(node** binptrs , int index){
    node* p = binptrs[index];
    binptrs[index]= binptrs[index]->next;
    int x = p->data;
    delete p;
    return x;
}

void binsort(int A[] , int n){
    int max = Findmax(A , n);

    node ** bins = new node* [max+1];

    for (int i = 0; i < max+1; i++)
    {
        bins[i]=nullptr;
    }

    for (int i = 0; i < n; i++)
    {
        insert(bins , A[i]);
    }

    int i =0 , j=0;

    while (i<max+1)
    {
        while (bins[i] != nullptr)
        {
            A[j++]=deletenode(bins , i);
        }
        i++;
    }
    
    delete [] bins;
    
}

int main() {
    int A[] = {2, 5, 8, 12, 3, 6, 7, 10};
    int n = sizeof(A)/sizeof(A[0]);

    binsort(A , n);

    for (int i = 0; i < n; i++)
    {
        cout<<A[i]<<" ";
    }
    
    return 0;
}