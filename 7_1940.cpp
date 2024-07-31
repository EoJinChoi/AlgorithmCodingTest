// 2024.7.31

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N, M;
    // 재료 개수 N 입력
    cin >> N;
    // 갑옷이 되는 수 M 입력
    cin >> M;

    vector<int> num(N, 0);
    // 재료 고유 번호 입력
    for (int i = 0; i < N; i++)
        cin >> num[i];

    // 고유 번호 정렬
    sort(num.begin(), num.end());

    int cnt = 0;
    int start = 0;
    int end = N - 1;
    // 갑옷이 되는 경우 찾기
    while (start < end)
    {
        if (num[start] + num[end] == M)
        {
            cnt++;
            start++;
            end--;
        }
        else if (num[start] + num[end] > M)
            end--;
        else
            start++;
    }

    cout << cnt << "\n";

    return 0;
}