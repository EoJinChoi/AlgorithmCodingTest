// 2025.4.17

#include <iostream>
using namespace std;

int main()
{
    int N, op;
    long fac[21], P[21];
    bool visited[21] = {
        false,
    };

    cin >> N >> op;

    fac[0] = 1;
    for (int i = 1; i <= N; i++)
        fac[i] = fac[i - 1] * i;

    if (op == 1)
    {
        long K;
        cin >> K;

        for (int i = 1; i <= N; i++)
        {
            for (int j = 1, cnt = 1; j <= N; j++)
            {
                if (visited[j])
                    continue;

                if (K <= fac[N - i] * cnt)
                {
                    K -= (fac[N - i] * (cnt - 1));
                    P[i] = j;
                    visited[j] = true;
                    break;
                }
                cnt++;
            }
        }

        for (int i = 1; i <= N; i++)
            cout << P[i] << " ";
        cout << "\n";
    }
    else
    {
        long K = 1;

        for (int i = 1; i <= N; i++)
        {
            cin >> P[i];
            long cnt = 0;

            for (int j = 1; j < P[i]; j++)
            {
                if (visited[j] == false)
                    cnt++;
            }
            K += cnt * fac[N - i];
            visited[P[i]] = true;
        }
        cout << K << "\n";
    }
    return 0;
}