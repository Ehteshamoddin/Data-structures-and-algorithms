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

//Iterative
int add(struct Node *p)
{
    int sum = 0;
    while (p != NULL)
    {
        sum = sum + (p->data);
        p=p->next;
    }
    return sum;
}
//Recursive
int Radd(struct Node *p)
{
    if (p==0)
    {
        return 0;
    }
    else{
        return add(p->next) + p->data;
    }
    
}

int main()
{
    int a[] = {3, 5, 7, 10, 1};
    create(a, 5);
    printf("%d", Radd(first));
    return 0;
}