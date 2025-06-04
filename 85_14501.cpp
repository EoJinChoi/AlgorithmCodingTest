// 2025.6.4

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> P(N + 1);
    vector<int> T(N + 1);
    vector<int> D(N + 1);

    for (int i = 1; i <= N; i++)
        cin >> T[i] >> P[i];

    for (int i = 1; i <= N; i++)
    {
        if (i + T[i] - 1 <= N)
        {
            if (T[i] == 1)
            {
                D[i] = max(D[i], D[i - 1] + P[i]);
            }
            else
            {
                D[i] = max(D[i - 1], D[i]);
                D[i + T[i] - 1] = max(D[i + T[i] - 1], D[i - 1] + P[i]);
            }
        }
        else
            D[i] = max(D[i - 1], D[i]);
    }

    cout << D[N] << "\n";

    return 0;
}