#include <stdio.h>
#include <stdlib.h>

int main()
{
    char i;
    char a[] = "Python";
    char b[7];

    for (i = 0; a[i] != '\0'; i++)
    {
    }
    i = i - 1;
    int j;
    for (j = 0; i >= 0; i--, j++)
    {
        b[j] = a[i];
    }
    b[j] = '\0';
    printf("%s",b);

    return 0;
}