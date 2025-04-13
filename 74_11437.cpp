// 2025.4.13

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

static vector<vector<int>> tree;
static vector<int> depth;
static vector<int> parent;
static vector<bool> visited;

void BFS(int n);
int LCA(int a, int b); // Lowest Common Ancestor

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N;

    tree.resize(N + 1);
    depth.resize(N + 1);
    parent.resize(N + 1);
    visited.resize(N + 1);

    for (int i = 0; i < N - 1; i++)
    {
        int s, e;
        cin >> s >> e;

        tree[s].push_back(e);
        tree[e].push_back(s);
    }

    BFS(1);
    cin >> M;

    for (int i = 0; i < M; i++)
    {
        int n1, n2;
        cin >> n1 >> n2;

        int res = LCA(n1, n2);
        cout << res << "\n";
    }

    return 0;
}

void BFS(int n)
{
    queue<int> q;
    q.push(n);
    visited[n] = true;

    int level = 1;
    int now_size = 1;
    int cnt = 0;

    while (!q.empty())
    {
        int now = q.front();
        q.pop();

        for (int i : tree[now])
        {
            if (!visited[i])
            {
                visited[i] = true;
                q.push(i);
                parent[i] = now;
                depth[i] = level;
            }
        }

        cnt++;
        if (cnt == now_size)
        {
            cnt = 0;
            now_size = q.size();
            level++;
        }
    }
}

int LCA(int a, int b)
{
    if (depth[a] < depth[b])
    {
        int tmp = a;
        a = b;
        b = tmp;
    }

    while (depth[a] != depth[b])
        a = parent[a];

    while (a != b)
    {
        a = parent[a];
        b = parent[b];
    }

    return a;
}