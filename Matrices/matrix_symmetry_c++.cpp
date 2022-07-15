#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
class Smatrix
{
private:
    int n;
    int *A;

public:
    Smatrix()
    {
        n = 2;
        A = new int[2 * 2];
    }
    Smatrix(int n)
    {
        this->n = n;
        A = new int[n * n]; // mistake here
    }
    ~Smatrix()
    {
        delete[] A;
    }
    void Set(int i, int j, int x);
    int Get(int i, int j);
    void Display();
};
void Smatrix::Set(int i, int j, int x)
{
    if (i >= j)
        A[i * (i - 1) / 2 + j - 1] = x;
    else
        A[j * (j - 1) / 2 + i - 1] = x;
}
int Smatrix::Get(int i, int j)
{
    if (i >= j)
        return A[i * (i - 1) / 2 + j - 1];
    else
        return A[j * (j - 1) / 2 + i - 1];
}
void Smatrix::Display()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i >= j)
                cout << A[i * (i - 1) / 2 + j - 1] << " ";
            else
            {
                /*int k;
                i=j;
                j=i;
                k=j;*/
                cout << A[j * (j - 1) / 2 + i - 1] << " ";
            }
        }
        cout << endl;
    }
}
int main()
{
    int d;
    cout << "Enter dimension :- ";
    cin >> d;
    Smatrix s(d); // dimensions must be given for matrix
    int x;
    cout << "Enter all the elements :- " << endl;
    for (int i = 1; i <= d; i++)
    {
        for (int j = 1; j <= d; j++)
        {
            cin >> x;
            s.Set(i, j, x);
        }
    }
    s.Display();
    return 0;
}