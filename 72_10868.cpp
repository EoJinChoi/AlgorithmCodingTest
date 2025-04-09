// 2025.4.9

#include <iostream>
#include <vector>
#include <cmath>
#include <limits.h>
using namespace std;

static vector<int> tree;
void setTree(int n);
int getMin(int s, int e);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    int treeHeight = 0;
    int length = N;

    while (length != 0)
    {
        length /= 2;
        treeHeight++;
    }

    int treeSize = int(pow(2, treeHeight + 1));
    int leftNodeStartIdx = treeSize / 2 - 1;

    tree.resize(treeSize + 1);
    fill(tree.begin(), tree.end(), INT_MAX);

    for (int i = leftNodeStartIdx + 1; i <= leftNodeStartIdx + N; i++)
        cin >> tree[i];

    setTree(treeSize - 1);

    for (int i = 0; i < M; i++)
    {
        int s, e;
        cin >> s >> e;

        s += leftNodeStartIdx;
        e += leftNodeStartIdx;

        cout << getMin(s, e) << "\n";
    }

    return 0;
}

void setTree(int n)
{
    while (n != 1)
    {
        if (tree[n / 2] > tree[n])
            tree[n / 2] = tree[n];
        n--;
    }
}

int getMin(int s, int e)
{
    int Min = INT_MAX;

    while (s <= e)
    {
        if (s % 2 == 1)
        {
            Min = min(Min, tree[s]);
            s++;
        }
        if (e % 2 == 0)
        {
            Min = min(Min, tree[e]);
            e--;
        }

        s /= 2;
        e /= 2;
    }
    return Min;
}