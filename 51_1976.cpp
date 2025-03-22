// 2025.3.22

#include <iostream>
#include <vector>
using namespace std;

int find(int a);
void unionFunc(int a, int b);
static vector<int> parent;

int main()
{
    int N, M;
    cin >> N >> M;

    int city[N + 1][N + 1];
    int route[M];
    parent.resize(N + 1);

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> city[i][j];
        }
    }

    for (int i = 0; i < M; i++)
        cin >> route[i];

    // init parent
    for (int i = 1; i <= N; i++)
        parent[i] = i;

    // connect cities
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (city[i][j] == 1)
                unionFunc(i, j);
        }
    }

    int idx = find(route[0]);
    bool connect = true;

    for (int i = 1; i < M; i++)
    {
        if (idx != find(route[i]))
        {
            connect = false;
            break;
        }
    }
    if (connect)
        cout << "YES\n";
    else
        cout << "NO\n";

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