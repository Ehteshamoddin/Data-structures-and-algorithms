#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int a[100];
    int size;
    int length;
};

void display(struct Array arr)
{
    printf("Elements are :\n");
    for (int i = 0; i < arr.length; i++)
        printf("%d ", arr.a[i]);
}

void duplicate(struct Array *arr)
{
    int count = 0;

    for (int i = 0; i < arr->length; i++)
    {
        count = 1;
        if (arr->a[i] != -1)
        {
            for (int j = i + 1; j < arr->length; j++)
            {
                if (arr->a[i] == arr->a[j])
                {
                    count++;
                    arr->a[j] = -1;
                }
            }
            if (count > 1)
            {
                printf("\n%d is repeated %d times ", arr->a[i], count);
            }
        }
    }
}

int main()
{

    struct Array arr = {{6, 3, 8, 8, 10, 16, 15, 15, 15, 1}, 20, 10};
    display(arr);
    duplicate(&arr);

    return 0;
}