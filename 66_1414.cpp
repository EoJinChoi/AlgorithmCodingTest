// 2025.4.4

#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int find(int a);
void unionFunc(int a, int b);
static vector<int> parent;

int main()
{
    int sum = 0;
    int N;
    cin >> N;

    typedef tuple<int, int, int> edge;
    priority_queue<edge, vector<edge>, greater<edge>> pq;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            char tmpC = cin.get();

            if (tmpC == '\n')
                tmpC = cin.get();

            int tmp = 0;
            if (tmpC >= 'a' && tmpC <= 'z')
                tmp = tmpC - 'a' + 1;
            else if (tmpC >= 'A' && tmpC <= 'Z')
                tmp = tmpC - 'A' + 27;

            sum += tmp;
            if (i != j && tmp != 0)
                pq.push(make_tuple(tmp, i, j));
        }
    }

    parent.resize(N);
    for (int i = 0; i < N; i++)
        parent[i] = i;

    int useEdge = 0;
    int res = 0;

    while (!pq.empty())
    {
        edge now = pq.top();
        pq.pop();

        if (find(get<1>(now)) != find(get<2>(now)))
        {
            unionFunc(get<1>(now), get<2>(now));
            res += get<0>(now);
            useEdge++;
        }
    }

    if (useEdge == N - 1)
        cout << sum - res << "\n";
    else
        cout << -1 << "\n";

    return 0;
}

int find(int a)
{
    if (a == parent[a])
        return a;
    else
        return parent[a] = find(parent[a]);
}

void unionFunc(int a, int b)
{
    int parent_a = find(a);
    int parent_b = find(b);

    if (parent_a != parent_b)
        parent[parent_b] = parent_a;
}