// 2025.03.04

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N, K;
    int cnt = 0;

    cin >> N >> K;
    vector<int> coin(N);

    for (int i = 0; i < N; i++)
        cin >> coin[i];

    for (int i = N - 1; i >= 0; i--)
    {
        if (coin[i] <= K)
        {
            cnt += K / coin[i];
            K = K % coin[i];
        }
        if (K == 0)
            break;
    }

    cout << cnt << "\n";

    return 0;
}