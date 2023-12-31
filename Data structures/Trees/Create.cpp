// to create a tree

#include <iostream>
using namespace std;

class Node
{
public:
    Node *lchild;
    int data;
    Node *rchild;
};

class Queue
{
private:
    int size;
    int front;
    int rear;
    Node **Q; // [Node*]*: Pointer to [Pointer to Node]
public:
    Queue(int size);
    ~Queue();
    bool isFull();
    bool isEmpty();
    void enqueue(Node *x);
    Node *dequeue();
};

Queue::Queue(int size)
{
    this->size = size;
    front = -1;
    rear = -1;
    Q = new Node *[size];
}

Queue::~Queue()
{
    delete[] Q;
}

bool Queue::isEmpty()
{
    if (front == rear)
    {
        return true;
    }
    return false;
}

bool Queue::isFull()
{
    if (rear == size - 1)
    {
        return true;
    }
    return false;
}

void Queue::enqueue(Node *x)
{
    if (isFull())
    {
        cout << "Queue Overflow" << endl;
    }
    else
    {
        rear++;
        Q[rear] = x;
    }
}

Node *Queue::dequeue()
{
    Node *x = nullptr;
    if (isEmpty())
    {
        cout << "Queue Underflow" << endl;
    }
    else
    {
        front++;
        x = Q[front];
    }
    return x;
}

// **********tree**************

class tree{
    private: 
        Node* root;
    public:
        tree(){root == nullptr;}
        ~tree();

        void createTree();
        void preorder(){ preorder(root);}
        void preorder(Node *p);
        void inorder(){inorder(root);}
        void inorder(Node *p);
        void postorder(){postorder(root);}
        void postorder(Node *p);
        void levelorder(){levelorder(root);}
        void levelorder(Node *p);
        int height(){return height(root);}
        int height(Node *p);

    
};

void tree::createTree(){
    Node *p , *t;
    int x;

    Queue q(25);
    root = new Node ;
    cout<<"Enter root value"<<endl;
    cin>>x;
    root->data=x;
    root->lchild=root->rchild=nullptr;
    q.enqueue(root);

    while (!q.isEmpty())
    {
        p = q.dequeue();

        cout<<"Enter left child of "<<p->data<<": ";
        cin>>x;

        if(x!=-1){
            t = new Node;
            t->data=x;
            t->lchild=t->rchild=nullptr;
            p->lchild=t;
            q.enqueue(t);
        }

        cout<<"Enter right child of "<<p->data<<": ";
        cin>>x;
        if (x != -1)
        {
            t = new Node;
            t->data=x;
            t->lchild=t->rchild=nullptr;
            p->rchild=t;
            q.enqueue(t);
        } 
    } 
}

void tree::preorder(Node *p){
    if(p){
        cout<<p->data<<" ";
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

void tree::inorder(Node *p){
    if (p)
    {
        inorder(p->lchild);
        cout<<p->data<<" ";
        inorder(p->rchild);
    }
}

void tree::postorder(Node *p){
    if (p)
    {
        postorder(p->lchild);
        postorder(p->rchild);
        cout<<p->data<<" ";
    }
}

void tree::levelorder(Node *p){ // procedure for level order
    Queue q(100);
    cout<<root->data<<" ";
    q.enqueue(root);

    while (! q.isEmpty())
    {
        p = q.dequeue();
        if (p->lchild)
        {
            cout<<p->lchild->data<<" ";
            q.enqueue(p->lchild);
        }
        if (p->rchild)
        {
            cout<<p->rchild->data<<" ";
            q.enqueue(p->rchild);
        }
    }
}

int tree::height(Node *p){
    int l =0, r =0;

    if (p==nullptr)
    {
        return 0;
    }
    l = height(p->lchild);
    r = height(p->rchild);

    if(l>r){
        return l+1;
    }
    else{
        return r+1;
    }
    
}

tree::~tree(){
    cout<<endl;
}

int main(){
    tree t;
    t.createTree();
    cout<<"levelorder"<<endl;
    t.levelorder();
    //cout<<endl;
    //cout<<"inorder"<<endl;
    //t.inorder();
    //cout<<endl;
    //cout<<"postorder"<<endl;
    //t.postorder();
    //cout<<endl;

}
