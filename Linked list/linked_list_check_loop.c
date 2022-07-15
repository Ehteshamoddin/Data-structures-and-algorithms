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

int isLoop(struct Node *f)
{
    struct Node *p, *q;
    p = q = f;
    do
    {
        p = p->next;
        q = q->next;
        q = q ? q->next : q;
    } while (p && q != q);
    if (p == q)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    struct Node *t1, *t2;
    int a[] = {10, 20, 30, 40, 50};

    create(a, 5);
    /* t1 = first->next->next;
    t2 = first->next->next->next->next;
    t2->next = t1; */

    printf("%d ", isLoop(first));

    return 0;
}