#include <iostream>
#include<stack>
using namespace std;

class node {
public:
    node* lchild;
    int data;
    node* rchild;
};

class bst {
private:
    node* root;

public:
    bst() {
        root = nullptr;
    }

    node* getroot() { return root; }
    void insert(int key);
    void inorder() { inorder(getroot()); }
    void inorder(node* t);
    node* search(int key);

    void createFromPreorder(int pre[] , int n);
};

void bst::insert(int key) {
    node* t = root;
    node* r = nullptr;
    node* p;

    if (root == nullptr) {
        p = new node;
        p->data = key;
        p->lchild = p->rchild = nullptr;
        root = p;
        return;
    }

    while (t) {
        r = t;

        if (t->data > key) {
            t = t->lchild;
        } else {
            t = t->rchild;
        }
    }

    p = new node;
    p->data = key;
    p->lchild = p->rchild = nullptr;
    if (r->data > p->data) {
        r->lchild = p;
    } else {
        r->rchild = p;
    }
}

void bst::inorder(node* t) {
    if (t) {
        inorder(t->lchild);
        cout << t->data << " ";
        inorder(t->rchild);
    }
}

node* bst::search(int key){

    node*t = root;
    
    while (t)
    {
        if (t->data==key)
        {
            return t;
        }
    
        else if (t->data>key)
        {
            t=t->lchild;
        }
        else{
            t=t->rchild;
        }
        
    }
    return nullptr;
}

void bst::createFromPreorder(int pre[] , int n){

    int i=0;
    root = new node;
    root->data=pre[i++];
    root->lchild=root->rchild=nullptr;

    node *t ;
    node *p = root;
    stack<node *> stk;

    while (i<n)
    {
        if (pre[i] < p->data)
        {
            t = new node;
            t->data=pre[i++];
            t->lchild=t->rchild=nullptr;
            p->lchild=t;
            stk.push(p);
            p=t;
        }
        else{
            if (pre[i] > p->data && pre[i] < (stk.empty() ? 32767 : stk.top()->data)  )
            {
                t= new node;
                t->data=pre[i++];
                t->lchild=t->rchild=nullptr;
                p->rchild=t;
                p=t;
            }
            else{
                p=stk.top();
                stk.pop();
            }
        }
    }
}

int main() {
    bst b;
    int arr[]={30 , 20 , 10 , 15 , 25 , 40 , 50 , 45};
    int n = sizeof(arr) / sizeof(arr[0]);

    b.createFromPreorder(arr , n);
    b.inorder(b.getroot());

    return 0;
}
