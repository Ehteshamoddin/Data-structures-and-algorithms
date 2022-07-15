#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *first = NULL;

void create(int a[], int n)
{
    int i;
    struct Node *t, *last;
    // Creation of first Node
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = a[0];
    first->next = NULL;
    last = first;

    // Creation of Rest Nodes
    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = a[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

int countSize(struct Node *p)
{
    int count = 0;
    while (p != NULL)
    {
        p = p->next;
        count++;
    }
    return count;
}

void display(struct Node *p)
{
    while (p != NULL)
    {
        printf("%d->", p->data);
        p = p->next;
    }
    printf("NULL");
}

void reverse1(struct Node *p)
{
    struct Node *q = p;
    int i = 0;
    int *A;
    A = (int *)malloc(sizeof(int) * countSize(p));
    while (q != NULL)
    {
        A[i] = q->data;
        q = q->next;
        i++;
    }
    q = p;
    i--;
    while (q != NULL)
    {
        q->data = A[i];
        q = q->next;
        i--;
    }
}

void reverse2(struct Node *p)
{
    struct Node *q = NULL, *r = NULL;
    while (p != NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}

void reverse_recursive(struct Node *q, struct Node *p)
{
    if (p)
    {
        reverse_recursive(p, p->next);
        p->next = q;
    }
    else
    {
        first = q;
    }
}
int main()
{
    int a[] = {1, 3, 5, 7, 10};
    create(a, 5);
    display(first);
    /* reverse1(first);
    reverse2(first); */
    reverse_recursive(NULL, first);
    printf("\n");
    display(first);
    return 0;
}