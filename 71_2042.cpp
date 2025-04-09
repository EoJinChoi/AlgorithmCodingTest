// 2025.4.9

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

static vector<long> tree;
void setTree(int i);
void changeVal(int idx, long v);
long getSum(int s, int e);

int main()
{
    int N, M, K;
    cin >> N >> M >> K;

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

    for (int i = leftNodeStartIdx + 1; i <= leftNodeStartIdx + N; i++)
        cin >> tree[i];

    setTree(treeSize - 1);

    for (int i = 0; i < M + K; i++)
    {
        long op, s, e;
        cin >> op >> s >> e;

        if (op == 1)
            changeVal(leftNodeStartIdx + s, e);
        else if (op == 2)
        {
            s += leftNodeStartIdx;
            e += leftNodeStartIdx;

            cout << getSum(s, e) << "\n";
        }
    }

    return 0;
}

void setTree(int i)
{
    while (i != 1)
    {
        tree[i / 2] += tree[i];
        i--;
    }
}

void changeVal(int idx, long v)
{
    long diff = v - tree[idx];

    while (idx > 0)
    {
        tree[idx] += diff;
        idx /= 2;
    }
}

long getSum(int s, int e)
{
    long sum = 0;

    while (s <= e)
    {
        if (s % 2 == 1)
        {
            sum += tree[s];
            s++;
        }
        if (e % 2 == 0)
        {
            sum += tree[e];
            e--;
        }

        s /= 2;
        e /= 2;
    }
    return sum;
}