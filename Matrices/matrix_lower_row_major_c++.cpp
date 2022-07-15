#include <iostream>
using namespace std;

class lower_triangular
{
private:
    int *a;
    int n;

public:
    lower_triangular()
    {
        n = 2;
        a = new int[2 * (2 + 1) / 2];
    }
    lower_triangular(int n)
    {
        this->n = n;
        a = new int[n * (n + 1) / 2];
    }
    ~lower_triangular()
    {
        delete[] a;
    }
    void set(int i, int j, int x);
    int get(int i, int j);
    void display();
    int getDim(){ return n;}
};

void lower_triangular::set(int i, int j, int x)
{
    if (i >= j)
        a[i * (i - 1) / 2 + j - 1] = x;
}

int lower_triangular::get(int i, int j)
{
    if (i >= j)
    {
        return a[i * (i - 1) / 2 + j - 1];
    }
    else
    {
        return 0;
    }
}

void lower_triangular::display()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i >= j)
                cout << a[i * (i - 1) / 2 + j - 1] << " ";
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

    lower_triangular dm(d);

    int x;
    cout << "Enter All Elements:";
    for (int i = 1; i <= d; i++)
    {
        for (int j = 1; j <= d; j++)
        {
            if (i >= j)
                cin >> x;
            dm.set(i, j, x);
        }
    }
    dm.display();
    cout << dm.getDim();

    return 0;
}