#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct Smatrix
{
    int *A;
    int n;
};
void Set(struct Smatrix *m, int i, int j, int x)
{
    if (i >= j)
        m->A[i * (i - 1) / 2 + j - 1] = x;
    else
        m->A[j * (j - 1) / 2 + i - 1] = x;
}
int Get(struct Smatrix *m, int i, int j)
{
    if (i >= j)
        return m->A[i * (i - 1) / 2 + j - 1];
    else
        return m->A[j * (j - 1) / 2 + i - 1];
}
void Display(struct Smatrix *m)
{
    for (int i = 1; i <= m->n; i++)
    {
        for (int j = 1; j <= m->n; j++)
        {
            if (i >= j)
                printf("%d ", m->A[i * (i - 1) / 2 + j - 1]);
            else
            {
                printf("%d ", m->A[j * (j - 1) / 2 + i - 1]);
            }
        }
        printf("\n");
    }
}
int main()
{
    struct Smatrix m;
    int d;
    printf("Enter dimension :- ");
    scanf("%d", &d);

    int i, j, x;

    m.A = (int *)malloc(m.n * (m.n + 1) / 2 * sizeof(int));
    printf("Enter all the elements :- ");

    for (int i = 1; i <= d; i++)
    {
        for (int j = 1; j <= d; j++)
        {
            scanf("%d", &x);
            Set(&m, i, j, x);
        }
    }
    Display(&m);
    return 0;
}