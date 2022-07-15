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

int linear_search(struct Array *arr, int key)
{
    for (int i = 0; i < arr->length; i++)
    {
        if (arr->a[i] == key)
        {
            return i;
        }
    }
    return -1;
}

int modify_linear_search_transpose(struct Array *arr, int key)
{
    for (int i = 0; i < arr->length; i++)
    {
        if (arr->a[i] == key)
        {
            swap(&arr->a[i], &arr->a[i - 1]);
            return i;
        }
    }
    return -1;
}

int modify_linear_search_front(struct Array *arr, int key)
{
    for (int i = 0; i < arr->length; i++)
    {
        if (arr->a[i] == key)
        {
            swap(&arr->a[i], &arr->a[0]);
            return i;
        }
    }
    return -1;
}

int main()
{

    struct Array arr = {{2, 3, 4, 5, 6}, 20, 5};
    display(arr);
    printf("\n");
    printf("Found at Index number :%d", linear_search(&arr, 5));
    printf("\n");
    printf("Modified search transpose,Index number :%d", modify_linear_search_transpose(&arr, 5));
    display(arr);
    printf("\n");
    printf("Modified search front,Index number :%d", modify_linear_search_front(&arr, 5));
    display(arr);

    return 0;
}