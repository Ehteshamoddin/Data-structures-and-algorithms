#include <stdio.h>
#include <stdlib.h>

int valid(char *s)
{
    int i;
    for (i = 0; s[i] != '\0'; i++)
    {
        if (!(s[i] >= 65 && s[i] <= 90) && !(s[i] >= 97 && s[i] <= 122) && !(s[i] >= 48 && s[i] <= 57))
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    char i;
    char *a = "Ani?321";

    if (valid(a))
    {
        printf("Valid string");
    }
    else
    {
        printf("invalid string");
    }

    return 0;
}