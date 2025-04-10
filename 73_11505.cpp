// 2025.4.10

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

static vector<long> tree;
static int MOD = 1000000007;
void setTree(int n);
void changeVal(int idx, int v);
long getMul(int s, int e);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

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
    fill(tree.begin(), tree.end(), 1);

    for (int i = leftNodeStartIdx + 1; i <= leftNodeStartIdx + N; i++)
        cin >> tree[i];

    setTree(treeSize - 1);

    for (int i = 0; i < M + K; i++)
    {
        int op, s, e;
        cin >> op >> s >> e;

        if (op == 1)
            changeVal(leftNodeStartIdx + s, e);
        else if (op == 2)
        {
            s += leftNodeStartIdx;
            e += leftNodeStartIdx;

            cout << getMul(s, e) << "\n";
        }
    }

    return 0;
}

void setTree(int n)
{
    while (n != 1)
    {
        tree[n / 2] = tree[n / 2] * tree[n] % MOD;
        n--;
    }
}

void changeVal(int idx, int v)
{
    tree[idx] = v;

    while (idx > 1)
    {
        idx /= 2;
        tree[idx] = tree[idx * 2] % MOD * tree[idx * 2 + 1] % MOD;
    }
}

long getMul(int s, int e)
{
    long mul = 1;

    while (s <= e)
    {
        if (s % 2 == 1)
        {
            mul = mul * tree[s] % MOD;
            s++;
        }
        if (e % 2 == 0)
        {
            mul = mul * tree[e] % MOD;
            e--;
        }

        s /= 2;
        e /= 2;
    }
    return mul;
}