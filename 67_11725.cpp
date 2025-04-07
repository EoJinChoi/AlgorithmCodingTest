// 2025.4.7

#include <iostream>
#include <vector>
using namespace std;

void DFS(int n);
static vector<vector<int>> tree;
static vector<bool> visited;
static vector<int> answer;

int main()
{
    int N;
    cin >> N;

    tree.resize(N + 1);
    visited.resize(N + 1);
    answer.resize(N + 1);

    for (int i = 0; i < N - 1; i++)
    {
        int n1, n2;
        cin >> n1 >> n2;

        tree[n1].push_back(n2);
        tree[n2].push_back(n1);
    }

    DFS(1);

    for (int i = 2; i <= N; i++)
        cout << answer[i] << "\n";

    return 0;
}

void DFS(int n)
{
    visited[n] = true;

    for (int i : tree[n])
    {
        if (!visited[i])
        {
            answer[i] = n;
            DFS(i);
        }
    }
}