// 2024.7.16

#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, sum_num;
    // 수의 개수, 연산 횟수 입력
    cin >> N >> sum_num;

    int S[100001] = {};
    // 수 입력 받으면서 합 배열 생성
    for (int i = 1; i <= N; i++)
    {
        int temp;
        cin >> temp;
        S[i] = S[i - 1] + temp;
    }

    // 구간 합 공식으로 계산 후 출력
    for (int i = 0; i < sum_num; i++)
    {
        int start, end;
        cin >> start >> end;

        int res = S[end] - S[start - 1];
        cout << res << "\n";
    }

    return 0;
}