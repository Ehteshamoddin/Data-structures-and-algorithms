#include <stdio.h>
#include <stdlib.h>

int main()
{
    char i;
    char a[] = "WELCOME";

    for (int i = 0; a[i] != '\0'; i++)
    {
        a[i] = a[i] + 32;
    }
    printf("%s", a);
    printf("\n");

    char b[] = "WeLcOmE";
    for (int i = 0; b[i] != '\0'; i++)
    {
        if (b[i] >= 65 && b[i] <= 90)
        {
            b[i] = b[i] + 32;
        }
        else if (b[i] >= 97 && b[i] <= 122)
        {
            b[i] = b[i] - 32;
        }
    }
    printf("%s", b);

    return 0;
}