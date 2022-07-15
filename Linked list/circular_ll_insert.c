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

void insert(struct Node *p, int index, int x)
{
    struct Node *t;
    if (index < 0 || index > counting(head))
    {
        return;
    }

    if (index == 0)
    {
        t = (struct Node *)malloc((sizeof(struct Node)));
        t->data = x;
        if (head == NULL)
        {
            head = t;
            head->next = head;
        }
        else
        {
            while (p->next != head)
            {
                p = p->next;
            }
            p->next = t;
            t->next = head;
            head = t;
        }
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
        {
            p = p->next;
        }
        t = (struct Node *)malloc((sizeof(struct Node)));
        t->data = x;
        t->next = p->next;
        p->next = t;
    }
}

int main()
{
    int a[] = {10, 20, 30, 40, 50};
    create(a, 5);
    display(head);
    insert(head, 0, 5);
    printf("\n");
    display(head);

    return 0;
}