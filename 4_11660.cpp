// 2024.7.18

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, sum_num;
    // 배열 크기, 연산 횟수 입력
    cin >> N >> sum_num;

    vector<vector<int>> A(N + 1, vector<int>(N + 1, 0));
    vector<vector<int>> D(N + 1, vector<int>(N + 1, 0));

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            // 원본 배열 저장
            cin >> A[i][j];

            // 합 배열 저장
            D[i][j] = D[i][j - 1] + D[i - 1][j] - D[i - 1][j - 1] + A[i][j];
        }
    }

    for (int i = 0; i < sum_num; i++)
    {
        int x1, y1, x2, y2;
        // 구간 입력
        cin >> x1 >> y1 >> x2 >> y2;

        // 구간 합 계산 후 출력
        int res = D[x2][y2] - D[x2][y1 - 1] - D[x1 - 1][y2] + D[x1 - 1][y1 - 1];
        cout << res << "\n";
    }

    return 0;
}