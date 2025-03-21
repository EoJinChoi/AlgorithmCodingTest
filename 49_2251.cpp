// 2025.3.21

#include <iostream>
#include <queue>
using namespace std;

void BFS();

static int Sender[] = {0, 0, 1, 1, 2, 2};
static int Receiver[] = {1, 2, 0, 2, 0, 1};
static bool visited[201][201];
static bool answer[201];
static int now[3];

int main()
{
    cin >> now[0] >> now[1] >> now[2];

    BFS();

    for (int i = 0; i < 201; i++)
    {
        if (answer[i])
            cout << i << " ";
    }
    cout << "\n";

    return 0;
}

void BFS()
{
    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));
    visited[0][0] = true;
    answer[now[2]] = true;

    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();

        int A = p.first;
        int B = p.second;
        int C = now[2] - A - B;

        for (int i = 0; i < 6; i++)
        {
            int next[] = {A, B, C};

            next[Receiver[i]] += next[Sender[i]];
            next[Sender[i]] = 0;

            if (next[Receiver[i]] > now[Receiver[i]])
            {
                next[Sender[i]] = next[Receiver[i]] - now[Receiver[i]];
                next[Receiver[i]] = now[Receiver[i]];
            }

            if (!visited[next[0]][next[1]])
            {
                visited[next[0]][next[1]] = true;
                q.push(make_pair(next[0], next[1]));

                if (next[0] == 0)
                    answer[next[2]] = true;
            }
        }
    }
}