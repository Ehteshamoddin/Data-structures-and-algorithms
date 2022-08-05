#include <iostream>
using namespace std;

class Node
{
public:
    Node *lchild;
    int data;
    Node *rchild;
};

class queue
{
private:
    int size;
    int front;
    int rear;
    Node **Q;

public:
    queue()
    {
        front = rear = -1;
        size = 10;
        Q = new Node *[size];
    };
    queue(int size)
    {
        front = rear = -1;
        this->size = size;
        Q = new Node *[this->size];
    };
    void enqueue(Node *x);
    Node *dequeue();
    int isEmpty() { return front == rear; }
    void display();
};

void queue::enqueue(Node *x)
{
    if (rear == size - 1)
    {
        printf("Queue full\n");
    }
    else
    {
        rear++;
        Q[rear] = x;
    }
}

Node *queue::dequeue()
{
    Node *x = nullptr;
    if (front == rear)
    {
        printf("Queue Empty\n");
    }
    else
    {
        x = Q[front + 1];
        front++;
    }
    return x;
}

void queue::display()
{
    for (int i = front + 1; i <= rear; i++)
    {
        cout << Q[i] << " ";
    }
}

/*int main()
{
    queue q1;
    q1.enqueue(2);
    q1.enqueue(4);
    q1.enqueue(6);
    q1.enqueue(8);

    q1.display();
    cout << "\nElement removed:" << q1.dequeue() << endl;

    return 0;
}*/

/*#include <iostream>

using namespace std;

class Node
{
public:
    Node *lchild;
    int data;
    Node *rchild;
};

class Queue
{
private:
    int size;
    int front;
    int rear;
    Node **Q; // [Node*]*: Pointer to [Pointer to Node]
public:
    Queue(int size);
    ~Queue();
    bool isFull();
    bool isEmpty();
    void enqueue(Node *x);
    Node *dequeue();
};

Queue::Queue(int size)
{
    this->size = size;
    front = -1;
    rear = -1;
    Q = new Node *[size];
}

Queue::~Queue()
{
    delete[] Q;
}

bool Queue::isEmpty()
{
    if (front == rear)
    {
        return true;
    }
    return false;
}

bool Queue::isFull()
{
    if (rear == size - 1)
    {
        return true;
    }
    return false;
}

void Queue::enqueue(Node *x)
{
    if (isFull())
    {
        cout << "Queue Overflow" << endl;
    }
    else
    {
        rear++;
        Q[rear] = x;
    }
}

Node *Queue::dequeue()
{
    Node *x = nullptr;
    if (isEmpty())
    {
        cout << "Queue Underflow" << endl;
    }
    else
    {
        front++;
        x = Q[front];
    }
    return x;
}*/