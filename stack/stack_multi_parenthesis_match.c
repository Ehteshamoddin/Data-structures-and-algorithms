#include <stdio.h>
#include <stdlib.h>

struct Node
{
    char data;
    struct Node *next;
} *top = NULL;

void push(char x)
{
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    if (t == NULL)
    {
        printf("stack is full\n");
    }
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}

char pop()
{
    char x = -1;
    struct Node *t;
    if (top == NULL)
    {
        printf("stack is Empty\n");
    }
    else
    {
        t = top;
        top = top->next;
        x = t->data;
        free(t);
    }
    return x;
}

void display()
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

int match(char a, char b)
{
    if (a == '(' && b == ')')
    {
        return 1;
    }
    if (a == '[' && b == ']')
    {
        return 1;
    }
    if (a == '{' && b == '}')
    {
        return 1;
    }
    return 0;
}

int isBalanced(char *exp)
{
    int i;
    char pop_ch;
    for (i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '{' || exp[i] == '(' || exp[i] == '[')
        {
            push(exp[i]);
        }
        else if (exp[i] == '}' || exp[i] == ')' || exp[i] == ']')
        {
            if (top == NULL)
            {
                return 0;
            }
            pop_ch = pop(exp[i]);
            if (!match(pop_ch, exp[i]))
            {
                return 0;
            }
        }
    }
    if (top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    char *exp = "{(a+b)*(c-d])}";
    printf("%d", isBalanced(exp));

    return 0;
}