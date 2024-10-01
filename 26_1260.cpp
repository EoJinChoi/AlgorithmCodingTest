// 2024.10.1

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

void DFS(int n);
void BFS(int n);
vector<vector<int>> v;
vector<bool> visited;

int main()
{
    int N, E, start;
    cin >> N >> E >> start;

    v.resize(N + 1);

    for (int i = 0; i < E; i++)
    {
        int a, b;
        cin >> a >> b;

        v[a].push_back(b);
        v[b].push_back(a);
    }

    // 방문할 수 있는 노드 여러 개일 때 노드 번호 작은 것을 먼저 방문
    for (int i = 1; i <= N; i++)
        sort(v[i].begin(), v[i].end());

    // DFS
    visited = vector<bool>(N + 1, false);
    DFS(start);
    cout << "\n";

    // BFS
    visited = vector<bool>(N + 1, false);
    BFS(start);
    cout << "\n";

    return 0;
}

void DFS(int n)
{
    cout << n << " ";
    visited[n] = true;

    for (int i : v[n])
    {
        if (!visited[i])
            DFS(i);
    }
}

void BFS(int n)
{
    queue<int> q;
    q.push(n);
    visited[n] = true;

    while (!q.empty())
    {
        int cur_node = q.front();
        q.pop();
        cout << cur_node << " ";

        for (int i : v[cur_node])
        {
            if (!visited[i])
            {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}