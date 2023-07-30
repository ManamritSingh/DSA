// delete a leaf

#include <iostream>
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
    node* insert(node* p, int key);
    void inorder() { inorder(getroot()); }
    void inorder(node* t);
    node* search(int key);

    node* deleten(node* p ,int key);
    int height(node *p);
    node* inpre(node *p);
    node * insucc(node *p);
};

void bst::insert(int key) {
    root = insert(root, key);
}

node* bst::insert(node* p, int key) {
    if (p == nullptr) {
        node* t = new node;
        t->data = key;
        t->lchild = t->rchild = nullptr;
        return t;
    }

    if (key < p->data) {
        p->lchild = insert(p->lchild, key);
    } else if (key > p->data) {
        p->rchild = insert(p->rchild, key);
    }

    return p;
}

void bst::inorder(node* t) {
    if (t) {
        inorder(t->lchild);
        cout << t->data << " ";
        inorder(t->rchild);
    }
}

node* bst::search(int key) {
    node* t = root;

    while (t) {
        if (t->data == key) {
            return t;
        } else if (t->data > key) {
            t = t->lchild;
        } else {
            t = t->rchild;
        }
    }

    return nullptr;
}

int bst::height(node *p) {
    if (p == nullptr)
        return -1; 

    int x = height(p->lchild);
    int y = height(p->rchild);
    return x > y ? x + 1 : y + 1;
}


node* bst::inpre(node* p){
    while (p && p->rchild!=nullptr)
    {
        p=p->rchild;
    }
    return p;
}

node* bst::insucc(node* p){
    while (p && p->lchild!=nullptr)
    {
        p=p->lchild;
    }
    return p;
}

node* bst::deleten(node *p , int key){
    node *q;

    if (p==nullptr)
    {
        return nullptr;
    }

    if (p->lchild == nullptr && p->rchild == nullptr)
    {
        if (p==root)
        {
            root=nullptr;
        }
        delete p;
        return nullptr;
    }

    if (key < p->data)
    {
        p->lchild = deleten(p->lchild , key);
    }
    else if (key>p->data)
    {
        p->rchild = deleten(p->rchild , key);
    }
    else
    {
        if (height(p->lchild) > height(p->rchild))
        {
            q=inpre(p->lchild);
            p->data=q->data;
            p->lchild=deleten(p->lchild , q->data);
        }
        else{
            q = insucc(p->rchild);
            p->data = q->data;
            p->rchild = deleten(p->rchild, q->data);
        }
    }
    return p;
}

int main() {
    bst b;
    b.insert(4);
    b.insert(1);
    b.insert(3);
    b.insert(10);
    b.insert(7);

    b.deleten(b.getroot() , 10);

    b.inorder();
    cout << endl;

    return 0;
}
