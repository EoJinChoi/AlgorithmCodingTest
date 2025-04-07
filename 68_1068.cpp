// 2025.4.7

#include <iostream>
#include <vector>
using namespace std;

void DFS(int n);
static vector<vector<int>> tree;
static vector<bool> visited;
static int leafCnt = 0;
static int dNode = 0;

int main()
{
    int N;
    cin >> N;

    tree.resize(N);
    visited.resize(N);
    int root = 0;

    for (int i = 0; i < N; i++)
    {
        int p;
        cin >> p;

        if (p != -1)
        {
            tree[i].push_back(p);
            tree[p].push_back(i);
        }
        else
            root = i;
    }

    cin >> dNode;

    if (dNode == root)
        cout << 0 << "\n";
    else
    {
        DFS(root);
        cout << leafCnt << "\n";
    }

    return 0;
}

void DFS(int n)
{
    visited[n] = true;
    int cNode = 0;

    for (int i : tree[n])
    {
        if (!visited[i] && i != dNode)
        {
            cNode++;
            DFS(i);
        }
    }
    if (cNode == 0)
        leafCnt++;
}