#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    char a[] = "finding";
    long int h = 0;
    int x = 0;

    for (i = 0; a[i] != '\0'; i++)
    {
        x = 1;
        x = x << (a[i] - 97);
        if ((x & h) > 0)
        {
            printf("\n%c is duplicate", a[i]);
        }
        else
        {
            h = (x | h);
        }
    }

    return 0;
}