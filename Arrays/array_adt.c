#include <stdio.h>
#include <stdlib.h>

/*Note : when you use call by address in "*" in function then only use "->" operator
,else use ".",call by address is used to change the actual array */

struct Array
{
    int *a;
    int size;
    int length;
};

void display(struct Array arr)
{
    printf("Elements are :\n");
    for (int i = 0; i < arr.length; i++)
        printf("%d ", arr.a[i]);
}

int main()
{

    struct Array arr;
    int n;
    printf("Enter size of Array:");
    scanf("%d", &arr.size);
    arr.a = (int *)malloc(arr.size * sizeof(int));
    arr.length = 0;
    printf("Enter number of numbers:");
    scanf("%d", &n);
    printf("Enter all the elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d ", &arr.a[i]);

    arr.length = n;
    display(arr);

    return 0;
}