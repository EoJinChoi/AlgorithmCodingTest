// 2025.03.21

#include <iostream>
#include <vector>
using namespace std;

int find(int a);
void unionFunc(int a, int b);
bool isSame(int a, int b);
static vector<int> parent;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    parent.resize(N + 1);
    for (int i = 0; i <= N; i++)
        parent[i] = i;

    for (int i = 0; i < M; i++)
    {
        int op, a, b;
        cin >> op >> a >> b;

        if (op == 0)
            unionFunc(a, b);
        else
        {
            if (isSame(a, b))
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }

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
    int a_parent = find(a);
    int b_parent = find(b);

    if (a_parent != b_parent)
        parent[b_parent] = a_parent;
}

bool isSame(int a, int b)
{
    int a_parent = find(a);
    int b_parent = find(b);

    if (a_parent == b_parent)
        return true;
    else
        return false;
}