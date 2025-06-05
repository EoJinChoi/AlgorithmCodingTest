// 2025.6.5

#include <iostream>
using namespace std;

int D[1001];

int main()
{
    int mod = 10007;
    int N;

    cin >> N;

    D[1] = 1;
    D[2] = 2;

    for (int i = 3; i <= N; i++)
        D[i] = (D[i - 1] + D[i - 2]) % mod;

    cout << D[N] << "\n";

    return 0;
}