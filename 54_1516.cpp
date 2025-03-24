// 2025.3.24

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<vector<int>> adj_lst(N + 1);
    vector<int> time(N + 1);
    vector<int> indegree(N + 1);
    vector<int> res(N + 1);

    for (int i = 1; i <= N; i++)
    {
        cin >> time[i];
        while (true)
        {
            int num;
            cin >> num;

            if (num == -1)
                break;

            adj_lst[num].push_back(i);
            indegree[i]++;
        }
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

        for (int i : adj_lst[cur])
        {
            indegree[i]--;
            if (indegree[i] == 0)
                q.push(i);

            res[i] = max(res[i], res[cur] + time[cur]);
        }
    }

    for (int i = 1; i <= N; i++)
        cout << res[i] + time[i] << "\n";

    return 0;
}