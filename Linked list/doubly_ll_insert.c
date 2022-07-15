#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
} *first = NULL;

void create(int a[], int n)
{
    struct Node *t, *last;
    first = (struct Node *)malloc((sizeof(struct Node)));
    first->data = a[0];
    first->prev = first->next = NULL;
    last = first;

    for (int i = 1; i < n; i++)
    {
        t = (struct Node *)malloc((sizeof(struct Node)));
        t->data = a[i];
        t->next = last->next;
        t->prev = last;
        last->next = t;
        last = t;
    }
}

void display(struct Node *p)
{
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

int length(struct Node *p)
{
    int len = 0;
    while (p)
    {
        p = p->next;
        len++;
    }
    return len;
}

void insert(struct Node *p, int index, int x)
{
    struct Node *t;
    int i;
    if (index < 0 || index > length(p))
    {
        return;
    }
    if (index == 0)
    {
        t = (struct Node *)malloc((sizeof(struct Node)));
        t->data = x;
        t->prev = NULL;
        t->next = first;
        first->prev = t;
        first = t;
    }
    else
    {
        for (i = 0; i < index-1; i++)
        {
            p = p->next;
        }
        t = (struct Node *)malloc((sizeof(struct Node)));
        t->data = x;
        t->prev = p;
        t->next = p->next;
        if (p->next)
        {
            p->next->prev = t;
        }
        p->next = t;
    }
}

int main()
{
    int a[] = {10, 20, 30, 40, 50};
    create(a, 5);
    display(first);
    insert(first, 4, 45);
    printf("\n");
    display(first);

    return 0;
}