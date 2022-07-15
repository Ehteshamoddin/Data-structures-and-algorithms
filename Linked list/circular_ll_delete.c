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

int counting(struct Node *p)
{
    int count = 0;
    do
    {
        p = p->next;
        count++;
    } while (p != head);
    return count;
}

int delete (struct Node *p, int index)
{
    struct Node *q;
    int i;
    int x = 0;
    if (index < 0 || index > counting(head))
    {
        return -1;
    }
    if (index == 1)
    {
        while (p->next != head)
        {
            p = p->next;
        }
        if (head == p)
        {
            free(p);
            head = NULL;
        }
        else
        {
            p->next = head->next;
            free(head);
            head = p->next;
        }
    }
    else
    {
        for (i = 0; i < index - 2; i++)
        {
            p = p->next;
        }
        q = p->next;
        p->next = q->next;
        x = q->data;
        free(q);
    }
    return x;
}

int main()
{
    int a[] = {10, 20, 30, 40, 50};
    create(a, 5);
    display(head);
    printf("\nDeleted Element:%d", delete (head, 2));
    printf("\n");
    display(head);

    return 0;
}