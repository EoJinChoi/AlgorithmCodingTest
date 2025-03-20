// 2025.3.20

#include <iostream>
#include <queue>
using namespace std;

void BFS(int node);
vector<vector<int>> adj_lst;
vector<bool> visited;
vector<int> rel;

int main()
{
    int N, R;
    cin >> N >> R;

    adj_lst.resize(N + 1);
    visited.resize(N + 1);
    rel.resize(N + 1);

    for (int i = 0; i < R; i++)
    {
        int s, e;
        cin >> s >> e;
        adj_lst[s].push_back(e);
    }

    for (int i = 1; i <= N; i++)
    {
        fill(visited.begin(), visited.end(), false);
        BFS(i);
    }

    int Max = 0;
    for (int i = 1; i <= N; i++)
    {
        if (rel[i] > Max)
            Max = rel[i];
    }

    for (int i = 1; i <= N; i++)
    {
        if (rel[i] == Max)
            cout << i << " ";
    }
    cout << "\n";

    return 0;
}

void BFS(int node)
{
    queue<int> q;
    q.push(node);
    visited[node] = true;

    while (!q.empty())
    {
        int cur_node = q.front();
        q.pop();

        for (int i : adj_lst[cur_node])
        {
            if (!visited[i])
            {
                visited[i] = true;
                rel[i]++;
                q.push(i);
            }
        }
    }
}