// 2025.03.04

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;

    int start = 1;
    int end = K;
    int answer;

    while (start <= end)
    {
        int mid = (start + end) / 2;
        int cnt = 0;

        for (int i = 1; i <= N; i++)
            cnt += min(mid / i, N);

        if (cnt < K)
            start = mid + 1;
        else
        {
            end = mid - 1;
            answer = mid;
        }
    }

    cout << answer << "\n";

    return 0;
}