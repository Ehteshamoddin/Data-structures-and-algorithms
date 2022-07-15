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

// Iterative
void display(struct Node *p)
{
    while (p != NULL)
    {
        printf("%d->", p->data);
        p = p->next;
    }
    printf("NULL");
}

// Recursive
void Rdisplay(struct Node *p)
{
    if (p != NULL)
    {
        printf("%d->", p->data);
        Rdisplay(p->next);
    }
}

int main()
{
    int a[] = {3, 5, 7, 10, 1};
    create(a, 5);
    Rdisplay(first);
    return 0;
}