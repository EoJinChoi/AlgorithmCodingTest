// 2025.3.11

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    long Min, Max;
    cin >> Min >> Max;

    vector<bool> check(Max - Min + 1);

    for (long i = 2; i * i <= Max; i++)
    {
        long pow = i * i;
        long start_idx = Min / pow;

        if (Min % pow != 0)
            start_idx++;

        for (long j = start_idx; pow * j <= Max; j++)
            check[(int)((pow * j) - Min)] = true;
    }

    int cnt = 0;
    for (int i = 0; i <= Max - Min; i++)
    {
        if (!check[i])
            cnt++;
    }

    cout << cnt << "\n";

    return 0;
}