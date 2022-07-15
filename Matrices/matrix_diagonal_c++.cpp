#include <iostream>
using namespace std;

class diagonal
{
private:
    int n;
    int *a;

public:
    diagonal()
    {
        n = 2;
        a = new int[n];
    }
    diagonal(int n)
    {
        this->n = n;
        a = new int[n];
    }
    ~diagonal()
    {
        delete[] a;
    }
    void set(int i, int j, int x);
    int get(int i, int j);
    void display();
};

void diagonal::set(int i, int j, int x)
{
    if (i == j)
        a[i - 1] = x;
}

int diagonal::get(int i, int j)
{
    if (i == j)
    {
        return a[i - 1];
    }
    else
    {
        return 0;
    }
}

void diagonal::display()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                cout << a[i - 1] << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }
}

int main()
{

    int d;
    cout << "Enter Dimensions:";
    cin >> d;

    diagonal dm(d);

    int x;
    cout << "Enter All Elements:";
    for (int i = 1; i <= d; i++)
    {
        for (int j = 1; j <= d; j++)
        {
            if (i == j)
                cin >> x;
            dm.set(i, j, x);
        }
    }
    dm.display();

    return 0;
}