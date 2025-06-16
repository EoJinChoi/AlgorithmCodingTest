// 2025.6.16

#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;

vector<pair<int, int>> p;
long D[501][501];
int execute(int s, int e);

int main()
{
    int N;
    cin >> N;

    p.resize(N + 1);

    for (int i = 0; i <= N; i++)
    {
        for (int j = 0; j <= N; j++)
            D[i][j] = -1;
    }

    for (int i = 1; i <= N; i++)
    {
        int a, b;
        cin >> a >> b;
        p[i] = make_pair(a, b);
    }

    cout << execute(1, N) << "\n";

    return 0;
}

int execute(int s, int e)
{
    if (D[s][e] != -1)
        return D[s][e];

    if (s == e)
        return 0;

    if (s + 1 == e)
        return p[s].first * p[s].second * p[e].second;

    int res = INT_MAX;
    for (int i = s; i < e; i++)
        res = min(res, p[s].first * p[i].second * p[e].second + execute(s, i) + execute(i + 1, e));

    return D[s][e] = res;
}