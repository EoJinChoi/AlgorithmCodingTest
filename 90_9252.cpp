// 2025.6.12

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int DP[1001][1001];
string A, B;
vector<char> res;
void getText(int r, int c);

int main()
{
    cin >> A >> B;

    for (int i = 1; i <= A.size(); i++)
    {
        for (int j = 1; j <= B.size(); j++)
        {
            if (A[i - 1] == B[j - 1])
                DP[i][j] = DP[i - 1][j - 1] + 1;
            else
                DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
        }
    }

    cout << DP[A.size()][B.size()] << "\n";
    getText(A.size(), B.size());

    for (int i = res.size() - 1; i >= 0; i--)
        cout << res[i];
    cout << "\n";

    return 0;
}

void getText(int r, int c)
{
    if (r == 0 || c == 0)
        return;

    if (A[r - 1] == B[c - 1])
    {
        res.push_back(A[r - 1]);
        getText(r - 1, c - 1);
    }
    else
    {
        if (DP[r - 1][c] > DP[r][c - 1])
            getText(r - 1, c);
        else
            getText(r, c - 1);
    }
}