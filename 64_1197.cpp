// 2025.4.2

#include <iostream>
#include <tuple>
#include <queue>
using namespace std;

int find(int a);
void unionFunc(int a, int b);
typedef tuple<int, int, int> edge;
static vector<int> parent;

int main()
{
    int N, E;
    cin >> N >> E;

    priority_queue<edge, vector<edge>, greater<edge>> pq;
    parent.resize(N + 1);

    for (int i = 1; i <= N; i++)
        parent[i] = i;

    for (int i = 0; i < E; i++)
    {
        int s, e, v;
        cin >> s >> e >> v;
        pq.push(make_tuple(v, s, e));
    }

    int answer = 0;
    int useEdge = 0;

    while (useEdge < N - 1)
    {
        edge cur = pq.top();
        pq.pop();

        int v = get<0>(cur);
        int s = get<1>(cur);
        int e = get<2>(cur);

        if (find(s) != find(e))
        {
            unionFunc(s, e);
            answer += v;
            useEdge++;
        }
    }

    cout << answer << "\n";

    return 0;
}

int find(int a)
{
    if (a == parent[a])
        return a;
    else
    {
        return parent[a] = find(parent[a]);
    }
}

void unionFunc(int a, int b)
{
    int parent_a = find(a);
    int parent_b = find(b);

    if (parent_a != parent_b)
        parent[parent_b] = parent_a;
}