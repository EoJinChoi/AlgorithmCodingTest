// 2024.9.27

#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int cnt[10001] = {0};

    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        cnt[num]++;
    }

    for (int i = 1; i <= 10000; i++)
    {
        if (cnt[i] > 0)
        {
            for (int j = 0; j < cnt[i]; j++)
                cout << i << "\n";
        }
    }

    return 0;
}