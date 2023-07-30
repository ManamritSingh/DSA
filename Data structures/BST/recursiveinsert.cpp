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

int main() {
    bst b;
    b.insert(4);
    b.insert(1);
    b.insert(3);
    b.insert(10);
    b.insert(7);

    b.inorder();
    cout << endl;

    node* temp;
    temp = b.search(10);

    if (temp) {
        cout << "Element found: " << temp->data;
    } else {
        cout << "Not Found";
    }

    return 0;
}
