// 2024.03.19

#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b);
vector<int> Execute(int a, int b);

int main()
{
    int a, b, c;
    cin >> a >> b >> c;

    int tgcd = gcd(a, b);

    if (c % tgcd != 0)
    {
        cout << -1 << "\n";
    }
    else
    {
        int mok = (int)(c / tgcd);
        vector<int> res = Execute(a, b);

        cout << res[0] * mok << " " << res[1] * mok << "\n";
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

vector<int> Execute(int a, int b)
{
    vector<int> res(2);

    if (b == 0)
    {
        res[0] = 1;
        res[1] = 0;
        return res;
    }

    int q = a / b;
    vector<int> v = Execute(b, a % b);
    res[0] = v[1];
    res[1] = v[0] - v[1] * q;

    return res;
}