// 2025.3.27

#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

typedef pair<int, int> edge;
vector<vector<edge>> adj_lst;
vector<bool> visited;
vector<int> m_dist;
int dijkstra(int start, int end);

int main()
{
    int N, M;
    cin >> N >> M;

    adj_lst.resize(N + 1);
    visited.resize(N + 1);
    m_dist.resize(N + 1);
    fill(m_dist.begin(), m_dist.end(), INT_MAX);

    for (int i = 0; i < M; i++)
    {
        int s, e, v;
        cin >> s >> e >> v;

        adj_lst[s].push_back(make_pair(v, e));
    }

    int start, end;
    cin >> start >> end;

    int res = dijkstra(start, end);

    cout << res << "\n";

    return 0;
}

int dijkstra(int start, int end)
{
    priority_queue<edge, vector<edge>, greater<edge>> q;
    q.push(make_pair(0, start));
    m_dist[start] = 0;

    while (!q.empty())
    {
        edge cur = q.top();
        q.pop();

        int idx = cur.second;

        if (visited[idx])
            continue;

        visited[idx] = true;
        for (int i = 0; i < adj_lst[idx].size(); i++)
        {
            edge tmp = adj_lst[idx][i];
            int next = tmp.second;
            int value = tmp.first;

            if (m_dist[next] > m_dist[idx] + value)
            {
                m_dist[next] = m_dist[idx] + value;
                q.push(make_pair(m_dist[next], next));
            }
        }
    }

    return m_dist[end];
}