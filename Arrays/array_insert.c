#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int a[10];
    int size;
    int length;
};

void display(struct Array arr)
{
    printf("Elements are :\n");
    for (int i = 0; i < arr.length; i++)
        printf("%d ", arr.a[i]);
}

void append(struct Array *arr, int x)
{
    if (arr->length < arr->size)
    {
        arr->a[arr->length++] = x;
    }
}

void insert(struct Array *arr, int index, int x)
{
    int i;
    if (index >= 0 && index <= arr->length)
    {
        for (i = arr->length; i > index; i--)
        {
            arr->a[i] = arr->a[i - 1];
        }
        arr->a[index] = x;
        arr->length++;
    }
}

int main()
{

    struct Array arr = {{2, 3, 4, 5, 6}, 20, 5};
    append(&arr, 12);
    insert(&arr, 5, 10);
    display(arr);

    return 0;
}