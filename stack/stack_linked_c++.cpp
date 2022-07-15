#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class stack
{
private:
    Node *top;

public:
    stack() { top = NULL; }
    void push(int x);
    int pop();
    void display();
    /* ~stack(); */
};

void stack::push(int x)
{
    Node *t = new Node;
    if (t == NULL)
    {
        cout << "stack is full";
    }
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}

int stack::pop()
{
    int x = -1;
    if (top == NULL)
    {
        cout << "stack is empty";
    }
    else
    {
        x = top->data;
        Node *t = top;
        top = top->next;
        delete t;
    }
    return x;
}

void stack::display()
{
    struct Node *p;
    p = top;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    stack stk;
    stk.push(2);
    stk.push(4);
    stk.push(6);
    stk.push(8);

    stk.display();
    cout << stk.pop();
    return 0;
}