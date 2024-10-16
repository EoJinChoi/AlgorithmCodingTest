// 2024.10.16

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int lesson_num, bluray_num;
    cin >> lesson_num >> bluray_num;

    vector<int> v(lesson_num);
    int start = 0;
    int end = 0;

    for (int i = 0; i < lesson_num; i++)
    {
        cin >> v[i];
        if (start < v[i])
            start = v[i];

        end += v[i];
    }

    while (start <= end)
    {
        int mid = (start + end) / 2;
        int sum = 0;
        int cnt = 0;

        for (int i = 0; i < lesson_num; i++)
        {
            if (sum + v[i] > mid)
            {
                cnt++;
                sum = 0;
            }
            sum += v[i];
        }

        if (sum != 0)
            cnt++;
        if (cnt > bluray_num)
            start = mid + 1;
        else
            end = mid - 1;
    }

    cout << start << "\n";

    return 0;
}