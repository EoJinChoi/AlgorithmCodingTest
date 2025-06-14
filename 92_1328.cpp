// 2025.6.14

#include <iostream>
using namespace std;

long D[101][101][101];

int main()
{
    int N, L, R;
    long mod = 1000000007;

    cin >> N >> L >> R;

    D[1][1][1] = 1;
    for (int i = 2; i <= N; i++)
    {
        for (int j = 1; j <= L; j++)
        {
            for (int k = 1; k <= R; k++)
                D[i][j][k] = (D[i - 1][j - 1][k] + D[i - 1][j][k - 1] + D[i - 1][j][k] * (i - 2)) % mod;
        }
    }

    cout << D[N][L][R] << "\n";

    return 0;
}