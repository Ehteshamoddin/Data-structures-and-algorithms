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
    printf("\nElements are :\n");
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

/* void delete (struct Array *arr, int index)
{
    int x;
    x = arr->a[index];
    if (index >=0 && index <= arr->length)
    {
        for (int i = index; i < arr->length - 1; i++)
        {
            arr->a[i] = arr->a[i + 1];
        }
        arr->length--;
    }
} */

int delete (struct Array *arr, int index)
{
    int x;
    x = arr->a[index];
    if (index >= 0 && index <= arr->length)
    {
        for (int i = index; i < arr->length - 1; i++)
        {
            arr->a[i] = arr->a[i + 1];
        }
        arr->length--;
    }
    return x;
}

int main()
{

    struct Array arr = {{2, 3, 4, 5, 6}, 20, 5};
    printf("Deleted element: %d", delete (&arr, 3));
    display(arr);

    return 0;
}