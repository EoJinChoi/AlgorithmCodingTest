// 2025.03.19

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

void BFS(int node);
static vector<vector<int>> adj_lst;
static vector<int> answer;
static vector<int> visited;

int main()
{
    int N, E, dist, start;
    cin >> N >> E >> dist >> start;

    adj_lst.resize(N + 1);
    visited.resize(N + 1);

    for (int i = 0; i < E; i++)
    {
        int s, e;
        cin >> s >> e;
        adj_lst[s].push_back(e);
    }

    for (int i = 0; i <= N; i++)
        visited[i] = -1;

    BFS(start);

    for (int i = 0; i <= N; i++)
    {
        if (visited[i] == dist)
            answer.push_back(i);
    }

    if (answer.empty())
        cout << -1 << "\n";
    else
    {
        sort(answer.begin(), answer.end());
        for (int i : answer)
            cout << i << "\n";
    }

    return 0;
}

void BFS(int node)
{
    queue<int> q;
    q.push(node);
    visited[node]++;

    while (!q.empty())
    {
        int cur_node = q.front();
        q.pop();

        for (int i : adj_lst[cur_node])
        {
            if (visited[i] == -1)
            {
                visited[i] = visited[cur_node] + 1;
                q.push(i);
            }
        }
    }
}