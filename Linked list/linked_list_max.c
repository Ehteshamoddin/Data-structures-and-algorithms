#include <stdio.h>
#include <stdlib.h>
// smallest in 2 bytes(16 bit integer) consider -32768 or INT_MIN

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

// Iterative
int max(struct Node *p)
{
    int m = -32768; // Minimum integer
    while (p)
    {
        if (p->data > m)
        {
            m = p->data;
        }
        p = p->next;
    }
    return m;
}

// Recursive
int Rmax(struct Node *p)
{
    int x = 0;
    if (p == 0)
    {
        return INT_MIN;
    }
    x = Rmax(p->next);
    if (x > p->data)
    {
        return x;
    }
    else
    {
        return p->data;
    }
}

int max2(struct Node *p){
    int x=0;
    if (p==0)
    {
        return INT_MIN;
    }
    x=max2(p->next);
    return x>p->data?x:p->data;
    
}
int main()
{
    int a[] = {3, 5, 7, 10, 1};
    create(a, 5);
    printf("%d ", Rmax(first));
    return 0;
}