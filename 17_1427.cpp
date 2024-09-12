// 2024.9.12

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    string str;
    cin >> str;
    vector<int> nums(str.size(), 0);

    for (int i = 0; i < str.size(); i++)
        nums[i] = stoi(str.substr(i, 1));

    for (int i = 0; i < str.length(); i++)
    {
        int max = i;
        for (int j = i + 1; j < str.length(); j++)
        {
            if (nums[j] > nums[max])
                max = j;
        }

        int tmp = nums[i];
        nums[i] = nums[max];
        nums[max] = tmp;
    }

    for (int i = 0; i < nums.size(); i++)
        cout << nums[i];
    cout << "\n";

    return 0;
}