// queue using 2 stacks

#include <iostream>
using namespace std;

class node{
    public:
        int data;
        node *next;
};

class stack{
    private:
    node *top;
public:
    stack(){
        top=nullptr;
    }
    void push(int n);
    int pop();
    void display();
    int isfull();
    int isempty();
    int stacktop();
    int peek(int index);
};

class queueUSingStack{
private:
    stack s1 , s2;

    public:
    queueUSingStack();
    void enqueue(int x);
    int dequeue();
    void displayQueue();
    void create();
};

queueUSingStack::queueUSingStack(){
    cout<<endl;
}

void queueUSingStack::create(){
    int x,k;
    cout<<"Enter no of elements"<<endl;
    cin>>x;
    cout<<"Enter your elements"<<endl;
    for (int i = 0; i < x; i++)
    {
        cin>>k;
        enqueue(k);
    }
}

void queueUSingStack::enqueue(int x){
    s1.push(x);
}

int queueUSingStack::dequeue(){
    int x = -1;
    if (s2.isempty())
    {
        if (s1.isempty())
        {
            cout<<"Queue Empty"<<endl;
            return x;
        }     
    }
    else{
            while (! s1.isempty())
            {
                s2.push(s1.pop());
            }
            x=s2.pop();
            return x;
        }
    s2.display();
    cout<<endl; 
    return x;
}

void queueUSingStack::displayQueue(){
    while (! s1.isempty())
            {
                s2.push(s1.pop());
            }
    s2.display();
}

void stack::push(int n){

    node*t = new node;

    if(t==nullptr)
        cout<<"stack overflow";
    else
    {
        t->data=n;
        t->next=top;
        top=t;
    }
}

int stack::pop(){
    int x= -1;
    node *t = new node;
    if (top==nullptr)
    {
        cout<<"stack empty";
    }
    else{
    t=top;
    x= t->data;
    top=t->next;
    delete t;
    }
    return x;
}

void stack::display(){

    node *p = top;

    while (p!=nullptr)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}

int stack::isfull(){      // kaafi faltu
    node *t = new node;
    if (t==nullptr)
    {
        return 1;
    }
    else
        return 0;
}

int stack::isempty(){

    if (top==nullptr)
    {
        return 1;
    }
    return 0;
}

int stack::peek(int index){
    int x=-1;

    node *p = new node;
    p=top;
    for (int i = 0; i < index-1; i++)
    {
        p=p->next;
    }
    if (index < 0 || p==nullptr )
    {
        cout<<"invalid index"<<endl;
    }
    else{
        x=p->data;
    }
    return x;
}

int stack::stacktop(){

    if (top==nullptr)
    {
        return -1;
    }
        return top->data;
}


int main() {
    int n;

    queueUSingStack q;
    q.create();
    q.displayQueue();
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;

    q.displayQueue();
    return 0;
}