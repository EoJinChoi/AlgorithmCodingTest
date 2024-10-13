// 2024.10.13

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair<int, int> edge;
vector<vector<edge>> adj_list;
vector<bool> visited;
vector<int> dist;
void BFS(int n);

int main()
{
    int N;
    cin >> N;
    adj_list.resize(N + 1);

    for (int i = 0; i < N; i++)
    {
        int node;
        cin >> node;

        while (true)
        {
            int E, D;
            cin >> E;
            if (E == -1)
                break;
            cin >> D;
            adj_list[node].push_back(edge(E, D));
        }
    }

    dist = vector<int>(N + 1, 0);
    visited = vector<bool>(N + 1, false);
    BFS(1);

    int max = 1;
    for (int i = 2; i <= N; i++)
    {
        if (dist[max] < dist[i])
            max = i;
    }

    dist = vector<int>(N + 1, 0);
    visited = vector<bool>(N + 1, false);
    BFS(max);

    sort(dist.begin(), dist.end());
    cout << dist[N] << "\n";

    return 0;
}

void BFS(int n)
{
    queue<int> q;
    q.push(n);
    visited[n] = true;

    while (!q.empty())
    {
        int curr_node = q.front();
        q.pop();

        for (edge i : adj_list[curr_node])
        {
            if (!visited[i.first])
            {
                visited[i.first] = true;
                q.push(i.first);
                dist[i.first] = dist[curr_node] + i.second;
            }
        }
    }
}