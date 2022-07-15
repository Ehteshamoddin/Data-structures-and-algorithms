#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} * head;

void create(int a[], int n)
{
    int i;
    struct Node *t, *last;
    head = (struct Node *)malloc((sizeof(struct Node)));
    head->data = a[0];
    head->next = head;
    last = head;

    for (int i = 1; i < n; i++)
    {
        t = (struct Node *)malloc((sizeof(struct Node)));
        t->data = a[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}

void display(struct Node *p)
{
    do
    {
        printf("%d ", p->data);
        p = p->next;
    } while (p != head);
}

void Rdisplay(struct Node *p){
    static int flag=0;
    if (p!=head || flag==0)
    {
        flag=1;
        printf("%d ",p->data);
        Rdisplay(p->next);
    }
    flag=0;
}

int main()
{
    int a[] = {10, 20, 30, 40, 50};
    create(a, 5);
    Rdisplay(head);

    return 0;
}