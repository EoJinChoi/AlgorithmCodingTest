// 2025.3.13

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    long N;
    cin >> N;
    long res = N;

    for (long i = 2; i <= sqrt(N); i++)
    {
        if (N % i == 0)
        {
            res -= (res / i);

            while (N % i == 0)
                N /= i;
        }
    }

    if (N > 1)
        res -= (res / N);

    cout << res << "\n";

    return 0;
}