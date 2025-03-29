// 2025.03.29

#include <iostream>
#include <vector>
#include <limits.h>
#include <tuple>
using namespace std;

typedef tuple<int, int, int> edge;
static int N, E;
static vector<long> mdist;
static vector<edge> edges;

int main()
{
    cin >> N >> E;
    mdist.resize(N + 1);
    fill(mdist.begin(), mdist.end(), LONG_MAX);

    for (int i = 0; i < E; i++)
    {
        int s, e, t;
        cin >> s >> e >> t;
        edges.push_back(make_tuple(s, e, t));
    }

    mdist[1] = 0;
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < E; j++)
        {
            edge cur = edges[j];
            int start = get<0>(cur);
            int end = get<1>(cur);
            int time = get<2>(cur);

            if (mdist[start] != LONG_MAX && mdist[end] > mdist[start] + time)
                mdist[end] = mdist[start] + time;
        }
    }

    bool mCycle = false;
    for (int i = 0; i < E; i++)
    {
        edge cur = edges[i];
        int start = get<0>(cur);
        int end = get<1>(cur);
        int time = get<2>(cur);

        if (mdist[start] != LONG_MAX && mdist[end] > mdist[start] + time)
            mCycle = true;
    }

    if (!mCycle)
    {
        for (int i = 2; i <= N; i++)
        {
            if (mdist[i] == LONG_MAX)
                cout << -1 << "\n";
            else
                cout << mdist[i] << "\n";
        }
    }
    else
        cout << -1 << "\n";

    return 0;
}