// 2025.4.16

#include <iostream>
using namespace std;

int main()
{
    int M, K;
    int C[51];
    int total = 0;

    cin >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> C[i];
        total += C[i];
    }
    cin >> K;

    double res = 0;
    for (int i = 0; i < M; i++)
    {
        double p = 1.0;
        if (C[i] >= K)
        {
            for (int j = 0; j < K; j++)
            {
                p *= (double)(C[i] - j) / (total - j);
            }
            res += p;
        }
    }

    cout << fixed;
    cout.precision(9);
    cout << res << "\n";

    return 0;
}