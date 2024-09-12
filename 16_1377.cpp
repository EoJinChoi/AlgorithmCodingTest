// 2024.9.12

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<pair<int, int>> nums(N);

    // 데이터와 정렬 전 index 저장
    for (int i = 0; i < N; i++)
    {
        cin >> nums[i].first;
        nums[i].second = i;
    }

    // 데이터 정렬
    sort(nums.begin(), nums.end());

    int max = 0;
    // 정렬 전과 후의 index 차이 중 최댓값 구하기
    for (int i = 0; i < N; i++)
    {
        if (nums[i].second - i > max)
            max = nums[i].second - i;
    }

    cout << max + 1 << "\n";

    return 0;
}