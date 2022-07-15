#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class linked_list
{
private:
    Node *first;

public:
    linked_list() { first = NULL; };
    linked_list(int a[], int n);
    ~linked_list();

    void display();
    void insert(int index, int x);
    int Delete(int index);
    int length();
};

linked_list::linked_list(int a[], int n)
{
    Node *last, *t;
    int i = 0;

    first = new Node;
    first->data = a[0];
    first->next = NULL;
    last = first;

    for (int i = 1; i < n; i++)
    {
        t = new Node;
        t->data = a[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

linked_list::~linked_list()
{
    Node *p = first;
    while (first)
    {
        first = first->next;
        delete p;
        p = first;
    }
}

void linked_list::display()
{
    Node *p = first;
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
}

int linked_list::length()
{
    Node *p = first;
    int count = 0;
    while (p)
    {
        count++;
        p = p->next;
    }
    return count;
}

void linked_list::insert(int index, int x)
{
    Node *p, *q;
    p = first;
    if (index < 0 || index > length())
    {
        return;
    }
    q = new Node;
    q->data = x;
    q->next = NULL;
    if (index == 0)
    {
        q->next = first;
        first = q;
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
        {
            p = p->next;
        }
        q->next = p->next;
        p->next = q;
    }
}

int linked_list::Delete(int index)
{
    Node *p, *q = NULL;
    int x = -1;
    if (index < 1 || index > length())
    {
        return -1;
    }
    if (index == 1)
    {
        p = first;
        first = first->next;
        x = p->data;
        delete p;
    }
    else
    {
        p = first;
        for (int i = 0; i < index - 1; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        delete p;
    }
    return x;
}

int main()
{
    int a[] = {2, 4, 5, 6, 8};
    linked_list l(a, 5);
    l.display();
    cout << endl;
    cout << "Length of linked list is:" << l.length();
    cout << endl;
    l.insert(5, 10);
    l.display();
    cout << endl;
    cout << "Deleted element:" << l.Delete(5) << endl;
    l.display();
}