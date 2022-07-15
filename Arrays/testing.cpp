#include <iostream>
#define SIZE 3
using namespace std;

int main()
{
    int matrix[SIZE][SIZE];
    int ad = 0, bd = 0;
    cout << "Enter elements into the matrix \n";
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            cin >> matrix[i][j];
            if (j > i)
                ad += matrix[i][j];
            else if (i > j)
                bd += matrix[i][j];
        }
    }
    cout << "Sum of Numbers above Left Diagonal: " << ad << endl;
    return 0;
}