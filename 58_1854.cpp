// 2025.3.28

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> Node;
static int value[1001][1001];
static priority_queue<int> distQ[1001];

int main()
{
    int N, M, K;
    cin >> N >> M >> K;

    for (int i = 0; i < M; i++)
    {
        int s, e, t;
        cin >> s >> e >> t;

        value[s][e] = t;
    }

    priority_queue<Node, vector<Node>, greater<Node>> pq;
    pq.push(make_pair(0, 1));
    distQ[1].push(0);

    while (!pq.empty())
    {
        Node cur = pq.top();
        pq.pop();

        for (int i = 1; i <= N; i++)
        {
            if (value[cur.second][i] != 0)
            {
                if (distQ[i].size() < K)
                {
                    distQ[i].push(cur.first + value[cur.second][i]);
                    pq.push(make_pair(cur.first + value[cur.second][i], i));
                }
                else if (distQ[i].top() > cur.first + value[cur.second][i])
                {
                    distQ[i].pop();
                    distQ[i].push(cur.first + value[cur.second][i]);
                    pq.push(make_pair(cur.first + value[cur.second][i], i));
                }
            }
        }
    }

    for (int i = 1; i <= N; i++)
    {
        if (distQ[i].size() == K)
            cout << distQ[i].top() << "\n";
        else
            cout << -1 << "\n";
    }

    return 0;
}