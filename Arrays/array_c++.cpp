#include <iostream>
using namespace std;

template <class T>

class Array
{
private:
    T *a;
    int size;
    int length;

public:
    Array()
    {
        size = 10;
        length = 0;
        a = new T[10];
    }
    Array(int sz)
    {
        size = sz;
        length = 0;
        a = new T[10];
    }
    ~Array()
    {
        delete[] a;
    }
    void display();
    void insert(int index, T x);
    T Delete(int index);
};

template <class T>
void Array<T>::display()
{
    for (int i = 0; i < length; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

template <class T>
void Array<T>::insert(int index, T x)
{
    if (index >= 0 && index <= length)
    {
        for (int i = length - 1; i >= index; i--)
        {
            a[i + 1] = a[i];
        }
        a[index] = x;
        length++;
    }
}

template <class T>
T Array<T>::Delete(int index)
{
    T x = 0;
    if (index >= 0 && index < length)
    {
        x = a[index];
        for (int i = index; i < length - 1; i++)
        {
            a[i] = a[i + 1];
        }
        length--;
    }
    return x;
}

int main()
{
    Array<int> arr(10);
    arr.insert(0, 2);
    arr.insert(1, 4);
    arr.insert(2, 5);
    arr.insert(3, 6);
    arr.insert(4, 12);
    arr.display();
    cout << arr.Delete(4) << endl;
    arr.display();

    return 0;
}