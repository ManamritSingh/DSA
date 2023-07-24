// code to convert std infix expressions to postfix

#include <iostream>
#include <cstring>
using namespace std;

class node {
public:
    char data;
    node* next;
};

class stack {
private:
    node* top;

public:
    stack() {
        top = nullptr;
    }
    void push(char n);
    char pop();
    void display();
    int isfull();
    int isempty();
    char stacktop();
    char peek(int index);
    int operatorcheck(char a);
    int precedence(char a);
    char* infixToPostfix(const char* str);
};

void stack::push(char n) {
    node* t = new node;

    if (t == nullptr)
        cout << "stack overflow";
    else {
        t->data = n;
        t->next = top;
        top = t;
    }
}

char stack::pop() {
    char x = -1;
    if (top == nullptr) {
        cout << "stack empty";
    } else {
        node* t = top;
        x = t->data;
        top = t->next;
        delete t;
    }
    return x;
}

void stack::display() {
    node* p = top;

    while (p != nullptr) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int stack::isfull() { // kaafi faltu
    node* t = new node;
    if (t == nullptr) {
        return 1;
    } else
        return 0;
}

int stack::isempty() {
    if (top == nullptr) {
        return 1;
    }
    return 0;
}

char stack::peek(int index) {
    int x = -1;

    node* p = top;
    for (int i = 0; i < index - 1; i++) {
        p = p->next;
    }
    if (index < 0 || p == nullptr) {
        cout << "invalid index" << endl;
    } else {
        x = p->data;
    }
    return x;
}

char stack::stacktop() {
    if (top == nullptr) {
        return -1;
    }
    return top->data;
}

int stack::operatorcheck(char a) { // checks for operators
    if (a == '+' || a == '-' || a == '*' || a == '/') {
        return true;
    } else
        return false;
}

int stack::precedence(char a) {
    if (a == '+' || a == '-') {
        return 1;
    } else if (a == '*' || a == '/') {
        return 2;
    } else
        return 0;
}

char* stack::infixToPostfix(const char* str) {
    int i = 0, j = 0;
    char* postfix = new char[strlen(str) + 1];

    while (str[i] != '\0') {
        if (!operatorcheck(str[i])) {
            postfix[j++] = str[i++];
        } else {
            while (!isempty() && precedence(str[i]) <= precedence(stacktop())) {
                postfix[j++] = pop();
            }
            push(str[i++]);
        }
    }
    while (!isempty()) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';

    return postfix;
}

int main() {
    const char* exp = "a+b*c-d";

    stack st;
    char* postfix = st.infixToPostfix(exp);
    cout << postfix << endl;

    delete[] postfix;

    return 0;
}
