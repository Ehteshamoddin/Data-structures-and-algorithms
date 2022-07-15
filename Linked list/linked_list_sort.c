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

int isSorted(struct Node *p)
{
    int x = INT_MIN;
    p = first;
    while (p != NULL)
    {
        if (p->data < x)
        {
            return 0;
            break;
        }
        x = p->data;
        p = p->next;
    }
    return 1;
}

int main()
{
    int a[] = {1, 3, 5, 7, 10};
    create(a, 5);
    display(first);
    printf("\n%d", isSorted(first));

    return 0;
}