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
    void inorder() { inorder(getroot()); }
    void inorder(node* t);
    node* search(int key);
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

int main() {
    bst b;
    b.insert(3);
    b.insert(4);
    b.insert(1);
    b.insert(10);
    b.insert(7);

    b.inorder();
    cout<<endl;

    node* temp;
    temp = b.search(10);

    if (temp)
    {
        cout<<"Element found "<<temp->data;
    }
    else{
        cout<< "Not Found";
    }

    return 0;
}
