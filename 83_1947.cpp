// 2025.6.2

#include <iostream>
using namespace std;

long D[1000001];

int main()
{
    int mod = 1000000000;
    int N;

    cin >> N;

    D[1] = 0;
    D[2] = 1;

    for (int i = 3; i <= N; i++)
        D[i] = (i - 1) * (D[i - 2] + D[i - 1]) % mod;

    cout << D[N] << "\n";

    return 0;
}