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

void missing_multiple(struct Array *arr, int l, int n)
{
    int d = l;
    int sum = (n * (n + 1)) / 2;
    for (int i = 0; i < n; i++)
    {
        if (arr->a[i] - i != d)
        {
            while (d < arr->a[i] - i)
            {
                printf("\nMissing element is: %d", i + d);
                d++;
            }
        }
    }
}

int main()
{

    struct Array arr = {{6, 7, 9, 10, 12}, 20, 6};
    display(arr);
    missing_multiple(&arr, 6, 6);

    return 0;
}