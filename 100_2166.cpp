
// 2025.7.8
#include <iostream>
using namespace std;

int main()
{
    int N;
    long x[10001], y[10001];

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> x[i];
        cin >> y[i];
    }

    x[N] = x[0];
    y[N] = y[0];

    double result = 0;

    for (int i = 0; i < N; i++)
        result += ((x[i] * y[i + 1]) - (x[i + 1] * y[i]));

    cout << fixed;
    cout.precision(1);
    cout << abs(result) / 2.0 << "\n";

    return 0;
}