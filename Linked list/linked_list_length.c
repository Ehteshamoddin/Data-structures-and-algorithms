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

//Iterative
void countNodes(struct Node *p){
    int count=0;
    while (p != NULL)
    {
        printf("%d->", p->data);
        p = p->next;
        count++;
    }
    printf("NULL");
    printf("\n%d ",count);
}

int count(struct Node *p){
    int c=0;
    while (p!=NULL)
    {
        c++;
        p=p->next;
    }
    return c;
}

//Recursive
int Rcount(struct Node *p){
    if (p==0)
    {
        return 0;
    }
    else{
        return count(p->next)+1;
    }
}
int Rcount2(struct Node *p){
    int x=0;
    if (p)
    {
        /* x=Rcount2(p->next);
        return x+1; */
        return Rcount2(p->next)+1;
    }
    else{
        return x;
    }
}

int main()
{
    int a[] = {3, 5, 7, 10, 1};
    create(a, 5);
    /* countNodes(first);
    printf("%d",count(first));
    printf("%d",Rcount(first)); */
    printf("%d",Rcount2(first));
    
    return 0;
}