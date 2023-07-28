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

class tree
{
private:
    Node *root;

public:
    tree() { root = nullptr; }

    void createTree();
    void preorder() { preorder(root); }
    void preorder(Node *p);
    void inorder() { inorder(root); }
    void inorder(Node *p);
    void postorder() { postorder(root); }
    void postorder(Node *p);
    void levelorder() { levelorder(root); }
    void levelorder(Node *p);
    int height() { return height(root); }
    int height(Node *p);

    int search(int A[], int m, int n, int x);
    Node *uniqueTree(int P[], int I[], int m, int n);

    ~tree() {
    // Call a function to delete the tree nodes recursively
    if (root)
        deleteTree(root);
}

    int deleteTree(Node *p) {
    if (p) {
        deleteTree(p->lchild);
        deleteTree(p->rchild);
        delete p;
    }
}

};

// functions of this very code

int tree::search(int A[], int m, int n, int x)
{
    for (int i = m; i <= n; i++)
    {
        if (A[i] == x)
        {
            return i;
        }
    }
    return -1;
}

Node *tree::uniqueTree(int P[], int I[], int m, int n)
{
    static int i = 0;
    int k;
    if (m > n)
    {
        return NULL;
    }
    Node *t = new Node;
    t->data = P[i];
    i++;
    if (m == n)
    {
        return t;
    }
    else
    {
        k = search(I, m, n, t->data);
        t->lchild = uniqueTree(P, I, m, k - 1);
        t->rchild = uniqueTree(P, I, k + 1, n);
        return t;
    }
}

void tree::createTree()
{
    Node *p, *t;
    int x;

    Queue q(25);
    root = new Node;
    cout << "Enter root value" << endl;
    cin >> x;
    root->data = x;
    root->lchild = root->rchild = nullptr;
    q.enqueue(root);

    while (!q.isEmpty())
    {
        p = q.dequeue();

        cout << "Enter left child of " << p->data << ": ";
        cin >> x;

        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = nullptr;
            p->lchild = t;
            q.enqueue(t);
        }

        cout << "Enter right child of " << p->data << ": ";
        cin >> x;
        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = nullptr;
            p->rchild = t;
            q.enqueue(t);
        }
    }
}

void tree::preorder(Node *p)
{
    if (p)
    {
        cout << p->data << " ";
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

void tree::inorder(Node *p)
{
    if (p)
    {
        inorder(p->lchild);
        cout << p->data << " ";
        inorder(p->rchild);
    }
}

void tree::postorder(Node *p)
{
    if (p)
    {
        postorder(p->lchild);
        postorder(p->rchild);
        cout << p->data << " ";
    }
}

void tree::levelorder(Node *p)
{
    if (p == nullptr)
        return;

    int totalNodes = 0;
    Queue q(100); // Set an initial size, it will dynamically expand if needed
    q.enqueue(p);

    while (!q.isEmpty())
    {
        p = q.dequeue();
        cout << p->data << " ";

        if (p->lchild)
        {
            q.enqueue(p->lchild);
            totalNodes++;
        }
        if (p->rchild)
        {
            q.enqueue(p->rchild);
            totalNodes++;
        }
    }
}


int tree::height(Node *p)
{
    int l = 0, r = 0;

    if (p == nullptr)
    {
        return 0;
    }
    l = height(p->lchild);
    r = height(p->rchild);

    if (l > r)
    {
        return l + 1;
    }
    else
    {
        return r + 1;
    }
}


int main()
{
    tree bt;
    int preorder[] = {4, 7, 9, 6, 3, 2, 5, 8, 1};
    int inorder[] = {7, 6, 9, 3, 4, 5, 8, 2, 1};

    Node *tr = bt.uniqueTree(preorder, inorder, 0, 8);

    cout << "Level-order Traversal: ";
    bt.levelorder(tr);
    cout << endl;

    return 0;
}
