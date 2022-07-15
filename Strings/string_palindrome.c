#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j;
    char a[] = "liril";
    char b[10];

    for (i = 0; a[i] != '\0'; i++)
    {
    }
    i = i - 1;
    for (j = 0; i >= 0; j++, i--)
    {
        b[j] = a[i];
    }
    b[j]='\0';

    for (i = 0, j = 0; a[i] != '\0' && b[j] != '\0'; i++, j++)
    {
        if (a[i] != b[j])
        {
            break;
        }
    }
    if (a[i] == b[j])
    {
        printf("Palindrome");
    }
    else
    {
        printf("Not Palindrome");
    }

    return 0;
}