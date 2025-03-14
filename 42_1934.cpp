// 2025.3.14

#include <iostream>
using namespace std;

int gcd(int a, int b);

int main()
{
    int T;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        int a, b;
        cin >> a >> b;

        int lcm = a * b / gcd(a, b);

        cout << lcm << "\n";
    }

    return 0;
}

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}