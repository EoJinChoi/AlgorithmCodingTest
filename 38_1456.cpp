// 2024.03.08

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    long Min, Max;
    cin >> Min >> Max;

    vector<long> v(10000001);
    for (int i = 2; i < 10000001; i++)
        v[i] = i;

    for (int i = 2; i <= sqrt(10000001); i++)
    {
        if (v[i] == 0)
            continue;

        for (int j = i + i; j < 10000001; j += i)
            v[j] = 0;
    }

    int cnt = 0;
    for (int i = 2; i < 10000001; i++)
    {
        if (v[i] != 0)
        {
            long temp = v[i];

            while ((double)v[i] <= (double)Max / (double)temp)
            {
                if ((double)v[i] >= (double)Min / (double)temp)
                    cnt++;

                temp *= v[i];
            }
        }
    }

    cout << cnt << "\n";

    return 0;
}