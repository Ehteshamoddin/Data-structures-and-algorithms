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

void display(struct Node *p)
{
    while (p != NULL)
    {
        printf("%d->", p->data);
        p = p->next;
    }
    printf("NULL");
}

int count(struct Node *p)
{
    int counting = 0;
    while (p != NULL)
    {
        counting++;
        p = p->next;
    }
    return counting;
}

void insert(struct Node *p, int index, int key)
{
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    t->data = key;
    if (index < 0 || index > count(p))
    {
        return;
    }
    if (index == 0)
    {
        t->next = first;
        first = t;
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
        {
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
    }
}

int main()
{
    int a[] = {3, 5, 7, 10, 1};
    create(a, 5);
    insert(first, 0, 12);
    display(first);

    return 0;
}