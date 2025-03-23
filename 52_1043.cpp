// 2025.3.23

#include <iostream>
#include <vector>
using namespace std;

int find(int a);
void unionFunc(int a, int b);
static vector<int> parent;
static vector<int> trueP;
static vector<vector<int>> party;

int main()
{
    int N, M, T;
    cin >> N >> M;
    cin >> T;

    parent.resize(N + 1);
    trueP.resize(T);
    party.resize(M);

    for (int i = 0; i < T; i++)
        cin >> trueP[i];

    for (int i = 0; i < M; i++)
    {
        int p_cnt;
        cin >> p_cnt;

        for (int j = 0; j < p_cnt; j++)
        {
            int temp;
            cin >> temp;
            party[i].push_back(temp);
        }
    }

    for (int i = 0; i <= N; i++)
        parent[i] = i;

    for (int i = 0; i < M; i++)
    {
        int first = party[i][0];
        for (int j = 1; j < party[i].size(); j++)
            unionFunc(first, party[i][j]);
    }

    int res = 0;
    for (int i = 0; i < M; i++)
    {
        bool isPossible = true;
        int cur = party[i][0];

        for (int j = 0; j < T; j++)
        {
            if (find(cur) == find(trueP[j]))
            {
                isPossible = false;
                break;
            }
        }
        if (isPossible)
            res++;
    }

    cout << res << "\n";

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