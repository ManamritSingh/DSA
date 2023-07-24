#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node *next;
};

class queue{
    private:
        node* front;
        node *rear;
    public:
        queue();
        void enqueue(int x);
        int dequeue();
        void display();
        void create();
};

queue::queue(){
    front = nullptr;
    rear = nullptr;
}

void queue::enqueue(int x){

    node * t = new node;
    if (t == nullptr)
    {
        cout<<"queue full"<<endl;
    }
    else{
        t->data=x;
        t->next=nullptr;
        if (front==nullptr)
        {
            front = rear= t;
        }
        else{
            rear->next=t;
            rear=t;
        }
    } 
}

int queue::dequeue()
{
    int x = -1;
    if (front==nullptr)
    {
        cout<<"queue empty"<<endl;
    }
    else{
        node *p = front;
        front = front->next;
        x=p->data;
        delete p;
    }
    return x;
}

void queue::display(){

    node*p = front;

    while (p)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}

void queue::create(){
    int k ,x=0;
    cout<<"Enter no of elements"<<endl;
    cin>>k;

    for (int i = 0; i < k; i++)
    {
        cout<<"Enter element : "<<i+1<<" "<<endl;
        cin>>x;
        enqueue(x);
    } 
}

int main() {

    queue q;
    q.create();
    q.display();
    q.dequeue();
    q.display();
    q.enqueue(4);
    q.display();
    
    return 0;
}