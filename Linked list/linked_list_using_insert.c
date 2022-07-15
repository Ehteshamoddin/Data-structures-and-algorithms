#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *first = NULL;

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
    struct Node *t;
    if (index < 0 || index > count(p))
    {
        return;
    }
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = key;
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

void insertlast(struct Node *p, int key)
{
    struct Node *t, *last;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = key;
    t->next = NULL;
    if (first == NULL)
    {
        first = last = t;
    }
    else
    {
        last->next = t;
        last = t;
    }
}

int main()
{
    insertlast(first, 12);
    insertlast(first, 14);
    insertlast(first, 1);
    insertlast(first, 2);
    display(first);

    return 0;
}