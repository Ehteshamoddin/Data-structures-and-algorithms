#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int main()
{
    string s = "312";
    sort(s.begin(), s.end());
    do
    {
        cout << s << endl;
    } while (next_permutation(s.begin(), s.end()));

    return 0;
}