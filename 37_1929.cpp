// 2025.03.08

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    int start, end;
    cin >> start >> end;

    vector<int> v(end + 1);
    for (int i = 2; i <= end; i++)
        v[i] = i;

    for (int i = 2; i <= sqrt(end); i++)
    {
        if (v[i] == 0)
            continue;

        for (int j = i + i; j <= end; j += i)
            v[j] = 0;
    }

    for (int i = start; i <= end; i++)
    {
        if (v[i] != 0)
            cout << v[i] << "\n";
    }

    return 0;
}