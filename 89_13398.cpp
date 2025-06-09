// 2025.6.9

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> num(N);
    vector<int> L(N);
    vector<int> R(N);

    for (int i = 0; i < N; i++)
        cin >> num[i];

    L[0] = num[0];
    R[N - 1] = num[N - 1];
    int res = L[0];
    for (int i = 0; i < N; i++)
    {
        L[i] = max(num[i], L[i - 1] + num[i]);
        res = max(res, L[i]);
    }

    for (int i = N - 2; i >= 0; i--)
        R[i] = max(num[i], R[i + 1] + num[i]);

    for (int i = 1; i < N - 1; i++)
    {
        int temp = L[i - 1] + R[i + 1];
        res = max(res, temp);
    }

    cout << res << "\n";

    return 0;
}