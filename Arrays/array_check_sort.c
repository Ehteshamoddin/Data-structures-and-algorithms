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

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int isSorted(struct Array arr)
{
    for (int i = 0; i < arr.length - 1; i++)
    {
        if (arr.a[i] > arr.a[i + 1])
        {
            return 0;
        }
    }
    return 1;
}

void insert_sorted(struct Array *arr, int key)
{
    int i = arr->length - 1;
    if (arr->length == arr->size)
    {
        return;
    }

    while (i >= 0 && arr->a[i] > key)
    {
        arr->a[i + 1] = arr->a[i];
        i--;
    }
    arr->a[i + 1] = key;
    arr->length++;
}

void rearrange(struct Array *arr)
{
    int i, j;
    i = 0;
    j = arr->length - 1;

    while (i < j)
    {
        /* while (arr->a[i] < 0)
        {
            i++;
        }
        while (arr->a[i] >= 0)
        {
            j--;
        }
        if (i < j)
        {
            swap(&arr->a[i], &arr->a[j]);
        } */

        while (arr->a[i] < 0)
            i++;
        while (arr->a[i] >= 0)
            j--;
        if (i < j)
            swap(&arr->a[i], &arr->a[j]);
    }
}

int main()
{

    /* struct Array arr = {{2, 3, 4, 15, 16}, 20, 5}; */
    struct Array arr = {{2, -3, 4, -15, 16}, 20, 5};
    /* insert_sorted(&arr, 5);
    printf("%d", isSorted(arr)); */
    display(arr);
    rearrange(&arr);
    display(arr);

    return 0;
}