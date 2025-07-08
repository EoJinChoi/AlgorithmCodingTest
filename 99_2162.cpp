// 2025.7.8

#include <iostream>
#include <cmath>
using namespace std;

int parent[3001];
int line[3001][4];

int find(int a);
void Union(int a, int b);
int ccw(long x1, long y1, long x2, long y2, long x3, long y3);
bool isOverlab(long x1, long y1, long x2, long y2, long x3, long y3, long x4, long y4);
bool isCross(long x1, long y1, long x2, long y2, long x3, long y3, long x4, long y4);

int main()
{
    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
        parent[i] = -1;

    for (int i = 0; i < N; i++)
    {
        cin >> line[i][0] >> line[i][1] >> line[i][2] >> line[i][3];

        for (int j = 0; j < i; j++)
        {
            if (isCross(line[i][0], line[i][1], line[i][2], line[i][3], line[j][0], line[j][1], line[j][2], line[j][3]))
                Union(i, j);
        }
    }

    int g_num = 0, l_num = 0;

    for (int i = 0; i < N; i++)
    {
        if (parent[i] < 0)
        {
            g_num++;
            l_num = min(l_num, parent[i]);
        }
    }

    cout << g_num << "\n";
    cout << -l_num << "\n";

    return 0;
}

int find(int a)
{
    if (parent[a] < 0)
        return a;

    return parent[a] = find(parent[a]);
}

void Union(int a, int b)
{
    int parent_a = find(a);
    int parent_b = find(b);

    if (parent_a == parent_b)
        return;

    parent[parent_a] += parent[parent_b];
    parent[parent_b] = parent_a;
}

int ccw(long x1, long y1, long x2, long y2, long x3, long y3)
{
    long res = (x1 * y2 + x2 * y3 + x3 * y1) - (x2 * y1 + x3 * y2 + x1 * y3);

    if (res > 0)
        return 1;
    else if (res < 0)
        return -1;

    return 0;
}

bool isOverlab(long x1, long y1, long x2, long y2, long x3, long y3, long x4, long y4)
{
    if (min(x1, x2) <= max(x3, x4) && min(x3, x4) <= max(x1, x2) && min(y1, y2) <= max(y3, y4) && min(y3, y4) <= max(y1, y2))
        return true;
    else
        return false;
}

bool isCross(long x1, long y1, long x2, long y2, long x3, long y3, long x4, long y4)
{
    int abc = ccw(x1, y1, x2, y2, x3, y3);
    int abd = ccw(x1, y1, x2, y2, x4, y4);
    int cda = ccw(x3, y3, x4, y4, x1, y1);
    int cdb = ccw(x3, y3, x4, y4, x2, y2);

    if (abc * abd == 0 && cda * cdb == 0)
        return isOverlab(x1, y1, x2, y2, x3, y3, x4, y4);
    else if (abc * abd <= 0 && cda * cdb <= 0)
        return true;
    else
        return false;
}