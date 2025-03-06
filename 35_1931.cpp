// 2025.03.06

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<pair<int, int>> time(N);

    for (int i = 0; i < N; i++)
        cin >> time[i].second >> time[i].first;

    // sort end time in ASC
    sort(time.begin(), time.end());

    int cnt = 0;
    int end = 0;

    for (int i = 0; i < N; i++)
    {
        if (time[i].second >= end)
        {
            cnt++;
            end = time[i].first;
        }
    }

    cout << cnt << "\n";

    return 0;
}