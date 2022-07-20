#include <iostream>
using namespace std;

class queue
{
private:
    int size;
    int front;
    int rear;
    int *Q;

public:
    queue()
    {
        front = rear = -1;
        size = 10;
        Q = new int[size];
    };
    queue(int size)
    {
        front = rear = -1;
        this->size = size;
        Q = new int[this->size];
    };
    void enqueue(int x);
    int dequeue();
    void display();
};

void queue::enqueue(int x)
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

int queue::dequeue()
{
    int x = -1;
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

int main()
{
    queue q1;
    q1.enqueue(2);
    q1.enqueue(4);
    q1.enqueue(6);
    q1.enqueue(8);
    
    q1.display();
    cout << "\nElement removed:" << q1.dequeue() << endl;

    return 0;
}