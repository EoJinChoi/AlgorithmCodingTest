// 2024.10.2

#include <iostream>
#include <queue>
using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
void BFS(int n, int m, int N, int M);
int maze[101][101];
bool visited[101][101] = {false};

int main()
{
    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; i++)
    {
        string nums;
        cin >> nums;
        for (int j = 1; j <= M; j++)
        {
            maze[i][j] = nums[j - 1] - '0';
        }
    }

    BFS(1, 1, N, M);

    cout << maze[N][M] << "\n";

    return 0;
}

void BFS(int n, int m, int N, int M)
{
    queue<pair<int, int>> q;
    q.push(make_pair(n, m));
    visited[n][m] = true;

    while (!q.empty())
    {
        int now_x = q.front().first;
        int now_y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int x = now_x + dx[i];
            int y = now_y + dy[i];

            if (x > 0 && y > 0 && x <= N && y <= M)
            {
                if (maze[x][y] != 0 && !visited[x][y])
                {
                    visited[x][y] = true;
                    maze[x][y] = maze[now_x][now_y] + 1;
                    q.push(make_pair(x, y));
                }
            }
        }
    }
}