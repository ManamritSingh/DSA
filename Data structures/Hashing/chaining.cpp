#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
};

class hashtable{
    public:
        node** ht;
        hashtable();
        ~hashtable();
        int hashkey(int key);
        void insert(int key);
        int search(int key);
};

hashtable::hashtable(){
    ht = new node*[10]; // 0 to 9
    for (int i = 0; i < 10; i++)
    {
        ht[i]==nullptr;
    }
    
}

int hashtable::hashkey(int key){
    return key%10;  //returns the key in hashtable 
}

void hashtable::insert(int key){
    int htidx = hashkey(key); 
    node* t = new node;
    t->data=key;
    t->next=nullptr;

    // no nodes in this ll

    if (ht[htidx]==nullptr)
    {
        ht[htidx]=t;
    }
    else{
        node* p = ht[htidx];
        node* q = ht[htidx];

        while (p && p->data < key)
        {
            q=p;
            p=p->next;
        }
        if (q == ht[htidx]) // condition if key to be inserted at 1st position
        {
            t->next = ht[htidx];
            ht[htidx]=t;
        }
        else{
            t->next=q->next;
            q->next=t;
        }
        
    }
}

int hashtable::search(int key){
    int htidx = hashkey(key);
    node *p = ht[htidx];
    while (p)
    {
        if (key == p->data)
        {
            return p->data;
        }
        p=p->next;
    }
    return -1;
}

hashtable::~hashtable(){
    for (int i = 0; i < 10; i++)
    {
        node*p = ht[i];
    
    while (ht[i])
    {
        ht[i]=ht[i]->next;
        delete p;
        p=ht[i];
    }
    }
    delete [] ht;
}
int main() {
    int A[] = {16, 12, 25, 39, 6, 122, 5, 68, 75};
	int n = sizeof(A)/sizeof(A[0]);
	hashtable H;
	for (int i=0; i<n; i++){
		H.insert(A[i]);
	}

    cout<<"successfull Search"<<endl;
    int key = 6;
    cout<<H.search(key)<<endl;

    cout<<"unsuccessfull Search"<<endl;
    key = 65;
    cout<<H.search(key)<<endl;
    return 0;
}