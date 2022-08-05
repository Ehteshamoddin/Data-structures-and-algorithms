#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
};

struct queue
{
    int size;
    int rear;
    int front;
    Node **Q;
};

void create(struct queue *q, int size)
{
    q->size = size;
    q->front = q->rear = 0;
    q->Q = (Node **)malloc(q->size * sizeof(Node *));
}

void enqueue(struct queue *q, Node *x)
{
    if ((q->rear + 1) % q->size == q->front)
    {
        printf("Queue full");
    }
    else
    {
        q->rear = (q->rear + 1) % q->size;
        q->Q[q->rear] = x;
    }
}
Node dequeue(struct queue *q)
{
    Node *x = NULL;
    if (q->front == q->rear)
    {
        printf("Queue Empty");
    }
    else
    {
        q->front = (q->front + 1) % q->size;
        x = q->Q[q->front];
    }
    return x;
}

int isEmpty(struct queue q)
{
    return q.front == q.rear;
}