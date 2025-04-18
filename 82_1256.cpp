// 2025.4.18

#include <iostream>
using namespace std;

static long C[202][202];

int main()
{
    int N, M, K;

    cin >> N >> M >> K;

    for (int i = 0; i <= 200; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (i == 0 || j == 0)
                C[i][j] = 1;
            else
            {
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
                if (C[i][j] > 1000000000)
                    C[i][j] = 1000000001;
            }
        }
    }

    if (C[N + M][M] < K)
        cout << "-1";
    else
    {
        while (!(N == 0 && M == 0))
        {
            if (C[N - 1 + M][M] >= K)
            {
                cout << "a";
                N--;
            }
            else
            {
                cout << "z";
                K = K - C[N - 1 + M][M];
                M--;
            }
        }
    }
    cout << "\n";

    return 0;
}