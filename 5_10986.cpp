// 2024.7.18

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N, M;
    // 수의 개수 N, 나눌 수 M 입력
    cin >> N >> M;

    vector<long> S(N, 0);
    vector<long> r_cnt(M, 0);

    long cnt = 0;

    // 합 배열 저장
    for (int i = 0; i < N; i++)
    {
        long temp;
        cin >> temp;

        if (i == 0)
            S[i] = temp;

        else
            S[i] = S[i - 1] + temp;

        int remainder = S[i] % M;

        if (remainder == 0)
            cnt++;

        r_cnt[remainder]++;
    }

    // 원소 값이 같은 인덱스 2대를 뽑는 경우의 수 더하기
    for (int i = 0; i < M; i++)
    {
        if (r_cnt[i] > 1)
            cnt += (r_cnt[i] * (r_cnt[i] - 1) / 2);
    }

    // M으로 나누어 떨어지는 구간의 개수 출력
    cout << cnt << "\n";

    return 0;
}