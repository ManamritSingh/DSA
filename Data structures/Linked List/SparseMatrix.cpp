#include <iostream>
using namespace std;

class node{
    public:
        int col;
        int row;
        int data;
        node *next;
};

class SparseMatrix{
    public:

    node *head = nullptr;
    int m , n;

    SparseMatrix();
    void display();

};

SparseMatrix::SparseMatrix(){

    cout<<"Enter row and columns "<<endl;
    cin>>m>>n;

    node *A[m];
    node *p = nullptr , *q = nullptr;
    int data , i , j;

    cout<<"Enter matrix"<<endl;
    
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            cin>>data;

            if (data != 0)
            {
                p = new node;
                if (q!=nullptr)
                {
                    q->next=p;
                }
                else{
                    head=p;
                }
                p->col=j;
                p->row =i;
                p->data=data;
                p->next=nullptr;
                q=p;
            }
        }
    }
    
}

void SparseMatrix::display(){

    node *p =head;
    
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (p && p->col==i && p->row == j)
            {
                cout<<p->data<<" ";
                p=p->next;
            }
            else
            {
                cout<<"0 ";
            } 
        }
        cout<<endl;
        
    }
    cout<<endl;
}

int main() {
    SparseMatrix m;
    m.display();
    
    return 0;
}