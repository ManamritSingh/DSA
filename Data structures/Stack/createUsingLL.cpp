// program for a stack implemented in LL

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

    stack st;
    cout<<"Enter size of stack"<<endl;
    cin>>n;
    int A[n];
    cout<<"Enter elements"<<endl;
    for (int i = 0; i < n; i++)
    {
        cin>>A[i];
    }
    for (int i = 0; i < n; i++)
    {
        st.push(A[i]);
    }
    st.push(1);
    st.push(2);
    st.display();

    st.pop();
    st.pop();

    st.display();

    cout<<st.stacktop()<<endl;
    cout<<st.isfull()<<endl;
    cout<<st.peek(4)<<endl;

    st.pop();
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    cout<<st.isempty()<<endl;
    
    return 0;
}