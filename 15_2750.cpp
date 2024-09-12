// 2024.9.12

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> nums(N, 0);

    for (int i = 0; i < N; i++)
        cin >> nums[i];

    // 버블 정렬
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < N - 1 - i; j++)
        {
            if (nums[j] > nums[j + 1])
            {
                int tmp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = tmp;
            }
        }
    }

    for (int i = 0; i < N; i++)
        cout << nums[i] << "\n";

    return 0;
}