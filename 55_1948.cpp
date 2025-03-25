// 2025.03.25

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;

    vector<vector<pair<int, int>>> adj_lst(N + 1);
    vector<vector<pair<int, int>>> rAdj_lst(N + 1);
    vector<int> indegree(N + 1);
    vector<int> res(N + 1);

    for (int i = 0; i < M; i++)
    {
        int s, e, t;
        cin >> s >> e >> t;

        adj_lst[s].push_back(make_pair(e, t));
        rAdj_lst[e].push_back(make_pair(s, t));
        indegree[e]++;
    }

    int s_city, e_city;
    cin >> s_city >> e_city;

    queue<int> q;
    q.push(s_city);

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (pair<int, int> i : adj_lst[cur])
        {
            indegree[i.first]--;
            res[i.first] = max(res[i.first], res[cur] + i.second);

            if (indegree[i.first] == 0)
                q.push(i.first);
        }
    }

    int cnt = 0;
    vector<bool> visited(N + 1);
    queue<int> rq;

    rq.push(e_city);
    visited[e_city] = true;

    while (!rq.empty())
    {
        int cur = rq.front();
        rq.pop();

        for (pair<int, int> i : rAdj_lst[cur])
        {
            if (res[i.first] + i.second == res[cur])
            {
                cnt++;
                if (!visited[i.first])
                {
                    visited[i.first] = true;
                    rq.push(i.first);
                }
            }
        }
    }

    cout << res[e_city] << "\n";
    cout << cnt << "\n";

    return 0;
}