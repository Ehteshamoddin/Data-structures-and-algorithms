#include <stdio.h>
#include <stdlib.h>

struct stack_array
{
    int size, top;
    int *s;
};

void create(struct stack_array *st)
{
    printf("Enter the size of stack:");
    scanf("%d", &st->size);
    st->top = -1;
    st->s = (int *)malloc(st->size * sizeof(int));
}

void display(struct stack_array st)
{
    for (int i = st.top; i >= 0; i--)
    {
        printf("%d ", st.s[i]);
    }
    printf("\n");
}

int isEmpty(struct stack_array *st)
{
    if (st->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isFull(struct stack_array *st)
{
    if (st->top == st->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int stackTop(struct stack_array st)
{
    if (st.top == -1)
    {
        return -1;
    }
    else
    {
        return st.s[st.top];
    }
}

void push(struct stack_array *st, int x)
{
    if (!isFull(st))
    {
        st->top++;
        st->s[st->top] = x;
    }
    else
    {
        printf("stack overflow\n");
    }
}
int pop(struct stack_array *st)
{
    int x = -1;
    if (!isEmpty(st))
    {
        x = st->s[st->top--];
    }
    else
    {
        printf("stack underflow:");
    }
    return x;
}

int peek(struct stack_array st, int index)
{
    int x = -1;
    if (st.top - index + 1 < 0)
    {
        printf("Invalid Index");
    }
    else
    {
        x = st.s[st.top - index + 1];
    }
    return x;
}

int main()
{

    struct stack_array st;
    create(&st);
    push(&st, 10);
    push(&st, 20);
    push(&st, 30);
    push(&st, 40);
    push(&st, 50);

    display(st);

    /* printf("%d\n", pop(&st));
    printf("%d\n", pop(&st));
    printf("%d\n", pop(&st));
    printf("%d\n", pop(&st));
    printf("%d\n", pop(&st));
    printf("%d\n", pop(&st)); */

    printf("%d ", peek(st, 1));

    return 0;
}