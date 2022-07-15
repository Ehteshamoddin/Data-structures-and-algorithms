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

int binary(struct Array arr, int key)
{
    int l, mid, h;
    l = 0;
    h = arr.length - 1;
    while (l <= h)
    {
        mid = (l + h) / 2;
        if (key == arr.a[mid])
        {
            return mid;
        }
        else if (key < arr.a[mid])
        {
            h = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return -1;
}
int Rbinary(int a[], int l, int h, int key)
{
    int mid;

    if (l <= h)
    {
        mid = (l + h) / 2;
        if (key == a[mid])
        {
            return mid;
        }
        else if (key < a[mid])
        {
            return Rbinary(a, l, mid - 1, key);
        }
        else
        {
            return Rbinary(a, mid + 1, h, key);
        }
    }
    return -1;
}

int main()
{

    struct Array arr = {{2, 3, 4, 5, 6}, 20, 5};
    printf("binary %d", binary(arr, 6));
    printf("\n");
    printf("Rbinary %d", Rbinary(arr.a, 0, arr.length, 5));
    printf("\n");
    display(arr);

    return 0;
}