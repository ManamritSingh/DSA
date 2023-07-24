#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* next;
};

class queue {
private:
    node* front;
    node* rear;

public:
    queue();
    void enqueueRear(int x);
    void enqueueFront(int x);
    int dequeueFront();
    int dequeueRear();
    void display();
    void create();
};

queue::queue() {
    front = nullptr;
    rear = nullptr;
}

void queue::enqueueRear(int x) {
    node* t = new node;
    if (t == nullptr) {
        cout << "queue full" << endl;
    } else {
        t->data = x;
        t->next = nullptr;
        if (front == nullptr) {
            front = rear = t;
        } else {
            rear->next = t;
            rear = t;
        }
    }
}

void queue::enqueueFront(int x) {
    node* t = new node;
    if (t == nullptr) {
        cout << "queue full" << endl;
    } else {
        t->data = x;
        if (front == nullptr) {
            front = rear = t;
        } else {
            t->next = front;
            front = t;
        }
    }
}

int queue::dequeueFront() {
    int x = -1;
    if (front == nullptr) {
        cout << "queue empty" << endl;
    } else {
        node* p = front;
        front = front->next;
        x = p->data;
        delete p;
    }
    return x;
}

int queue::dequeueRear() {
    int x = -1;
    if (front == nullptr) {
        cout << "queue empty" << endl;
    } else {
        if (front == rear) {
            x = front->data;
            delete front;
            front = rear = nullptr;
        } else {
            node* p = front;
            while (p->next != rear) {
                p = p->next;
            }
            x = rear->data;
            delete rear;
            rear = p;
            rear->next = nullptr;
        }
    }
    return x;
}

void queue::display() {
    node* p = front;
    while (p != nullptr) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

void queue::create() {
    int k, x = 0;
    cout << "Enter no of elements" << endl;
    cin >> k;

    for (int i = 0; i < k; i++) {
        cout << "Enter element : " << i + 1 << " " << endl;
        cin >> x;
        enqueueRear(x);
    }
}

int main() {
    queue q;
    q.create();
    q.display();
    q.dequeueRear();
    q.display();
    q.enqueueFront(9);
    q.display();

    return 0;
}
// delete from rear is o(n) incase of singly lL