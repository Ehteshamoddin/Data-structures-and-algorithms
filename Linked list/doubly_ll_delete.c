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

int delete (struct Node *p, int index)
{
    int i;
    int x = -1;
    if (index < 1 || index > length(p))
    {
        return x;
    }
    if (index == 1)
    {
        first = first->next;
        if (first)
        {
            first->prev = NULL;
        }
        x = p->data;
        free(p);
    }
    else
    {
        for (i = 0; i < index - 1; i++)
        {
            p = p->next;
        }
        p->prev->next = p->next;
        if (p->next)
        {
            p->next->prev = p->prev;
        }
        x = p->data;
        free(p);
    }
    return x;
}

int main()
{
    int a[] = {10, 20, 30, 40, 50};
    create(a, 5);
    display(first);
    printf("\n%d", delete (first, 5));
    printf("\n");
    display(first);

    return 0;
}