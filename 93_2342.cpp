// 2025.6.16

#include <iostream>
#include <cmath>
using namespace std;

int DP[100001][5][5];

int mp[5][5] = {{0, 2, 2, 2, 2},
                {2, 1, 3, 4, 3},
                {2, 3, 1, 3, 4},
                {2, 4, 3, 1, 3},
                {2, 3, 4, 3, 1}};

int main()
{
    for (int i = 0; i < 100001; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            for (int k = 0; k < 5; k++)
                DP[i][j][k] = 100000 * 4 + 1;
        }
    }

    DP[0][0][0] = 0;
    int n, s = 1;

    while (true)
    {
        cin >> n;
        if (n == 0)
            break;

        for (int i = 0; i < 5; i++)
        {
            if (n == i)
                continue;

            for (int j = 0; j < 5; j++)
                DP[s][i][n] = min(DP[s - 1][i][j] + mp[j][n], DP[s][i][n]);
        }

        for (int j = 0; j < 5; j++)
        {
            if (n == j)
                continue;

            for (int i = 0; i < 5; i++)
                DP[s][n][j] = min(DP[s - 1][i][j] + mp[i][n], DP[s][n][j]);
        }

        s++;
    }

    s--;
    int minVal = 100000 * 4 + 1;

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
            minVal = min(minVal, DP[s][i][j]);
    }

    cout << minVal << "\n";

    return 0;
}