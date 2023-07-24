// creating queue

#include <iostream>
using namespace std;

class queue{
    private:
        int front;
        int rear;
        int size;
        int *q;
    public:
        queue(int size);
        ~queue();
        void enqueue(int x);
        int dequeue();
        void display();
        int isfull();
        int isempty();
        void create();
};

queue::queue(int size){
    this->size=size;
    front=rear=-1;
    q = new int[size];
}

int queue::isfull(){

    if (rear == size -1)
    {
        return true;
    }
    else{
        return false;
    }
}

int queue::isempty(){

    if (front == rear)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void queue::enqueue(int x){

    if (isfull())
    {
        cout<<"Queue is full"<<endl;
    }
    else{
        rear++;
        q[rear]=x;
    }
}

int queue::dequeue(){

    int x = -1;
    if (isempty())
    {
        cout<<"Queue is empty"<<endl;
    }
    else{
        front++;
        x = q[front];
    }
    return x;
}

void queue::display(){
    for (int i = front+1; i <=rear ; i++)
    {
        cout<<q[i]<<" ";
    }
    cout<<endl;
}

queue::~queue(){
    delete []q;
}

void queue::create(){

    int x=0;

    for (int i = 0; i < size; i++)
    {
        cout<<"Enter element : "<<i+1<<" "<<endl;
        cin>>x;
        enqueue(x);
    } 
}


int main() {

    queue q(5);
    q.create();
    q.display();
    q.enqueue(3);
    q.dequeue();
    q.display();
    q.enqueue(3);
    q.display();
    return 0;
}