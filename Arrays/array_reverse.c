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

/*Method 1*/
void reverse(struct Array *arr)
{
    int *b;
    int i, j;
    b = (int *)malloc(arr->length * sizeof(int *));
    for (int i = arr->length - 1, j = 0; i >= 0; i--, j++)
    {
        b[j] = arr->a[i];
    }
    for (int i = 0; i < arr->length; i++)
    {
        arr->a[i] = b[i];
    }
}

/*Method 2*/

void reverse2(struct Array *arr)
{
    int i, j;
    for (i = 0, j = arr->length - 1; i < j; i++, j--)
    {
        swap(&arr->a[i], &arr->a[j]);
    }
}

int main()
{

    struct Array arr = {{2, 3, 4, 5, 6}, 20, 5};
    display(arr);
    reverse2(&arr);
    display(arr);

    return 0;
}