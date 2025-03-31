// 2025.3.31

#include <iostream>
using namespace std;

int main()
{
    long mdist[101][101];
    int N, E;
    cin >> N >> E;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (i == j)
                mdist[i][j] = 0;
            else
                mdist[i][j] = 10000001;
        }
    }

    for (int i = 0; i < E; i++)
    {
        int s, e, v;
        cin >> s >> e >> v;

        if (mdist[s][e] > v)
            mdist[s][e] = v;
    }

    // Floyd-Warshall
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

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (mdist[i][j] == 10000001)
                cout << 0 << " ";
            else
                cout << mdist[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}