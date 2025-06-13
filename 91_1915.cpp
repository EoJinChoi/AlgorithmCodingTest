// 2025.6.13

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int D[1000][1000];
    int n, m;
    int max = 0;

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;

        for (int j = 0; j < m; j++)
        {
            D[i][j] = str[j] - '0';

            if (D[i][j] == 1 && i > 0 && j > 0)
                D[i][j] = min(min(D[i - 1][j - 1], D[i - 1][j]), D[i][j - 1]) + 1;

            if (D[i][j] > max)
                max = D[i][j];
        }
    }

    cout << max * max << "\n";

    return 0;
}