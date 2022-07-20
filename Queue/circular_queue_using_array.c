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
    q->front = q->rear = 0;
    q->Q = (int *)malloc(q->size * sizeof(int));
}

void enqueue(struct queue *q, int x)
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
int dequeue(struct queue *q)
{
    int x = -1;
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

void display(struct queue *q)
{
    int i = q->front + 1;
    do
    {
        printf("%d ", q->Q[i]);
        i = (i + 1) % q->size;
    } while (i != (q->rear + 1) % q->size);
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
    
    display(&q);
    printf("\n");
    // Dequeing elements in array queue
    printf("Element removed:%d\n", dequeue(&q));
    display(&q);

    return 0;
}