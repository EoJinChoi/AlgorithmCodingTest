// 2024.9.28

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adj_list;
vector<bool> isVisited;
void DFS(int v);

int main()
{
    int V, E;
    cin >> V >> E;

    adj_list.resize(V + 1);
    isVisited = vector<bool>(V + 1, false);

    for (int i = 0; i < E; i++)
    {
        int s, e;
        cin >> s >> e;

        adj_list[s].push_back(e);
        adj_list[e].push_back(s);
    }

    int cnt = 0;
    for (int i = 1; i <= V; i++)
    {
        if (!isVisited[i])
        {
            cnt++;
            DFS(i);
        }
    }

    cout << cnt << "\n";

    return 0;
}

void DFS(int v)
{
    if (isVisited[v])
        return;

    isVisited[v] = true;

    for (int i : adj_list[v])
    {
        if (isVisited[i] == false)
            DFS(i);
    }
}