// 2025.3.20

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void DFS(int node);
vector<vector<int>> adj_lst;
vector<bool> visited;
vector<int> check;
bool isEven;

int main()
{
    int T;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        int N, E;
        cin >> N >> E;

        adj_lst.resize(N + 1);
        visited.resize(N + 1);
        check.resize(N + 1);
        isEven = true;

        for (int j = 0; j < E; j++)
        {
            int s, e;
            cin >> s >> e;

            adj_lst[s].push_back(e);
            adj_lst[e].push_back(s);
        }

        for (int i = 1; i <= N; i++)
        {
            if (isEven)
                DFS(i);
            else
                break;
        }

        if (isEven)
            cout << "YES\n";
        else
            cout << "NO\n";

        for (int i = 0; i <= N; i++)
        {
            adj_lst[i].clear();
            visited[i] = false;
            check[i] = 0;
        }
    }

    return 0;
}

void DFS(int node)
{
    visited[node] = true;

    for (int i : adj_lst[node])
    {
        if (!visited[i])
        {
            check[i] = (check[node] + 1) % 2;
            DFS(i);
        }
        else if (check[node] == check[i])
            isEven = false;
    }
}