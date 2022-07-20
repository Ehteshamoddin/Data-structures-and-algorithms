#include <stdio.h>
#include <stdlib.h>
struct queue
{
    int size;
    int rear;
    int front;
    int *Q;
};

void create(struct queue *q, int size)
{
    q->size = size;
    q->front = q->rear = -1;
    q->Q = (int *)malloc(q->size * sizeof(int));
}

void enqueue(struct queue *q, int x)
{
    if (q->rear == q->size - 1)
    {
        printf("Queue is full, can't insert");
    }
    else
    {
        q->rear++;
        q->Q[q->rear] = x;
        //Q[q->rear] = x;
    }
}
int dequeue(struct queue *q)
{
    int x = -1;
    if (q->front == q->rear)
    {
        printf("The Queue is Empty");
    }
    else
    {
        q->front++;
        x = q->Q[q->front];
    }
    return x;
}

void display(struct queue *q)
{
    for (int i = q->front + 1; i <= q->rear; i++)
    {
        printf("%d ", q->Q[i]);
    }
}

int main()
{
    // creating pointer to array in structure
    struct queue q;
    create(&q, 5);
    // Enqueing elements in array queue
    enqueue(&q, 2);
    enqueue(&q, 4);
    enqueue(&q, 6);
    enqueue(&q, 8);
    enqueue(&q, 10);
    display(&q);
    printf("\n");
    // Dequeing elements in array queue
    printf("Element removed:%d\n", dequeue(&q));
    display(&q);

    return 0;
}