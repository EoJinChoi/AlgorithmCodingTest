// 2025 3.30

#include <iostream>
#include <vector>
#include <tuple>
#include <limits.h>
using namespace std;

typedef tuple<int, int, int> edge;
static vector<long> mmoney, cmoney;
static vector<edge> edges;
static int N, E, sCity, eCity;

int main()
{
    cin >> N >> sCity >> eCity >> E;

    mmoney.resize(N);
    cmoney.resize(N);
    fill(mmoney.begin(), mmoney.end(), LONG_MIN);

    for (int i = 0; i < E; i++)
    {
        int s, e, p;
        cin >> s >> e >> p;

        edges.push_back(make_tuple(s, e, p));
    }

    for (int i = 0; i < N; i++)
        cin >> cmoney[i];

    mmoney[sCity] = cmoney[sCity];

    for (int i = 0; i <= N + 50; i++)
    {
        for (int j = 0; j < E; j++)
        {
            int s = get<0>(edges[j]);
            int e = get<1>(edges[j]);
            int p = get<2>(edges[j]);

            if (mmoney[s] == LONG_MIN)
                continue;
            else if (mmoney[s] == LONG_MAX)
                mmoney[e] = LONG_MAX;
            else if (mmoney[e] < mmoney[s] + cmoney[e] - p)
            {
                mmoney[e] = mmoney[s] + cmoney[e] - p;

                if (i >= N - 1)
                    mmoney[e] = LONG_MAX;
            }
        }
    }

    if (mmoney[eCity] == LONG_MIN)
        cout << "gg\n";
    else if (mmoney[eCity] == LONG_MAX)
        cout << "Gee\n";
    else
        cout << mmoney[eCity] << "\n";

    return 0;
}