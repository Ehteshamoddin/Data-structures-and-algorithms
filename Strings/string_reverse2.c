#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j;
    char t;
    char a[] = "Python";

    for (i = 0; a[i] != '\0'; i++)
    {
    }
    i = i - 1;
    for (j = 0; i > j; i--, j++)
    {
        char temp = a[j];
        a[j] = a[i];
        a[i] = temp;
    }
    printf("%s", a);

    return 0;
}