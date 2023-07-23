// program for a stack implemented in LL

#include <iostream>
using namespace std;

class node{
    public:
        char data;
        node *next;
};

class stack{
    private:
    node *top;
public:
    stack(){
        top=nullptr;
    }
    void push(char n);
    char pop();
    void display();
    int isfull();
    int isempty();
    char stacktop();
    char peek(int index);
    int balanceCheck(const char *str);
};

void stack::push(char n){

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

char stack::pop(){
    char x= -1;
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

char stack::peek(int index){
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

char stack::stacktop(){

    if (top==nullptr)
    {
        return -1;
    }
        return top->data;
}

int stack::balanceCheck(const char *str){

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i]=='('  || str[i]=='[' || str[i]=='{')
        {
            push(str[i]);
        }
        else if (str[i]==')')
        {
            if (isempty())
            {
                return -1;
            }
            else
            {
                if (pop()=='(')
                {
                    continue;
                }
                else{
                    return -1;
                }
                
            }
        }
        else if (str[i]==']')
        {
            if (isempty())
            {
                return -1;
            }
            else
            {
                if (pop()=='[')
                {
                    continue;
                }
                else{
                    return -1;
                }
                
            }
        } 
        else if (str[i]=='}')
        {
            if (isempty())
            {
                return -1;
            }
            else
            {
                if (pop()=='{')
                {
                    continue;
                }
                else{
                    return -1;
                }    
            }
        }    
    }
    if (isempty())
    {
        return 1;
    }
    else
    {
        return -1;
    }
}


int main() {
    int n;

    const char *exp = "([a+b]*{c-d])";

    stack st;
    cout<<st.balanceCheck(exp);

    return 0;
}