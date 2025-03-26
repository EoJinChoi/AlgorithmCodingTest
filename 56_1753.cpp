// 2025.3.26

#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

int main()
{
    int V, E, start;
    cin >> V >> E >> start;

    typedef pair<int, int> edge;
    vector<int> dist(V + 1);
    fill(dist.begin(), dist.end(), INT_MAX);
    vector<bool> visited(V + 1);
    vector<vector<edge>> adj_lst(V + 1);
    priority_queue<edge, vector<edge>, greater<edge>> q;

    for (int i = 0; i < E; i++)
    {
        int s, e, v;
        cin >> s >> e >> v;
        adj_lst[s].push_back(make_pair(e, v));
    }

    q.push(make_pair(0, start));
    dist[start] = 0;

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
            int next = tmp.first;
            int value = tmp.second;

            if (dist[next] > dist[idx] + value)
            {
                dist[next] = dist[idx] + value;
                q.push(make_pair(dist[next], next));
            }
        }
    }

    for (int i = 1; i <= V; i++)
    {
        if (visited[i])
            cout << dist[i] << "\n";
        else
            cout << "INF\n";
    }

    return 0;
}