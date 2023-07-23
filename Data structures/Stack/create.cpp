// creating a stack;

#include <iostream>
using namespace std;

class stack{
    private:
        int size;
        int top;
        int *s;

    public:
        stack(int size);
        ~stack();
        void push(int x);
        int pop();
        int peek(int index);
        int isfull();
        int isempty();
        int stacktop();
        void display();
};

stack::stack(int size){
    this->size=size;
    s = new int[size];
    top = -1;
}

stack::~stack(){
    delete []s;
}

int stack::isfull(){
    if (top == size -1)
    {
        return 1;
    }
    else
        return 0;
    
}

int stack::isempty(){
    if (top == -1)
    {
        return 1;
    }
    else
        return 0;
}

int stack::stacktop(){
    if (top== -1)
    {
        cout<<"stack is empty"<<endl;
        return -1;
    }
    else
    {
        return s[top];
    }
}

void stack::push(int x){
    if (isfull())
    {
        cout<<"Stack overflow"<<endl;
    }
    else
    {
        top++;
        s[top]=x;
    }
}

int stack::pop(){
    int x=-1;

    if (isempty())
    {
        cout<<"Stack underflow"<<endl;
    }
    else
    {
        x = s[top];
        top--;
    }
    return x;
}

int stack::peek(int index){ // function to return element at index of stack which is different from index of array
    int x = -1;
    if (top - index + 1 < 0 || top - index + 1 > size-1)
    {
        cout<<"invalid index"<<endl;
    }
    else
    {
        x = s[top - index +1];
    }
    return x;
}

void stack::display(){
    for (int i = top ; i> -1; i--)
    {
        cout<<s[i]<<" ";
    }
    cout<<endl;
}


int main() {
    int n ;

    stack st(5);
    cout<<st.isempty()<<endl;
    cout<<"Enter size of stack";
    cin>>n;
    int A[n];
    cout<<"Enter elements";
    for (int i = 0; i < n; i++)
    {
        cin>>A[i];
    }
    for (int i = 0; i < n; i++)
    {
        st.push(A[i]);
    }
    st.display();

    cout<<st.isfull()<<endl;

    // test push pop
    //st.pop();
    //st.display();
    //st.push(6);
    //st.display();

    // test peek
    cout<<st.peek(3)<<endl;
    cout<<st.stacktop();


    return 0;
}