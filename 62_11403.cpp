// 2025.4.1

#include <iostream>
using namespace std;

int main()
{
    int N;
    int mdist[101][101];
    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> mdist[i][j];
        }
    }

    for (int k = 1; k <= N; k++)
    {
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                if (mdist[i][k] == 1 && mdist[k][j] == 1)
                    mdist[i][j] = 1;
            }
        }
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
            cout << mdist[i][j] << " ";

        cout << "\n";
    }

    return 0;
}