// 2024.8.2

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    // 수의 개수, 수 입력
    int N;
    cin >> N;

    vector<int> num(N, 0);
    for (int i = 0; i < N; i++)
        cin >> num[i];

    // 수 정렬
    sort(num.begin(), num.end());

    int cnt = 0;
    // 좋은 수 찾기
    for (int i = 0; i < N; i++)
    {
        int find = num[i];
        int start = 0;
        int end = N - 1;

        while (start < end)
        {
            if (num[start] + num[end] == find)
            {
                if (start != i && end != i)
                {
                    cnt++;
                    break;
                }
                else if (start == i)
                    start++;
                else if (end == i)
                    end--;
            }
            else if (num[start] + num[end] < find)
                start++;
            else
                end--;
        }
    }

    cout << cnt << "\n";

    return 0;
}