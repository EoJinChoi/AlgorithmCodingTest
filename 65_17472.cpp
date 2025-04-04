// 2025.4.4

#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
using namespace std;

void BFS(int i, int j);
int find(int a);
void unionFunc(int a, int b);

static int dr[] = {-1, 0, 1, 0};
static int dc[] = {0, -1, 0, 1};
static int map[10][10];
static bool visited[10][10] = {false,};
static vector<int> parent;
static int N, M, sNum;

static vector<vector<pair<int, int>>> sumList;
static vector<pair<int, int>> mList;

typedef tuple<int, int, int> edge;
static priority_queue<edge, vector<edge>, greater<edge>> pq;

int main()
{
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
            cin >> map[i][j];
    }

    sNum = 1;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (map[i][j] != 0 && visited[i][j] == false)
            {
                BFS(i, j);
                sNum++;
                sumList.push_back(mList);
            }
        }
    }

    for (int i = 0; i < sumList.size(); i++)
    {
        vector<pair<int, int>> now = sumList[i];

        for (int j = 0; j < now.size(); j++)
        {
            int r = now[j].first;
            int c = now[j].second;
            int now_sum = map[r][c];

            for (int d = 0; d < 4; d++)
            {
                int tmpR = dr[d];
                int tmpC = dc[d];
                int bLength = 0;

                while (r + tmpR >= 0 && r + tmpR < N && c + tmpC >= 0 && c + tmpC < M)
                {
                    if (map[r + tmpR][c + tmpC] == now_sum)
                        break;
                    else if (map[r + tmpR][c + tmpC] != 0)
                    {
                        if (bLength > 1)
                            pq.push(make_tuple(bLength, now_sum, map[r + tmpR][c + tmpC]));
                        break;
                    }
                    else
                        bLength++;

                    if (tmpR < 0)
                        tmpR--;
                    else if (tmpR > 0)
                        tmpR++;
                    else if (tmpC < 0)
                        tmpC--;
                    else if (tmpC > 0)
                        tmpC++;
                }
            }
        }
    }

    parent.resize(sNum);
    for (int i = 0; i < sNum; i++)
        parent[i] = i;

    int useEdge = 0;
    int res = 0;

    while (!pq.empty())
    {
        edge cur = pq.top();
        pq.pop();

        if (find(get<1>(cur)) != find(get<2>(cur)))
        {
            unionFunc(get<1>(cur), get<2>(cur));
            res += get<0>(cur);
            useEdge++;
        }
    }

    if (useEdge == sNum - 2)
        cout << res << "\n";
    else
        cout << -1 << "\n";

    return 0;
}

void BFS(int i, int j)
{
    queue<pair<int, int>> q;
    mList.clear();

    q.push(make_pair(i, j));
    mList.push_back(make_pair(i, j));
    visited[i][j] = true;
    map[i][j] = sNum;

    while (!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for (int d = 0; d < 4; d++)
        {
            int tmpR = dr[d];
            int tmpC = dc[d];

            if (r + tmpR >= 0 && r + tmpR < N && c + tmpC >= 0 && c + tmpC < M)
            {
                if (visited[r + tmpR][c + tmpC] == false && map[r + tmpR][c + tmpC] != 0)
                {
                    map[r + tmpR][c + tmpC] = sNum;
                    visited[r + tmpR][c + tmpC] = true;
                    mList.push_back(make_pair(r + tmpR, c + tmpC));
                    q.push(make_pair(r + tmpR, c + tmpC));
                }
            }
        }
    }
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