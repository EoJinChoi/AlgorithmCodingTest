// 2024.9.20

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> time(N, 0);
    vector<int> sum_time(N, 0);

    for (int i = 0; i < N; i++)
        cin >> time[i];

    // insertion sort (삽입 정렬)
    for (int i = 1; i < N; i++)
    {
        int insert_idx = i;
        int cur_value = time[i];
        for (int j = i - 1; j >= 0; j--)
        {
            if (time[j] <= time[i])
            {
                insert_idx = j + 1;
                break;
            }
            if (j == 0)
                insert_idx = 0;
        }
        for (int j = i; j > insert_idx; j--)
            time[j] = time[j - 1];

        time[insert_idx] = cur_value;
    }

    // 합 배열 만들기
    sum_time[0] = time[0];
    for (int i = 1; i < N; i++)
        sum_time[i] = sum_time[i - 1] + time[i];

    // 시간 총 합 구하기
    int sum = 0;
    for (int i = 0; i < N; i++)
        sum += sum_time[i];

    cout << sum << "\n";

    return 0;
}