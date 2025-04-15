// 2025.4.15

#include <iostream>
using namespace std;

static int D[31][31];

int main()
{
    int T, N, M;

    for (int i = 0; i < 31; i++)
    {
        D[i][0] = 1;
        D[i][1] = i;
        D[i][i] = 1;
    }

    for (int i = 2; i < 31; i++)
    {
        for (int j = 2; j < i; j++)
            D[i][j] = D[i - 1][j - 1] + D[i - 1][j];
    }

    cin >> T;

    for (int i = 0; i < T; i++)
    {
        cin >> N >> M;
        cout << D[M][N] << "\n";
    }

    return 0;
}