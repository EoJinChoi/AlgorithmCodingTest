// 2024.9.29

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> v;
vector<bool> visited;
void DFS(int n, int depth);
bool arrive;

int main()
{
    int N, E;
    arrive = false;
    cin >> N >> E;

    v.resize(N);
    visited = vector<bool>(N, false);

    for (int i = 0; i < E; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    int cnt = 1;
    for (int i = 0; i < N; i++)
    {
        DFS(i, 1);
        if (arrive)
            break;
    }

    if (arrive)
        cout << 1 << "\n";
    else
        cout << 0 << "\n";

    return 0;
}

void DFS(int n, int depth)
{
    if (depth == 5 || arrive)
    {
        arrive = true;
        return;
    }

    visited[n] = true;

    for (int i : v[n])
    {
        if (!visited[i])
            DFS(i, depth + 1);
    }

    visited[n] = false;
}