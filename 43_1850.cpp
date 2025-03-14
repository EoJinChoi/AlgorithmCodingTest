// 2025.3.14

#include <iostream>
using namespace std;

int gcd(long a, long b);

int main()
{
    long a, b;
    cin >> a >> b;

    int len = gcd(a, b);

    for (int i = 0; i < len; i++)
        cout << 1;
    cout << "\n";

    return 0;
}

int gcd(long a, long b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}