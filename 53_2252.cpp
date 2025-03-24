// 2025.3.24

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int N, E;
    cin >> N >> E;

    vector<vector<int>> adj_lst;
    vector<int> indegree;
    adj_lst.resize(N + 1);
    indegree.resize(N + 1);

    for (int i = 0; i < E; i++)
    {
        int s, e;
        cin >> s >> e;

        adj_lst[s].push_back(e);
        indegree[e]++;
    }

    queue<int> q;
    for (int i = 1; i <= N; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        cout << cur << " ";

        for (int i : adj_lst[cur])
        {
            indegree[i]--;
            if (indegree[i] == 0)
                q.push(i);
        }
    }
    cout << "\n";

    return 0;
}