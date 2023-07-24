// queue made using array canm only be used once
// heres the fix

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
    front=rear=0;
    q = new int[size];
}

int queue::isfull(){

    if ((rear+1)%size == front)
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
        rear = (rear +1)%size;
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
        front=(front+1)%size;
        x = q[front];
    }
    return x;
}

void queue::display(){

    int i = front+1;
    do
    {
        cout<<q[i]<<" ";
        i=(i+1)%size;
    } while (i!=(rear+1)%size);
    
    cout<<endl;
}

queue::~queue(){
    delete []q;
}

void queue::create(){

    int x=0;

    for (int i = 0; i < size-1; i++)
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
// normal
/*
Enter element : 1 
1
Enter element : 2 
2
Enter element : 3 
3
Enter element : 4 
4
Enter element : 5 
5
1 2 3 4 5 
Queue is full
2 3 4 5
Queue is full
2 3 4 5
*/

// circular

/*
Enter element : 1 
1
Enter element : 2 
2
Enter element : 3 
3
Enter element : 4 
4
1 2 3 4 
Queue is full
2 3 4
2 3 4 3
*/