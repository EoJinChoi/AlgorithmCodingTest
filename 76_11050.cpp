// 2025.4.14

#include <iostream>
using namespace std;

static int D[11][11];

int main()
{
    int N, K;
    cin >> N >> K;

    for (int i = 0; i <= N; i++)
    {
        D[i][1] = i;
        D[i][0] = 1;
        D[i][i] = 1;
    }

    for (int i = 3; i <= N; i++)
    {
        for (int j = 2; j < i; j++)
            D[i][j] = D[i - 1][j] + D[i - 1][j - 1];
    }

    cout << D[N][K] << "\n";

    return 0;
}