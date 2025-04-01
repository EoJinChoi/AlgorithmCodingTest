// 2025.4.1

#include <iostream>
using namespace std;

int main()
{
    int N, M;
    int mdist[101][101];

    cin >> N >> M;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (i == j)
                mdist[i][j] = 0;
            else
                mdist[i][j] = 10000;
        }
    }

    for (int i = 0; i < M; i++)
    {
        int s, e;
        cin >> s >> e;

        mdist[s][e] = 1;
        mdist[e][s] = 1;
    }

    for (int k = 1; k <= N; k++)
    {
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                if (mdist[i][j] > mdist[i][k] + mdist[k][j])
                    mdist[i][j] = mdist[i][k] + mdist[k][j];
            }
        }
    }

    int Min = 1000000;
    int answer = -1;

    for (int i = 1; i <= N; i++)
    {
        int sum = 0;
        for (int j = 1; j <= N; j++)
        {
            sum += mdist[i][j];
        }

        if (Min > sum)
        {
            Min = sum;
            answer = i;
        }
    }

    cout << answer << "\n";

    return 0;
}