// 2024.7.31

#include <iostream>
using namespace std;

int main()
{
    int N;
    // N 입력
    cin >> N;

    int cnt = 1;
    int start_idx = 1;
    int end_idx = 1;
    int sum = 1;

    // end_idx가 N이 될 때까지 반복
    while (end_idx != N)
    {
        if (sum == N)
        {
            cnt++;
            end_idx++;
            sum += end_idx;
        }
        else if (sum > N)
        {
            sum -= start_idx;
            start_idx++;
        }
        else
        {
            end_idx++;
            sum += end_idx;
        }
    }

    cout << cnt << "\n";

    return 0;
}