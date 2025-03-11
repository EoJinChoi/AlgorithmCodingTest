// 2025.3.11

#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

bool isPalindrome(int num);

int main()
{
    int N;
    cin >> N;

    vector<int> v(10000001);
    for (int i = 2; i < 10000001; i++)
        v[i] = i;

    for (int i = 2; i < sqrt(10000001); i++)
    {
        if (v[i] == 0)
            continue;

        for (int j = i + i; j < 10000001; j += i)
            v[j] = 0;
    }

    int i = N;
    while (true)
    {
        if (v[i] != 0)
        {
            int res = v[i];
            if (isPalindrome(res))
            {
                cout << res << "\n";
                break;
            }
        }
        i++;
    }

    return 0;
}

bool isPalindrome(int num)
{
    string str = to_string(num);
    int start = 0;
    int end = str.size() - 1;

    while (start < end)
    {
        if (str[start] != str[end])
            return false;

        start++;
        end--;
    }
    return true;
}