#include <iostream>
using namespace std;

class node{
    public:
    node* lchild;
    node *rchild;
    int data;
    int height;
    
};

class avl{
    private:
    node * root;

    public:
    avl(){root = nullptr;}
    node* getroot(){return root;}
    node* insert(node *p , int key);
    int nodeHeight(node *p);
    int balancefactor(node *p);
    node* LLrotation(node *p); 
    node* LRrotation(node *p);
    node* RRrotation(node *p);
    node* RLrotation(node *p);
};

node* avl::insert(node* p, int key) {
    if (p == nullptr) {
        node* t = new node;
        t->data = key;
        t->height=1;
        t->lchild = t->rchild = nullptr;
        //root=t;
        return t;
    }

    if (key < p->data) {
        p->lchild = insert(p->lchild, key);
    } else if (key > p->data) {
        p->rchild = insert(p->rchild, key);
    }
    p->height=nodeHeight(p);

    if (balancefactor(p)==2 && balancefactor(p->lchild)==1) // condition for LL rotation
    {
        return LLrotation(p);
    }
    else if (balancefactor(p)==2 && balancefactor(p->lchild)==-1)
    {
        return LRrotation(p);
    }
    else if (balancefactor(p)==-2 && balancefactor(p->lchild)==-1)
    {
        return RRrotation(p);
    }
    else if (balancefactor(p)==-2 && balancefactor(p->lchild)==1)
    {
        return RLrotation(p);
    }
    return p;
}

int avl::balancefactor(node* p){
    int hl , hr;
    hl=p && p->lchild ? p->lchild->height:0;
    hr=p && p->rchild ? p->rchild->height:0;

    return hl-hr;
}


int avl::nodeHeight(node *p){
    int hr , hl;
    hl=p && p->lchild ? p->lchild->height:0;
    hr=p && p->rchild ? p->rchild->height:0;

    return hl>hr?hl+1:hr+1;

}

node* avl::LLrotation(node* p){

    node *pl=p->lchild;
    node *plr=pl->rchild;
// changes to nodes 
    pl->rchild=p;
    p->lchild=plr;
    p->height=nodeHeight(p);
    pl->height=nodeHeight(pl);
    if (root==p)
    {
        root=pl;
    }
    return pl;
}

node* avl::LRrotation(node* p){
    
    node* pl = p->lchild;
    node *plr = pl->rchild;

    // changes

    p->lchild=plr->rchild;
    pl->rchild=plr->lchild;
    plr->lchild=pl;
    plr->rchild=p;

    p->height=nodeHeight(p);
    pl->height=nodeHeight(pl);
    plr->height=nodeHeight(plr);

    if (p==root)
    {
        plr=root;
    }
    return plr;
}

node* avl::RRrotation(node* p){
    
    node* pr = p->rchild;
    node* prl = pr->lchild;

    pr->lchild = p;
    p->rchild = prl;

    // Update height
    p->height = nodeHeight(p);
    pr->height = nodeHeight(pr);

    // Update root
    if (root == p){
        root = pr;
    }
    return pr;
}

node* avl::RLrotation(node* p){
    
    node* pr = p->rchild;
    node* prl = pr->lchild;
 
    pr->lchild = prl->rchild;
    p->rchild = prl->lchild;
 
    prl->rchild = pr;
    prl->lchild = p;
 
    // Update height
    pr->height = nodeHeight(pr);
    p->height = nodeHeight(p);
    prl->height = nodeHeight(prl);
 
    // Update root
    if (root == p){
        root = prl;
    }
    return prl;
}

int main() {

    avl tr;
    tr.insert(tr.getroot() , 10);
    tr.insert(tr.getroot() , 5);
    tr.insert(tr.getroot() , 2);

    cout<<tr.nodeHeight(tr.getroot());
    
    return 0;
}