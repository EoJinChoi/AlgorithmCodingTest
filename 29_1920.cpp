// 2024.10.16

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N;

    vector<int> v(N);
    for (int i = 0; i < N; i++)
        cin >> v[i];

    sort(v.begin(), v.end());
    cin >> M;

    for (int i = 0; i < M; i++)
    {
        int num;
        cin >> num;

        int start = 0;
        int end = v.size() - 1;
        bool exist = false;

        while (start <= end)
        {
            int mid = (start + end) / 2;

            if (v[mid] > num)
                end = mid - 1;
            else if (v[mid] < num)
                start = mid + 1;
            else
            {
                exist = true;
                break;
            }
        }

        if (exist)
            cout << 1 << "\n";
        else
            cout << 0 << "\n";
    }

    return 0;
}